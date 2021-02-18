/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Carrier.cpp
*/

#include <iostream>
#include <string>
#include "Carrier.hpp"
#include "Droid.hpp"

Carrier::Carrier(const std::string id)
    : _id(id), _energy(300), _attack(100), _toughness(90), _speed(0),
    _nbDroids(0), _x(0), _y(0)
{
    _droids[0] = nullptr;
    _droids[1] = nullptr;
    _droids[2] = nullptr;
    _droids[3] = nullptr;
    _droids[4] = nullptr;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++) {
        if (_droids[i])
            delete _droids[i];
    }
}

void Carrier::updateSpeed()
{
    _nbDroids = 0;

    for (int i = 0; i < 5; i++) {
        if (_droids[i])
            _nbDroids++;
    }
    if (_nbDroids == 0)
        _speed = 0;
    else
        _speed = 100 - (10 * _nbDroids);
}

Carrier &Carrier::operator<<(Droid *&droid)
{
    int place = 0;

    if (!droid)
        return (*this);
    while (place < 5 && _droids[place])
        place++;
    if (place == 5)
        return (*this);
    _droids[place] = droid;
    droid = nullptr;
    updateSpeed();
    return (*this);
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    int place = 0;

    while (place < 5 && !_droids[place])
        place++;
    if (place == 5)
        return (*this);
    droid = _droids[place];
    _droids[place] = nullptr;
    updateSpeed();
    return (*this);
}

Droid *&Carrier::operator[](const size_t &pos)
{
    return (_droids[pos]);
}

Droid *Carrier::operator[](const size_t &pos) const
{
    return (_droids[pos]);
}

Carrier &Carrier::operator~()
{
    updateSpeed();
    return (*this);
}

bool Carrier::operator()(const int &x, const int &y)
{
    updateSpeed();
    if (_speed == 0 || _energy < (abs(x) + abs(y)) * (10 + (_nbDroids)))
        return (false);
    _energy -= (abs(x) + abs(y)) * (10 + (_nbDroids));
    _x = x;
    _y = y;
    return (true);
}

Carrier &Carrier::operator<<(size_t &energy)
{
    if (_energy + energy > 600) {
        energy -= (600 - _energy);
        _energy = 600;
    } else {
        _energy += energy;
        energy = 0;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Carrier &carrier)
{
    stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" <<
    std::endl;
    for (int i = 0; i < 5; i++) {
        stream << "[" << i << "] : ";
        if (nullptr == (void *)(carrier[i]))
            stream << "Free" << std::endl;
        else
            stream << *(carrier[i]) << std::endl;
    }
    stream << "Speed : " << carrier.getSpeed() << ", Energy " <<
    carrier.getEnergy();
    return (stream);
}