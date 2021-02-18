/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Event.cpp
*/

#include "Event.hpp"

namespace arcade {

    Event::Event(EventType type, int x, int y)
        : _type(type), _pos(x, y)
    {}

    Event::Event(EventType type, const Vector &v)
        : _type(type), _pos(v)
    {}

    Event::Event(const Event &e)
        : _type(e._type), _pos(e._pos)
    {}

    Event &Event::operator=(const Event &e)
    {
        if (this == &e)
            return (*this);
        _type = e._type;
        _pos = e._pos;
        return (*this);
    }

    bool Event::operator==(const Event &e) const
    {
        return (_type == e._type);
    }

    bool Event::operator==(const EventType &e) const
    {
        return (_type == e);
    }

    EventType Event::getType() const
    {
        return (_type);
    }

    Vector Event::getPos() const
    {
        return (_pos);
    }
}