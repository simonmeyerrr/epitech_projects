#ifndef CPP_RTYPE_2019_ISERVER_HPP
#define CPP_RTYPE_2019_ISERVER_HPP

#include <memory>
#include "ISocket.hpp"

namespace my_socket {

    class IServer {
    public:
        virtual ~IServer() = default;

        virtual Port getPort() const = 0;
        virtual bool hasError() const = 0;
        virtual bool isWorking() const = 0;
        virtual bool start() = 0;
        virtual void stopServer() = 0;
    };

    using IServerPtr = std::unique_ptr<IServer>;
}

#endif /*CPP_RTYPE_2019_ISERVER_HPP*/
