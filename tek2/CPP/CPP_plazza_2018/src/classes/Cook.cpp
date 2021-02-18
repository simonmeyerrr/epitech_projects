/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Cook.cpp
*/

#include <iostream>
#include "Cook.hpp"

Cook::Cook(double time_pizza)
    : _time_pizza(time_pizza), _working(false)
{

}

std::deque<Serialization::SerialNumber> Cook::checkCommands()
{
    _working = false;
    return _ready;
}

bool Cook::takeCommand(Serialization::SerialNumber command)
{
    if (isActive())
        return false;
    _doing = command;
    _working = true;
    return true;
}

bool Cook::isActive() const
{
    return _working;
}

