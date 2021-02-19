#include <iostream>
#include "SecureSocket.hpp"

SecureSocket::SecureSocket(SOCKET fd, api::IpV4 target, SSL *ssl)
    : SocketTCP(fd, target), _ssl(ssl)
{
}

void SecureSocket::sendPacket(const api::Buffer &data)
{
    if (!isOpen())
        return;
    SSL_write(_ssl, data.data(), static_cast<int>(data.size()));
}

api::Buffer SecureSocket::recvPacket()
{
    if (!isOpen())
        return {};
    char buff;
    int ret;
    api::Buffer data{};

    while (true) {
        ret = SSL_read(_ssl, &buff, 1);
        if (ret <= 0) {
            closeSocket();
            break;
        }
        data.push_back(buff);
        if (data.size() >= 2 && data[data.size() - 1] == '\n')
            break;
    }
    return data;
}

api::Buffer SecureSocket::recvPacket(unsigned int size)
{
    if (!isOpen())
        return {};
    int ret;
    api::Buffer data(size, '\0');

    ret = SSL_read(_ssl, data.data(), size);
    if (ret <= 0) {
        closeSocket();
        return {};
    }
    data.resize(ret);
    return data;
}

void SecureSocket::closeSocket()
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
    if (_ssl) {
        SSL_shutdown(_ssl);
        //SSL_free(_ssl);
    }
    //_ssl = nullptr;
}

bool SecureSocket::acceptSsl()
{
    while (_ssl && isOpen()) {
        auto ret = SSL_accept(_ssl);
        if (ret == 0) {
        } else if (ret < 0) {
            if (_ssl) {
                SSL_free(_ssl);
                _ssl = nullptr;
            }
            closeSocket();
            return false;
        } else {
            break;
        }
    }
    return true;
}
