/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ConveyorBeltRand.cpp
*/

#include <random>
#include "../XMLSerializer/XMLSerializer.hpp"
#include "../Object/Wrap/Paper.hpp"
#include "../Object/Wrap/Box.hpp"
#include "ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand() : _obj(nullptr)
{
    say("created");
}

ConveyorBeltRand::~ConveyorBeltRand()
{
    if (_obj)
        delete _obj;
}

void ConveyorBeltRand::say(const std::string &message) const
{
    std::cout << "[CONVEYOR BELT RAND] " << message << std::endl;
}

bool ConveyorBeltRand::in(Object::Types type)
{
    (void)type;
    if (random() % 2 == 0) {
        _obj = new Paper;
        say("* bip bip * paper generated");
    } else {
        say("* bip bip * box generated");
        _obj = new Box;
    }
    return (true);
}

bool ConveyorBeltRand::out()
{
    if (!_obj) {
        say("nothing to send");
        return (false);
    }
    if (_obj->getType() != Object::PAPER || _obj->isOpen()) {
        say("can't send a " + _obj->describe());
        return (false);
    }
    say("sent a " + _obj->describe());
    XMLSerializer xml(_obj);
    delete _obj;
    _obj = nullptr;
    return (true);
}

bool ConveyorBeltRand::put(Object *obj)
{
    if (!_obj) {
        _obj = obj;
        return (true);
    } else {
        return (_obj->wrapMeThat(obj));
    }
}

Object *ConveyorBeltRand::take()
{
    auto tmp = _obj;

    _obj = nullptr;
    return (tmp);
}

bool ConveyorBeltRand::isObjectOn() const
{
    return (_obj != nullptr);
}

const Object *ConveyorBeltRand::getOnConv() const
{
    return (_obj);
}
