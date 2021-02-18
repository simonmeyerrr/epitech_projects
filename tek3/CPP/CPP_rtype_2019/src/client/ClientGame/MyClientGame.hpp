#ifndef CPP_RTYPE_2019_MYCLIENTGAME_HPP
#define CPP_RTYPE_2019_MYCLIENTGAME_HPP

#include "AClientGame.hpp"
#include "../../socket/socket_c/SocketUDP.hpp"
#include "../../ProtocolUDP.hpp"

class MyClientGame : public AClientGame {
public:
    ~MyClientGame() override = default;
    MyClientGame(my_socket::IpV4 ip, my_socket::Port port, int userId);

    bool isConnected() const {return _connected;}

    void sendPing(const ProtocolUDP::ActionPing &);
    void sendMove(const ProtocolUDP::ActionMovePlayer &);
    void readPackets();

    const ProtocolUDP::InfoPlayers &getInfoPlayers() const {return _infoPlayers;}
    const ProtocolUDP::Entities &getEntities() const {return _entities;}

private:
    template <typename T>
    void sendPacket(ProtocolUDP::Action action, const T &body);
    void readPing(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer);
    void readPlayers(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer);
    void readEntities(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer);

    my_socket::IpV4 _ip;
    my_socket::Port _port;
    int _userId;
    bool _connected;

    my_socket::ISocketPtr _socket;

    ProtocolUDP::InfoPlayers _infoPlayers;
    ProtocolUDP::Entities _entities;
};


#endif /* CPP_RTYPE_2019_MYCLIENTGAME_HPP */
