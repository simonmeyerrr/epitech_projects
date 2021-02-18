#ifndef CPP_RTYPE_2019_ASOCKET_HPP
#define CPP_RTYPE_2019_ASOCKET_HPP

#include <random>
#include "ISocket.hpp"

namespace my_socket {

    class ASocket : public ISocket {
    public:
        ~ASocket() override = default;

        explicit ASocket(bool blocking, IpV4 target)
            : _working(false), _blocking(blocking), _id(-1), _target(target) {
            _id = std::rand();
        }

        bool isWorking() const override { return _working; }
        bool isBlocking() const override { return _blocking; }
        int getId() const override { return _id; }
        IpV4 getTargetIp() const override { return _target; }
        void close() override { _working = false; }

    protected:
        bool _working;
        bool _blocking;
        int _id;
        IpV4 _target;
    };
}

#endif /* CPP_RTYPE_2019_ASOCKET_HPP */
