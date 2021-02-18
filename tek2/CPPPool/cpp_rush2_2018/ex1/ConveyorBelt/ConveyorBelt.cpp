/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ConveyorBelt.cpp
*/

#include "../Object/Wrap/Paper.hpp"
#include "../Object/Wrap/Box.hpp"
#include "ConveyorBelt.hpp"

ConveyorBelt::ConveyorBelt() : _obj(nullptr)
{
    say("created");
}

ConveyorBelt::~ConveyorBelt()
{
    if (_obj)
        delete _obj;
}

void ConveyorBelt::say(const std::string &message) const
{
    std::cout << "[CONVEYOR BELT] " << message << std::endl;
}

bool ConveyorBelt::in(Object::Types type)
{
    if (type != Object::PAPER && type != Object::BOX) {
        say("can only generate a Wrap");
        return (false);
    }
    if (_obj) {
        say("there is already something on it");
        return (false);
    }
    if (type == Object::PAPER) {
        _obj = new Paper;
        say("* bip bip * paper generated");
    } else {
        say("* bip bip * box generated");
        _obj = new Box;
    }
    return (true);
}

bool ConveyorBelt::out()
{
    if (!_obj) {
        say("nothing to send");
        return (false);
    }
    if (_obj->getType() != Object::PAPER || !_obj->isOpen()) {
        say("can't send a " + _obj->describe());
        return (false);
    }
    say("sent a " + _obj->describe());
    delete _obj;
    _obj = nullptr;
    return (true);
}

bool ConveyorBelt::put(Object *obj)
{
    if (!_obj) {
        _obj = obj;
        return (true);
    } else {
        return (_obj->wrapMeThat(obj));
    }
}

Object *ConveyorBelt::take()
{
    auto tmp = _obj;

    _obj = nullptr;
    return (tmp);
}

bool ConveyorBelt::isObjectOn() const
{
    return (_obj != nullptr);
}

const Object *ConveyorBelt::getOnConv() const
{
    return (_obj);
}
