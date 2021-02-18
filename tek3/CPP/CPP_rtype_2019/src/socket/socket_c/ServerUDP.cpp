#include "ServerUDP.hpp"

my_socket::ServerUDP::~ServerUDP()
{
    stopServer();
    while (_working);
}

my_socket::ServerUDP::ServerUDP(Port port, IBackEndUDP &backend)
    : AServerUDP(port, backend), _socket(nullptr), _mutex(), _read_fd_set()
{
}

bool my_socket::ServerUDP::start()
{
    _mutex.lock();
    if (!initSocket())
        return false;

    while (_working && !_error) {
        FD_ZERO(&_read_fd_set);
        FD_SET(_socket->getFd(), &_read_fd_set);
        struct timeval timeout = {1, 0};
        int ret = select(500, &_read_fd_set, nullptr, nullptr, &timeout);
        if (ret < 0) {
            _error = true;
        } else if (ret > 0){
            try {
                _backend.communicate(std::make_unique<SocketUDP>(_socket->getFd()));
            } catch (...) {
            }
        }
    }
    _socket = nullptr;
    _working = false;
    return true;
}

bool my_socket::ServerUDP::initSocket()
{
    if (_working)
        return false;
    try {
        _socket = nullptr;
        _socket = std::make_unique<SocketUDP>();
        _socket->bind(_port);
        _socket->setBlocking(false);
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

    struct timeval read_timeout;
    read_timeout.tv_sec = 0;
    read_timeout.tv_usec = 1000;
#ifdef WIN32
	setsockopt(_socket->getFd(), SOL_SOCKET, SO_RCVTIMEO, (char *)(&read_timeout), sizeof(read_timeout));
#else
	setsockopt(_socket->getFd(), SOL_SOCKET, SO_RCVTIMEO, &read_timeout, sizeof(read_timeout));
#endif
    _error = false;
    _working = true;
    _mutex.unlock();
    return true;
}