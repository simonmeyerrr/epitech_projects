#ifndef CPP_RTYPE_2019_SERVERTCP_HPP
#define CPP_RTYPE_2019_SERVERTCP_HPP

#include <map>
#include <mutex>
#include "SocketTCP.hpp"
#include "../AServerTCP.hpp"

namespace my_socket {

    class ServerTCP : public AServerTCP {
    public:
        ~ServerTCP() override;
        explicit ServerTCP(IBackEndTCP &backend, Port port, int max_queue);

        bool start() final;

    private:
        bool initSocket();
        void loopAccept();

        void addConnection();
        bool communicate(ISocketPtr &socket);
        void closeConnection(SOCKET fd);

        int _max_queue;
        SocketTCPPtr _socket;
        std::mutex _mutex;
        fd_set _active_fd_set;
        fd_set _read_fd_set;
        std::map<SOCKET, ISocketPtr> _sockets;
    };

}

#endif /*CPP_RTYPE_2019_SERVERTCP_HPP*/
