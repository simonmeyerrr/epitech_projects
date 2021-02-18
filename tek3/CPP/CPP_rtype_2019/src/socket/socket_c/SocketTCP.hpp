#ifndef CPP_RTYPE_2019_SOCKETTCP_HPP
#define CPP_RTYPE_2019_SOCKETTCP_HPP

#include "Includes.hpp"
#include "../ASocket.hpp"

namespace my_socket {

class SocketTCP : public ASocket {
    public:
        ~SocketTCP() final;
        SocketTCP(SOCKET fd, IpV4 target);
        SocketTCP();

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
    };

    using SocketTCPPtr = std::unique_ptr<SocketTCP>;

}


#endif /*CPP_RTYPE_2019_SOCKETTCP_HPP*/
