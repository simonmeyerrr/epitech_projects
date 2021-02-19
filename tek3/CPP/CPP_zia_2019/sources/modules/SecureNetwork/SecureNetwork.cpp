#include <iostream>
#include "SecureNetwork.hpp"
#include "../../socket/MyRequest.hpp"
#include "../../socket/MyResponse.hpp"
#include "../../socket/SecureSocket.hpp"

MODULE_EXPORTER(SecureNetwork)

SecureNetwork::~SecureNetwork()
{
    EVP_cleanup();
#ifdef WIN32
    WSACleanup();
#endif

}

SecureNetwork::SecureNetwork()
        : _running(false), _thread(nullptr), _modules(), _logger(nullptr)
{
#ifdef WIN32
    WSACleanup();
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
#endif
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX *create_context(api::JsonString w_cert, api::JsonString w_key)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_server_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        return nullptr;
    }
    SSL_CTX_set_ecdh_auto(ctx, 1);

    /* Set the key and cert */
    if (SSL_CTX_use_certificate_file(ctx, std::string(w_cert.begin(), w_cert.end()).c_str(), SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        return nullptr;
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, std::string(w_key.begin(), w_key.end()).c_str(), SSL_FILETYPE_PEM) <= 0 ) {
        ERR_print_errors_fp(stderr);
        return nullptr;
    }
    if ( !SSL_CTX_check_private_key(ctx) ) {
        ERR_print_errors_fp(stderr);
        return nullptr;
    }
    return ctx;
}

bool SecureNetwork::startServing()
{
    if (_running)
        return false;

    if (_thread) {
        _thread->join();
        _thread = nullptr;
    }
    api::Port port = 8080;
    try {
        port = _config.at(L"port").as<api::JsonNumber>();
    } catch (...) {}

    std::shared_ptr<SocketTCP> sock = std::make_shared<SocketTCP>();
    if (!sock->createSocket() || !sock->bindSocket(port) || !sock->listenSocket(5)) {
        perror("Error while starting server: ");
        sock->closeSocket();
        return false;
    }
    SSL_CTX *ctx = nullptr;
    try {
        ctx = create_context(_config.at(L"ssl-certificate").as<api::JsonString>(), _config.at(L"ssl-certificate-key").as<api::JsonString>());
    } catch (...) {}
    if (!ctx) {
        std::cerr << "Error while preparing ssl" << std::endl;
        sock->closeSocket();
        return false;
    }
    _running = true;
    std::cout << "Starting https server on port " << port << std::endl;
    _thread = std::make_unique<Thread<>>(&SecureNetwork::loopServing, this, sock, ctx);
    return true;
}

void SecureNetwork::stopServing()
{
    _running = false;
    if (_thread) {
        _thread->join();
        _thread = nullptr;
    }
}

void SecureNetwork::setModules(const std::vector<api::module::AHttp *> &modules)
{
    if (modules == _modules)
        return;
    bool wasRunning = _running;
    stopServing();
    _modules = modules;
    if (wasRunning)
        startServing();
}

void SecureNetwork::setLogger(api::module::ALogger *logger)
{
    updateLogger(logger);
}

void SecureNetwork::setConfig(const api::JsonObject &config)
{
    if (config == _config)
        return;
    bool wasRunning = _running;
    stopServing();
    _config = config;
    if (wasRunning)
        startServing();
}

void SecureNetwork::loopServing(std::shared_ptr<SocketTCP> sock, SSL_CTX *ctx)
{
    fd_set read_set;
    fd_set active_set;
    struct timeval timeout = {1, 0};

    FD_ZERO(&active_set);
    FD_SET(sock->getFd(), &active_set);
    while (_running) {
        read_set = active_set;
        if (select(500, &read_set, nullptr, nullptr, &timeout) > 0 && FD_ISSET(sock->getFd(), &read_set)) {
            acceptConnection(sock->acceptSocket(), ctx);
        }
        for (auto it = _pool.begin(); it != _pool.end(); ) {
            if (!it->first->isOpen()) {
                it->second->join();
                _pool.erase(it);
                it = _pool.begin();
            } else {
                it++;
            }
        }
    }
    for (auto &t: _pool) {
        t.first->closeSocket();
    }
    for (auto &t: _pool) {
        t.second->join();
    }
    _pool.clear();
    _running = false;
    SSL_CTX_free(ctx);
    sock->closeSocketWithoutSd();
}

void SecureNetwork::acceptConnection(std::pair<SOCKET, api::IpV4> info, SSL_CTX *ctx)
{
    if (info.first == -1)
        return;

    auto ssl = SSL_new(ctx);
    SSL_set_fd(ssl, info.first);
    std::shared_ptr<SecureSocket> sock = std::make_shared<SecureSocket>(info.first, info.second, ssl);
    _pool.emplace_back(sock, std::make_unique<Thread<>>(&SecureNetwork::loopRequest, this, sock));
}

void SecureNetwork::loopRequest(std::shared_ptr<SecureSocket> sock)
{
    log("New connection accepted " + std::to_string(sock->getFd()), api::module::ALogger::LEVEL_DEBUG);
    if (!sock->acceptSsl())
        return;

    log("SSL accepted " + std::to_string(sock->getFd()), api::module::ALogger::LEVEL_DEBUG);
    api::module::AHttp::Connection conn = {new MyRequest, new MyResponse, sock.get()};

    while (!_modules.empty() && sock->isOpen()) {
        for (auto i = _modules.begin(); sock->isOpen() && i != _modules.end(); ++i) {
            if (!(*i)->handle(conn))
                break;
        }
        if (conn.req)
            conn.req->clear();
        if (conn.res)
            conn.res->clear();
    }
    delete conn.req;
    delete conn.res;
    log("Closed connection " + std::to_string(sock->getFd()), api::module::ALogger::LEVEL_DEBUG);
    sock->closeSocket();
}
