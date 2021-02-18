/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Paper.cpp
*/

#include "Paper.hpp"

Paper::Paper(const std::string &title) : Wrap(Object::PAPER, title)
{}

Paper::Paper(Object *obj) : Wrap(Object::PAPER, obj)
{}

Paper::~Paper()
{}

void Paper::say(const std::string &message) const
{
    std::cout << "[PAPER] " << message << std::endl;
}

std::string Paper::describe() const
{
    if (!_obj) {
        return ("empty " + std::string(_open ? "opened" : "closed")  +
            " paper");
    } else {
        return (std::string(_open ? "opened" : "closed")  +
            " paper that contains a " + _obj->describe());
    }
}

bool Paper::wrapMeThat(Object *obj)
{
    if (_obj)
        return (false);
    if (obj->getType() != Object::BOX)
        return (false);

    if (obj->isOpen())
        return (false);
    _obj = obj;
    closeMe();
    return (true);
}

Object *Paper::takeObject()
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
    _obj = nullptr;
    return (ret);
}

const Object *Paper::getObject() const
{
    return (_obj);
}
