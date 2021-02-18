//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP


#include "IEntity.hpp"
#include "../../../ProtocolUDP.hpp"

class Player : public IEntity {
public:
    ~Player();
    Player(int nb, bool connected);

    void kill() {_alive = false;}
    void disconnect() {_connected = false;}
    void setMovement(const ProtocolUDP::ActionMovePlayer &move);
    void setPos(Vector2s pos);

    Vector2s getPos() const override;
    bool getConnected();
    bool getAlive();
    void update() override;
    ProtocolUDP::EntityType getType() const override {return ProtocolUDP::PLAYER1;}
    Vector2s getSize() const override {return _size;}

protected:
    int _nb;
    Vector2s _pos;
    Vector2s _size;
    bool _connected;
    bool _alive;
    ProtocolUDP::ActionMovePlayer _movement;
};


#endif //CPP_RTYPE_2019_PLAYER_HPP
