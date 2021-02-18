#ifndef CPP_RTYPE_2019_ISOCKET_HPP
#define CPP_RTYPE_2019_ISOCKET_HPP

#include <vector>
#include <memory>

#define DEFAULT_IP 0x7F000001

namespace my_socket {

    using Buffer = std::vector<char>;
    using Port = unsigned short;
    using IpV4 = unsigned int;

    class ISocket {
    public:
        virtual ~ISocket() = default;

        virtual bool isWorking() const = 0;
        virtual bool isBlocking() const = 0;
        virtual int getId() const = 0;
        virtual IpV4 getTargetIp() const = 0;
        virtual void close() = 0;

        virtual void setBlocking(bool blocking) = 0;
        virtual void connect(IpV4 ip, Port port) = 0;
        virtual void bind(Port port) = 0;
        virtual void listen(unsigned int max_queue) = 0;
        virtual std::unique_ptr<ISocket> accept() = 0;

        virtual Buffer recv(size_t size) = 0;
        virtual void send(const Buffer &data) = 0;
    };

    using ISocketPtr = std::unique_ptr<ISocket>;
}

#endif /* CPP_RTYPE_2019_ISOCKET_HPP */
