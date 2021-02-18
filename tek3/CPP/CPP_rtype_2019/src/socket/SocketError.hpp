#ifndef CPP_RTYPE_2019_SOCKETERROR_HPP
#define CPP_RTYPE_2019_SOCKETERROR_HPP

#include <iostream>
#include <exception>

namespace my_socket {

    class SocketError : public std::exception {
    public:
        enum Type {
            UNKNOWN = -1,
            IS_CLOSED = 0,
            PORT_ALREADY_USED = 1,
            TARGET_DISCONNECTED = 2,
            NOTHING_TO_READ = 3,
            BAD_ARGUMENT = 4,
            TIME_OUT = 5
        };

        ~SocketError() override = default;

        explicit SocketError(Type type = UNKNOWN) : _type(type)
        {
#ifdef DEBUG
            if (type != NOTHING_TO_READ)
                dump();
#endif
        }

        const char *what() const noexcept override
        {
            switch (_type) {
                case IS_CLOSED: return "socket is closed";
                case PORT_ALREADY_USED: return "this port is already used";
                case TARGET_DISCONNECTED: return "target is now disconnected";
                case NOTHING_TO_READ: return "nothing to read";
                case BAD_ARGUMENT: return "invalid argument";
                case TIME_OUT: return "request timed out";
                default: return "Unknown error";
            }
        }

        Type getType() const { return _type; }

        void dump() const noexcept
        {
            std::cerr << "Socket Error " << _type << " : " << what() << std::endl;
        }

    protected:
        Type _type;
    };

}

#endif /* CPP_RTYPE_2019_SOCKETERROR_HPP */
