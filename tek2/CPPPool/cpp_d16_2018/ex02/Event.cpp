/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Event.cpp
*/

#include "Event.hpp"

Event::~Event()
{}

Event::Event() : _time(0), _event("")
{}

Event::Event(unsigned int time, const std::string &event)
    : _time(time), _event(event)
{}

Event::Event(const Event &other) : _time(other._time), _event(other._event)
{}

Event &Event::operator=(const Event &other)
{
    if (this == &other)
        return (*this);
    _time = other._time;
    _event = other._event;
    return (*this);
}

unsigned int Event::getTime() const
{
    return (_time);
}

const std::string &Event::getEvent() const
{
    return (_event);
}

void Event::setTime(unsigned int time)
{
    _time = time;
}

void Event::setEvent(const std::string &event)
{
    _event = event;
}

std::ostream &operator<<(std::ostream &stream, const Event &other)
{
    stream << other.getTime() << ": " << other.getEvent();
    return (stream);
}