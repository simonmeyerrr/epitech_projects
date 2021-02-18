/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Box.cpp
*/

#include "Box.hpp"

Box::Box(const std::string &title) : Wrap(Object::BOX, title)
{}

Box::Box(Object *obj) : Wrap(Object::BOX, obj)
{}

Box::~Box()
{}

void Box::say(const std::string &message) const
{
    std::cout << "[BOX] " << message << std::endl;
}

std::string Box::describe() const
{
    if (!_obj) {
        return ("empty " + std::string(_open ? "opened" : "closed")  +
            " box");
    } else {
        return (std::string(_open ? "opened" : "closed")  +
            " box that contains a " + _obj->describe());
    }
}

bool Box::wrapMeThat(Object *obj)
{
    if (!_open)
        return (false);
    if (_obj)
        return (false);
    if (obj->getMainType() != Object::TOY)
        return (false);

    _obj = obj;
    closeMe();
    return (true);
}

Object *Box::takeObject()
{
    if (!_open) {
        say("is closed, can't take the object inside");
        return (nullptr);
    }
    if (!_obj) {
        say("there is nothing inside");
        return (nullptr);
    }

    auto ret = _obj;
    ret->isTaken();
    _obj = nullptr;
    return (ret);
}

const Object *Box::getObject() const
{
    return (_obj);
}
