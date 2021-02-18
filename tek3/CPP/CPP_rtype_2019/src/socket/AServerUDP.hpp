#ifndef CPP_RTYPE_2019_ASERVERUDP_HPP
#define CPP_RTYPE_2019_ASERVERUDP_HPP

#include <atomic>
#include "IServer.hpp"

namespace my_socket {

    class IBackEndUDP {
    public:
        virtual ~IBackEndUDP() = default;

        virtual void communicate(ISocketPtr socket) = 0;
    };

    using IBackEndUDPPtr = std::unique_ptr<IBackEndUDP>;

    class AServerUDP : public IServer {
    public:
        ~AServerUDP() override {stopServer();}
        explicit AServerUDP(Port port, IBackEndUDP &backend)
            : _port(port), _backend(backend), _error(false), _working(false) {}

        Port getPort() const override {return _port;}
        bool hasError() const override {return _error;}
        bool isWorking() const override {return _working;}
        void stopServer() override {_working = false;}

    protected:
        Port _port;
        IBackEndUDP &_backend;
        std::atomic<bool> _error;
        std::atomic<bool> _working;
    };

}

#endif //CPP_RTYPE_2019_ASERVERUDP_HPP
