#ifndef CPP_RTYPE_2019_SOCKETUDP_HPP
#define CPP_RTYPE_2019_SOCKETUDP_HPP

#include "Includes.hpp"
#include "../ASocket.hpp"

namespace my_socket {

    class SocketUDP : public ASocket {
    public:
        ~SocketUDP() override;
        SocketUDP();
        SocketUDP(SOCKET fd);

        SOCKET getFd() const {return _fd;}

        void close() final;
        void setBlocking(bool blocking) final;
        void connect(IpV4 ip, Port port) final;
        void bind(Port port) final;
        void listen(unsigned int max_queue) final;
        ISocketPtr accept() final;

        Buffer recv(size_t size) final;
        void send(const Buffer &data) final;

    private:
        SOCKET _fd;
        bool _ownFd;
        struct sockaddr_in _addr;
        my_socket::Port _targetPort;
    };

    using SocketUDPPtr = std::unique_ptr<SocketUDP>;
}


#endif //CPP_RTYPE_2019_SOCKETUDP_HPP
