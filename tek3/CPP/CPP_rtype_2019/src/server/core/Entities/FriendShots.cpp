//
// Created by arnaud on 25/11/2019.
//

#include "FriendShots.hpp"

FriendShots::FriendShots(Vector2s pos)
    : AEntity(pos, Vector2s(36, 12), ProtocolUDP::ROCKET)
{

}

void FriendShots::update()
{
    _pos._x += 8;
}