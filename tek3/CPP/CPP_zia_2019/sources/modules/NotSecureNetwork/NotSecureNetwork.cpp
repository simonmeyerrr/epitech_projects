#include <iostream>
#include "NotSecureNetwork.hpp"
#include "../../socket/MyRequest.hpp"
#include "../../socket/MyResponse.hpp"

MODULE_EXPORTER(NotSecureNetwork)

NotSecureNetwork::~NotSecureNetwork()
{
#ifdef WIN32
    WSACleanup();
#endif

}

NotSecureNetwork::NotSecureNetwork()
        : ModuleLoggable(), _running(false), _thread(nullptr), _modules(), _logger(nullptr)
{
#ifdef WIN32
    WSACleanup();
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
#endif
}

bool NotSecureNetwork::startServing()
{
    if (_running)
        return false;

    if (_thread) {
        _thread->join();
        _thread = nullptr;
    }
    api::Port port = 8080;
    try {
        port = static_cast<api::Port>(_config.at(L"port").as<api::JsonNumber>());
    } catch (...) {}

    std::shared_ptr<SocketTCP> sock = std::make_shared<SocketTCP>();
    if (!sock->createSocket() || !sock->bindSocket(port) || !sock->listenSocket(5)) {
        perror("Error while starting server: ");
        sock->closeSocket();
        return false;
    }
    _running.store(true);
    std::cout << "Starting http server on port " << port << std::endl;
    log("Starting http server on port " + std::to_string(port));
    _thread = std::make_unique<Thread<>>(&NotSecureNetwork::loopServing, this, sock);
    return true;
}

void NotSecureNetwork::stopServing()
{
    _running.store(false);
    if (_thread) {
        _thread->join();
        _thread = nullptr;
    }
}

void NotSecureNetwork::setModules(const std::vector<api::module::AHttp *> &modules)
{
    if (modules == _modules)
        return;
    bool wasRunning = _running;
    stopServing();
    _modules = modules;
    if (wasRunning)
        startServing();
}

void NotSecureNetwork::setLogger(api::module::ALogger *logger)
{
    updateLogger(logger);
}

void NotSecureNetwork::setConfig(const api::JsonObject &config)
{
    if (config == _config)
        return;
    bool wasRunning = _running;
    stopServing();
    _config = config;
    if (wasRunning)
        startServing();
}

void NotSecureNetwork::loopServing(std::shared_ptr<SocketTCP> sock)
{
    fd_set read_set;
    fd_set active_set;
    struct timeval timeout = {1, 0};

    FD_ZERO(&active_set);
    FD_SET(sock->getFd(), &active_set);
    while (_running) {
        read_set = active_set;
        if (select(500, &read_set, nullptr, nullptr, &timeout) > 0 && FD_ISSET(sock->getFd(), &read_set)) {
            acceptConnection(sock->acceptSocket());
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
    _running.store(false);
    sock->closeSocketWithoutSd();
}

void NotSecureNetwork::acceptConnection(std::pair<SOCKET, api::IpV4> info)
{
    if (info.first == -1)
        return;

    std::shared_ptr<SocketTCP> sock = std::make_shared<SocketTCP>(info.first, info.second);
    _pool.emplace_back(sock, std::make_unique<Thread<>>(&NotSecureNetwork::loopRequest, this, sock));
}

void NotSecureNetwork::loopRequest(std::shared_ptr<api::http::ISocket> sock)
{
    log("New connection accepted", api::module::ALogger::LEVEL_DEBUG);
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
    log("Connection closed", api::module::ALogger::LEVEL_DEBUG);
    sock->closeSocket();
}
