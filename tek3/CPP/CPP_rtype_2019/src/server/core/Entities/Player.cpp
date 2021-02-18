//
// Created by arnaud on 25/11/2019.
//

#include "Player.hpp"

Player::Player(int nb, bool connected)
    : _nb(nb), _pos{0, 0}, _size{100, 50}, _connected(connected), _alive(true), _movement{false, false, false, false}
{
    _pos._x = 200;
    _pos._y = (900 / 5) * (1 + nb);
}

Player::~Player()
{

}

void Player::setMovement(const ProtocolUDP::ActionMovePlayer &move)
{
    _movement = move;
}

void Player::setPos(Vector2s pos)
{
    _pos = pos;
}

Vector2s Player::getPos() const
{
    return _pos;
}

bool Player::getConnected()
{
    return _connected;
}

bool Player::getAlive()
{
    return _alive;
}

void Player::update()
{
    if (!_connected)
        return;
    int intensity = 5;
    int max_x = 1600 - _size._x;
    int max_y = 900 - _size._y;
    _pos._x = _pos._x - (_movement.left ? intensity : 0) + (_movement.right ? intensity : 0);
    _pos._y = _pos._y - (_movement.up ? intensity : 0) + (_movement.down ? intensity : 0);
    if (_pos._x < 0)
        _pos._x = 0;
    else if (_pos._x > max_x)
        _pos._x = max_x;
    if (_pos._y < 0)
        _pos._y = 0;
    else if (_pos._y > max_y)
        _pos._y = max_y;
}