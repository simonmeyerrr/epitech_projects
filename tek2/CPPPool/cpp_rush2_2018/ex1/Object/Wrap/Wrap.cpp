/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Wrap.cpp
*/

#include <string>
#include "../Object.hpp"
#include "Wrap.hpp"

Wrap::Wrap(Object::Types type, const std::string &title)
    : Object(Object::WRAP, type, title), _open(true), _obj(nullptr)
{}

Wrap::Wrap(Object::Types type, Object *obj)
    : Object(Object::WRAP, type, ""), _open(false), _obj(obj)
{
}

Wrap::~Wrap()
{
    if (_obj)
        delete _obj;
}

void Wrap::openMe()
{
    say("opened");
    _open = true;
}

void Wrap::closeMe()
{
    say("closed");
    _open = false;
}

bool Wrap::isOpen() const
{
    return (_open);
}

int Wrap::getObjectCount() const
{
    if (_obj)
        return (1 + _obj->getObjectCount());
    else
        return (1);
}

void Wrap::isTaken() const
{}