#include <cstring>
#include "SocketUDP.hpp"
#include "../SocketError.hpp"
#include "../Utils.hpp"

#define DEFAULT_BLOCKING true

static void c_closesocket(SOCKET __fd) {
	closesocket(__fd);
}

static int c_bind(SOCKET __fd, const struct sockaddr *__addr, unsigned int __len) {
	return bind(__fd, __addr, __len);
}

#ifdef WIN32
static int c_sendto(SOCKET __fd, const char *__buf, int __n, int __flags, const struct sockaddr *__addr, socklen_t __addr_len) {
	return sendto(__fd, __buf, __n, __flags, __addr, __addr_len);
}
#else
static ssize_t c_sendto(SOCKET __fd, const void *__buf, size_t __n, int __flags, const struct sockaddr *__addr, socklen_t __addr_len) {
	return sendto(__fd, __buf, __n, __flags, __addr, __addr_len);
}
#endif

#ifdef WIN32
static int c_recvfrom(SOCKET __fd, char *__buf, int __n, int __flags, struct sockaddr *__addr, socklen_t *__addr_len) {
	return recvfrom(__fd, __buf, __n, __flags, __addr, __addr_len);
}
#else
static ssize_t c_recvfrom(SOCKET __fd, void *__buf, size_t __n, int __flags, struct sockaddr *__addr, socklen_t *__addr_len) {
	return recvfrom(__fd, __buf, __n, __flags, __addr, __addr_len);
}
#endif

my_socket::SocketUDP::~SocketUDP()
{
    if (_ownFd)
        close();
}

my_socket::SocketUDP::SocketUDP(SOCKET fd)
        : ASocket(DEFAULT_BLOCKING, DEFAULT_IP), _fd(fd), _ownFd(false), _addr(), _targetPort(-1)
{
    if (_fd == -1)
        throw SocketError(SocketError::BAD_ARGUMENT);
    _working = true;
    std::memset(&_addr, 0, sizeof(struct sockaddr_in));
    try {
        //setBlocking(_blocking);
    } catch (const SocketError &e) {
        close();
        throw e;
    } catch (...) {
        close();
        throw SocketError(SocketError::UNKNOWN);
    }
}

my_socket::SocketUDP::SocketUDP()
        : ASocket(false, DEFAULT_IP), _fd(socket(AF_INET, SOCK_DGRAM, 0)), _ownFd(true), _addr(), _targetPort(-1)
{
    if (_fd == -1)
        throw SocketError(SocketError::BAD_ARGUMENT);
    _working = true;
    std::memset(&_addr, 0, sizeof(struct sockaddr_in));
    try {
        setBlocking(_blocking);
    } catch (const SocketError &e) {
        close();
        throw e;
    } catch (...) {
        close();
        throw SocketError(SocketError::UNKNOWN);
    }
}

void my_socket::SocketUDP::setBlocking(bool blocking)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

#ifdef WIN32

    u_long iMode = blocking ? 0 : 1; // 0: blocking, else: non-blocking
    if (ioctlsocket(_fd, FIONBIO, &iMode) == -1)
        throw SocketError(SocketError::UNKNOWN);

#else /* not WIN32 */

    int flags = fcntl(_fd, F_GETFL);
    if (flags == -1)
        throw SocketError(SocketError::UNKNOWN);
    if (fcntl(_fd, F_SETFL, blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK)) == -1)
        throw SocketError(SocketError::UNKNOWN);

#endif /* WIN32 */
    _blocking = blocking;
}

void my_socket::SocketUDP::close()
{
    ASocket::close();
    if (_fd != -1) {
        c_closesocket(_fd);
        _fd = -1;
    }
}

void my_socket::SocketUDP::bind(my_socket::Port port)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    struct sockaddr_in addr;
    std::memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (c_bind(_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        throw SocketError(SocketError::PORT_ALREADY_USED);
}

my_socket::ISocketPtr my_socket::SocketUDP::accept()
{
    throw SocketError(SocketError::BAD_ARGUMENT);
}

void my_socket::SocketUDP::listen(unsigned int max_queue)
{
    throw SocketError(SocketError::BAD_ARGUMENT);
}

void my_socket::SocketUDP::connect(my_socket::IpV4 ip, my_socket::Port port)
{
    _target = ip;
    _targetPort = port;
    struct timeval read_timeout;
    read_timeout.tv_sec = 0;
    read_timeout.tv_usec = 1000;
#ifdef WIN32
	setsockopt(_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)(&read_timeout), sizeof(read_timeout));
#else
    setsockopt(_fd, SOL_SOCKET, SO_RCVTIMEO, &read_timeout, sizeof(read_timeout));
#endif
}

my_socket::Buffer my_socket::SocketUDP::recv(size_t size)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    Buffer data(size, '\0');
    socklen_t len;
    auto ret = c_recvfrom(_fd, data.data(), size, 0, (struct sockaddr *)&_addr, &len);

    if (ret <= 0) {
        throw SocketError(SocketError::NOTHING_TO_READ);
    } else if (std::size_t(ret) != data.size()) {
        data.resize(ret);
    }
    return data;
}

void my_socket::SocketUDP::send(const my_socket::Buffer &data)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    int ret;
    struct sockaddr_in     servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(_targetPort);
    servaddr.sin_addr.s_addr = _target;
    if (_ownFd) {
        ret = c_sendto(_fd, data.data(), data.size(), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    } else {
        ret = c_sendto(_fd, data.data(), data.size(), 0, (const struct sockaddr *)&_addr, sizeof(_addr));
    }
    if (std::size_t(ret) != data.size()) {
        close();
        throw SocketError(SocketError::TARGET_DISCONNECTED);
    }
}
