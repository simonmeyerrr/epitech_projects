#ifndef CPP_RTYPE_2019_ACLIENTLAUNCHER_HPP
#define CPP_RTYPE_2019_ACLIENTLAUNCHER_HPP

#include "IClientLauncher.hpp"

class AClientLauncher : public IClientLauncher {
public:
    ~AClientLauncher() override = default;
    explicit AClientLauncher()
    : _connected(false), _connecting(false), _myId(-1), _inRoom(false), _master(false), _inGame(false),
    _rooms(), _port(0) {}

    virtual bool isConnected() const override {return _connected;}
    virtual bool isConnecting() const override {return _connecting;}
    virtual int getMyId() const override {return _myId;}
    virtual bool isInRoom() const override {return _inRoom;}
    virtual bool isMaster() const override {return _master;}
    virtual bool isInGame() const override {return _inGame;}
    virtual ProtocolTCP::Rooms getRooms() const override {return _rooms;}
    virtual my_socket::Port getPort() const override {return _port;}
    virtual bool hasErrorFetch() const override {return _fetchError;}

protected:
    std::atomic<bool> _connected;
    bool _connecting;
    int _myId;
    bool _inRoom;
    bool _master;
    bool _inGame;
    ProtocolTCP::Rooms _rooms;
    my_socket::Port _port;
    std::atomic<bool> _fetchError;
};

#endif //CPP_RTYPE_2019_ACLIENTLAUNCHER_HPP
