#ifndef CPP_RTYPE_2019_SERVERUDP_HPP
#define CPP_RTYPE_2019_SERVERUDP_HPP

#include <mutex>
#include "../AServerUDP.hpp"
#include "SocketUDP.hpp"
#include "../SocketError.hpp"

namespace my_socket {

    class ServerUDP : public AServerUDP {
    public:
        ~ServerUDP();
        ServerUDP(Port port, IBackEndUDP &backend);

        bool start() final;

    private:
        bool initSocket();

        SocketUDPPtr _socket;
        std::mutex _mutex;
        fd_set _read_fd_set;
    };
}


#endif /* CPP_RTYPE_2019_SERVERUDP_HPP */
