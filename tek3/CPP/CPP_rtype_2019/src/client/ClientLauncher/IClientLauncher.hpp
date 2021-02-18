#ifndef CPP_RTYPE_2019_ICLIENTLAUNCHER_HPP
#define CPP_RTYPE_2019_ICLIENTLAUNCHER_HPP

#include <memory>
#include <string>
#include "../../socket/ISocket.hpp"
#include "../../ProtocolTCP.hpp"

class IClientLauncher {
public:
    virtual ~IClientLauncher() = default;

    virtual my_socket::IpV4 getIp() const = 0;

    virtual void connect(const std::string &username, my_socket::IpV4 ip, my_socket::Port port) = 0;
    virtual void disconnect() = 0;
    virtual void createRoom(const std::string &name) = 0;
    virtual void joinRoom(int nbRoom) = 0;
    virtual void leaveRoom() = 0;
    virtual void startGame() = 0;

    virtual bool isConnected() const = 0;
    virtual bool isConnecting() const = 0;
    virtual int getMyId() const = 0;
    virtual bool isInRoom() const = 0;
    virtual bool isMaster() const = 0;
    virtual bool isInGame() const = 0;
    virtual ProtocolTCP::Rooms getRooms() const = 0;
    virtual my_socket::Port getPort() const = 0;
    virtual bool hasErrorFetch() const = 0;
};

using IClientLauncherPtr = std::unique_ptr<IClientLauncher>;

#endif //CPP_RTYPE_2019_ICLIENTLAUNCHER_HPP
