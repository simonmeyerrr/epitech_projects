#include <iostream>
#include <cstring>
#include "SocketTCP.hpp"

SocketTCP::SocketTCP()
    : _fd(-1), _target(DEFAULT_IP)
{}

SocketTCP::SocketTCP(SOCKET fd, api::IpV4 target)
        : _fd(fd), _target(target)
{}

api::IpV4 SocketTCP::getTargetIp() const
{
    return _target;
}

bool SocketTCP::isOpen() const
{
    return _fd != -1;
}

void SocketTCP::closeSocket()
{
    if (_fd != -1) {
#ifdef WIN32
        shutdown(_fd, SD_BOTH);
#else
		shutdown(_fd, SHUT_RDWR);
#endif
        closesocket(_fd);
    }
    _fd = -1;
    _target = DEFAULT_IP;
}

void SocketTCP::closeSocketWithoutSd()
{
    if (_fd != -1) {
        closesocket(_fd);
    }
    _fd = -1;
    _target = DEFAULT_IP;
}

api::Buffer SocketTCP::recvPacket()
{
    char buff;
    int ret;
    api::Buffer data{};

    while (isOpen()) {
        ret = read(_fd, &buff, 1);
        if (ret <= 0) {
            closeSocket();
            break;
        }
        data.push_back(buff);
        if (data.size() >= 2 && data[data.size() - 2] == '\r' && data[data.size() - 1] == '\n')
            break;
    }
    return data;
}

api::Buffer SocketTCP::recvPacket(unsigned int size)
{
    int ret;
    api::Buffer data(size, '\0');

    ret = read(_fd, data.data(), size);
    if (ret <= 0) {
        closeSocket();
        return {};
    }
    data.resize(ret);
    return data;
}

void SocketTCP::sendPacket(const api::Buffer &data)
{
    if (!isOpen())
        return;

    auto ret = send(_fd, data.data(), static_cast<int>(data.size()), 0);

    if (std::size_t(ret) != data.size()) {
        closeSocket();
    }
}

SOCKET SocketTCP::getFd()
{
    return _fd;
}

bool SocketTCP::createSocket()
{
    closeSocket();
    _fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_fd == -1)
        return false;
#ifdef WIN32
    char enable = 1;
#else
    int enable = 1;
#endif
    setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    return true;
}

bool SocketTCP::connectSocket(api::IpV4 ip, api::Port port)
{
    if (!isOpen())
        return false;

    struct sockaddr_in addr = {};
    std::memset(&addr, '\0', sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = ip;
    _target = ip;

    return connect(_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) != -1;
}

bool SocketTCP::bindSocket(api::Port port)
{
    if (!isOpen())
        return false;

    struct sockaddr_in addr = {};
    std::memset(&addr, '\0', sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    return bind(_fd, (struct sockaddr *)&addr, sizeof(addr)) != -1;
}

bool SocketTCP::listenSocket(int max_queue)
{
    if (!isOpen())
        return false;

    return listen(_fd, max_queue) != -1;
}

std::pair<SOCKET, api::IpV4> SocketTCP::acceptSocket()
{
    if (!isOpen())
        return {-1, DEFAULT_IP};

    struct sockaddr_in client = {};
    std::memset(&client, '\0', sizeof(struct sockaddr_in));
    socklen_t size = sizeof(client);
    SOCKET new_fd = accept(_fd, (struct sockaddr *)&client, &size);

    return {new_fd, client.sin_addr.s_addr};
}

void SocketTCP::setBlocking(bool blocking)
{
    if (_fd == -1)
        return;
#ifdef WIN32

    u_long iMode = blocking ? 0 : 1; // 0: blocking, else: non-blocking
    if (ioctlsocket(_fd, FIONBIO, &iMode) == -1) {
        closeSocket();
        return;
    }

#else /* not WIN32 */

    int flags = fcntl(_fd, F_GETFL);
    if (flags == -1 || fcntl(_fd, F_SETFL, blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK)) == -1) {
        closeSocket();
        return;
    }

#endif /* WIN32 */
}
