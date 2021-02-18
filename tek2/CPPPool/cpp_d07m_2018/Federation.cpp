/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** Federation.cpp
*/

#include <iostream>
#include <string>
#include "Destination.hpp"
#include "Federation.hpp"
#include "WarpSystem.hpp"

// Federation > Starfleet > Ensign
Federation::Starfleet::Ensign::Ensign(std::string name)
    : _name(name)
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{}

// Federation > Starfleet > Captain
Federation::Starfleet::Captain::Captain(std::string name)
    : _name(name), _age(0)
{}

Federation::Starfleet::Captain::~Captain()
{}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

// Federation > Starfleet > Ship
Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
    short maxWarp)
    : _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(nullptr), _captain(nullptr), _location(EARTH), _home(EARTH),
    _shield(100), _photonTorpedo(0)
{
    std::cout << "The ship USS " << name << " has been finished." << std::endl
    << "It is " << length << " m in length and " << width << " m in width."
    << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (!this->_core)
        return;
    std::cout << "USS " << this->_name << ": The core is " <<
        (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
        << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    if (!captain)
        return;
    this->_captain = captain;
    std::cout << captain->getName() <<
        ": I'm glad to be the captain of the USS " << this->_name << "."
        << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
        this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return (this->move(warp, this->_home));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return (this->move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return (this->move(this->_maxWarp, this->_home));
}

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

// Federation > Ship
Federation::Ship::Ship(int length, int width, std::string name)
    : _length(length), _width(width), _name(name), _maxWarp(1), _core(nullptr),
    _location(VULCAN), _home(VULCAN)
{
    std::cout << "The independant ship " << name <<
        " just finished its construction." << std::endl << "It is " << length
        << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (!this->_core)
        return;
    std::cout << this->_name << ": The core is " <<
        (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
        << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
        this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    return (this->move(warp, this->_home));
}

bool Federation::Ship::move(Destination d)
{
    return (this->move(this->_maxWarp, d));
}

bool Federation::Ship::move()
{
    return (this->move(this->_maxWarp, this->_home));
}