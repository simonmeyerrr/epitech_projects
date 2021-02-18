//
// Created by arnaud on 25/11/2019.
//

#include "SlowMonster.hpp"

extern "C"
{
IEntity *init(int posY)
{
    return new SlowMonster(posY);
}
}

SlowMonster::SlowMonster(int ypos)
    : AEntity({1600, static_cast<short>(ypos)}, {195, 100}, ProtocolUDP::MONSTER)
{
}

void SlowMonster::update()
{
    _pos._x -= 3;
}
