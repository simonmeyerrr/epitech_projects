//
// Created by arnaud on 27/11/2019.
//

#include <cmath>
#include "FastMonster.hpp"

extern "C"
{
IEntity *init(int posY)
{
    return new FastMonster(posY);
}
}

FastMonster::FastMonster(int ypos)
    : AEntity({1600, static_cast<short>(ypos)}, {195, 100}, ProtocolUDP::MONSTER2)
{
}

void FastMonster::update()
{
    _pos._x -= 8;
    _pos._y -= 100 * sin(_pos._x / 150) / 9;
}
