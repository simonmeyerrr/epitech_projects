#ifndef CPP_RTYPE_2019_ASERVERTCP_HPP
#define CPP_RTYPE_2019_ASERVERTCP_HPP

#include <atomic>
#include "IServer.hpp"

namespace my_socket {

    class IBackEndTCP {
    public:
        virtual ~IBackEndTCP() = default;

        virtual bool addConnection(ISocketPtr &socket) = 0;
        virtual bool communicate(ISocketPtr &socket) = 0;
        virtual void closeConnection(ISocketPtr &socket) = 0;
    };

    using IBackEndTCPPtr = std::unique_ptr<IBackEndTCP>;

    class AServerTCP : public IServer {
    public:
        ~AServerTCP() override {stopServer();}
        explicit AServerTCP(Port port, IBackEndTCP &backend)
            : _port(port), _backend(backend), _error(false), _working(false) {}

        Port getPort() const override {return _port;}
        bool hasError() const override {return _error;}
        bool isWorking() const override {return _working;}
        void stopServer() override {_working = false;}

    protected:
        Port _port;
        IBackEndTCP &_backend;
        std::atomic<bool> _error;
        std::atomic<bool> _working;
    };

}

#endif //CPP_RTYPE_2019_ASERVERTCP_HPP
