/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** Borg.cpp
*/

#include <iostream>
#include <string>
#include "Destination.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

Borg::Ship::Ship()
    : _side(300), _maxWarp(9), _core(nullptr), _location(UNICOMPLEX),
    _home(UNICOMPLEX)
{
    std::cout << "We are the Borgs. Lower your shields and surrender "
        << "yourselves unconditionally." << std::endl
        << "Your biological characteristics and technologies will be "
           "assimilated." << std::endl << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    if (!this->_core)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
    this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    return (this->move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
    return (this->move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return (this->move(this->_maxWarp, this->_home));
}