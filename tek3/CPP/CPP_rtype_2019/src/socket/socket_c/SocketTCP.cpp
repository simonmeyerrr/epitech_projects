#include <cstring>
#include "SocketTCP.hpp"
#include "../SocketError.hpp"

#define DEFAULT_BLOCKING true

static void c_closesocket(SOCKET __fd) {
    closesocket(__fd);
}

static int c_connect(SOCKET __fd, const struct sockaddr *__addr, unsigned int __len) {
    return connect(__fd, __addr, __len);
}

static int c_bind(SOCKET __fd, const struct sockaddr *__addr, unsigned int __len) {
    return bind(__fd, __addr, __len);
}

static int c_listen(SOCKET __fd, int __n) {
    return listen(__fd, __n);
}

#ifdef WIN32
static SOCKET c_accept(SOCKET __fd, struct sockaddr *__addr, int *__addr_len) {
    return accept(__fd, __addr, __addr_len);
}
#else
static SOCKET c_accept(SOCKET __fd, struct sockaddr *__addr, unsigned int *__addr_len) {
	return accept(__fd, __addr, __addr_len);
}
#endif

#ifdef WIN32
static int c_send(SOCKET __fd, const char *__buf, int __n, int __flags) {
    return send(__fd, __buf, __n, __flags);
}
#else
static ssize_t c_send(SOCKET __fd, const void *__buf, size_t __n, int __flags) {
	return send(__fd, __buf, __n, __flags);
}
#endif

#ifdef WIN32
static int c_recv(SOCKET __fd, char *__buf, int __n, int __flags) {
	return recv(__fd, __buf, __n, __flags);
}
#else
static ssize_t c_recv(SOCKET __fd, void *__buf, size_t __n, int __flags) {
	return recv(__fd, __buf, __n, __flags);
}
#endif

my_socket::SocketTCP::~SocketTCP()
{
    close();
}

my_socket::SocketTCP::SocketTCP(SOCKET fd, IpV4 target)
    : ASocket(DEFAULT_BLOCKING, DEFAULT_IP), _fd(fd)
{
    if (_fd == -1)
        throw SocketError(SocketError::BAD_ARGUMENT);
    _target = target;
    _working = true;
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

my_socket::SocketTCP::SocketTCP()
    : ASocket(DEFAULT_BLOCKING, DEFAULT_IP), _fd(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))
{
    if (_fd == -1)
        throw SocketError(SocketError::BAD_ARGUMENT);
    _working = true;
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

void my_socket::SocketTCP::close()
{
    ASocket::close();
    if (_fd != -1) {
        c_closesocket(_fd);
        _fd = -1;
    }
}

void my_socket::SocketTCP::setBlocking(bool blocking)
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

void my_socket::SocketTCP::connect(my_socket::IpV4 ip, my_socket::Port port)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    struct sockaddr_in addr;
    std::memset(&addr, '\0', sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = ip;

    if (c_connect(_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) == -1)
        throw SocketError(SocketError::TARGET_DISCONNECTED);
    _target = ip;
}

void my_socket::SocketTCP::bind(my_socket::Port port)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    struct sockaddr_in addr = {0, 0, {0}, {0}};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (c_bind(_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        throw SocketError(SocketError::PORT_ALREADY_USED);
}

void my_socket::SocketTCP::listen(unsigned int max_queue)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    if (c_listen(_fd, max_queue) == -1)
        throw SocketError(SocketError::BAD_ARGUMENT);
}

my_socket::ISocketPtr my_socket::SocketTCP::accept()
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    struct sockaddr_in client;
#ifdef WIN32
	int size = sizeof(client);
#else
	unsigned int size = sizeof(client);
#endif
	SOCKET new_fd = c_accept(_fd, (struct sockaddr *)&client, &size);

    if (new_fd == -1)
        throw SocketError(SocketError::NOTHING_TO_READ);
    return ISocketPtr(new SocketTCP(new_fd, client.sin_addr.s_addr));
}

my_socket::Buffer my_socket::SocketTCP::recv(size_t size)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    Buffer data(size, '\0');
    auto ret = c_recv(_fd, data.data(), size, 0);

    if (ret <= 0) {
        close();
        throw SocketError(SocketError::TARGET_DISCONNECTED);
    } else if (std::size_t(ret) != data.size()) {
        data.resize(ret);
    }
    return data;
}

void my_socket::SocketTCP::send(const my_socket::Buffer &data)
{
    if (!_working)
        throw SocketError(SocketError::IS_CLOSED);

    auto ret = c_send(_fd, data.data(), data.size(), 0);

    if (std::size_t(ret) != data.size()) {
        close();
        throw SocketError(SocketError::TARGET_DISCONNECTED);
    }
}