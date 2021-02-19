#ifndef CPP_ZIA_2019_SECURESOCKET_HPP
#define CPP_ZIA_2019_SECURESOCKET_HPP


#include "SocketTCP.hpp"
#include <openssl/ssl.h>
#include <openssl/err.h>

class SecureSocket : public SocketTCP {
public:
    ~SecureSocket() override = default;
    SecureSocket(SOCKET fd, api::IpV4 target, SSL *ssl);

    void closeSocket() override;
    api::Buffer recvPacket() override;
    api::Buffer recvPacket(unsigned int size) override;
    void sendPacket(const api::Buffer &data) override;

    bool acceptSsl();

private:
    SSL *_ssl;
};


#endif /* CPP_ZIA_2019_SECURESOCKET_HPP */
