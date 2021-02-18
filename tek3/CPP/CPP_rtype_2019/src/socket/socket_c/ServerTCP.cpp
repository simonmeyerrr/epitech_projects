#include "ServerTCP.hpp"

#include <memory>
#include "../SocketError.hpp"

my_socket::ServerTCP::~ServerTCP()
{
    stopServer();
    while (_working);
}

my_socket::ServerTCP::ServerTCP(IBackEndTCP &backend, Port port, int max_queue)
    : AServerTCP(port, backend), _max_queue(max_queue), _socket(nullptr),
      _mutex(), _active_fd_set(), _read_fd_set(), _sockets()
{}

bool my_socket::ServerTCP::initSocket()
{
    if (_working)
        return false;
    try {
        _socket = nullptr;
        _socket = std::make_unique<SocketTCP>();
        _socket->bind(_port);
        _socket->listen(_max_queue);
    } catch (const SocketError &e) {
        _socket = nullptr;
        _error = true;
        _mutex.unlock();
        return false;
    } catch (...) {
        _socket = nullptr;
        _error = true;
        _mutex.unlock();
        throw SocketError(SocketError::UNKNOWN);
    }
#ifdef WIN32
    char enable = 1;
#else
	int enable = 1;
#endif
    setsockopt(_socket->getFd(), SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    _error = false;
    _working = true;
    _mutex.unlock();
    return true;
}

bool my_socket::ServerTCP::start()
{
    _mutex.lock();
    if (!initSocket())
        return false;

    FD_ZERO(&_active_fd_set);
    FD_SET(_socket->getFd(), &_active_fd_set);

    while (_working && !_error) {
        _read_fd_set = _active_fd_set;
        try {
            struct timeval timeout = {1, 0};
            if (select(500, &_read_fd_set, nullptr, nullptr, &timeout) < 0) {
                _error = true;
            } else {
                loopAccept();
            }
        } catch (...) {
            _error = true;
        }
    }
    while (!_error && !_sockets.empty()) {
        auto fd = _sockets.begin()->first;
        closeConnection(fd);
    }
    _socket = nullptr;
    _working = false;
    return true;
}

void my_socket::ServerTCP::loopAccept()
{
    for (int fd = 0; fd < 500; ++fd) {
        if (!FD_ISSET(fd, &_read_fd_set))
            continue;
        if (fd == _socket->getFd()) {
            addConnection();
        } else if (!communicate(_sockets.at(fd))) {
            closeConnection(fd);
        }
    }
}

void my_socket::ServerTCP::addConnection()
{
    struct sockaddr_in client;
    socklen_t size = sizeof(client);
    SOCKET new_fd = accept(_socket->getFd(), (struct sockaddr *)&client, &size);

    if (new_fd == -1)
        return;
    FD_SET(new_fd, &_active_fd_set);
    _sockets.insert(std::make_pair(new_fd, ISocketPtr(new SocketTCP(new_fd, client.sin_addr.s_addr))));

    if (!_backend.addConnection(_sockets.at(new_fd))) {
        closeConnection(new_fd);
    }
}

bool my_socket::ServerTCP::communicate(my_socket::ISocketPtr &socket)
{
    try {
        return _backend.communicate(socket);
    } catch (const SocketError &e) {
        return false;
    }
}

void my_socket::ServerTCP::closeConnection(SOCKET fd)
{
    _backend.closeConnection(_sockets.at(fd));
    _sockets.erase(fd);
    FD_CLR(fd, &_active_fd_set);
}
