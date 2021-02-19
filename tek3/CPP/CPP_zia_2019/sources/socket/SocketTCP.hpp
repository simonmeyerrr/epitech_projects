#ifndef CPP_ZIA_2019_SOCKETTCP_HPP
#define CPP_ZIA_2019_SOCKETTCP_HPP

#include <Types.hpp>
#include <http/ISocket.hpp>
#include "Includes.hpp"

class SocketTCP : public api::http::ISocket {
public:
    virtual ~SocketTCP() override = default;
    SocketTCP();
    SocketTCP(SOCKET fd, api::IpV4 target);
    SocketTCP(const SocketTCP &) = delete;
    SocketTCP &operator=(const SocketTCP &) = delete;

    api::IpV4 getTargetIp() const override;

    bool isOpen() const override;
    void closeSocket() override;
    void closeSocketWithoutSd();

    api::Buffer recvPacket() override;
    api::Buffer recvPacket(unsigned int size) override;
    void sendPacket(const api::Buffer &data) override;

    SOCKET getFd();
    bool createSocket();
    bool connectSocket(api::IpV4 ip, api::Port port);
    bool bindSocket(api::Port port);
    bool listenSocket(int max_queue);
    std::pair<SOCKET, api::IpV4> acceptSocket();
    void setBlocking(bool blocking);

protected:
    SOCKET _fd;
    api::IpV4 _target;
};


#endif /* CPP_ZIA_2019_SOCKETTCP_HPP */
