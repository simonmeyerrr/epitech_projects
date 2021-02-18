/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Droid.cpp
*/

#include <iostream>
#include <string>
#include "Droid.hpp"

Droid::Droid(std::string id)
    : _id(id), _energy(50), _attack(25), _toughness(15),
    _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : _id(droid.getId()), _energy(droid.getEnergy()),
    _attack(droid.getAttack()), _toughness(droid.getToughness()),
    _status(new std::string(droid.getStatus()))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (_id);
}

size_t Droid::getEnergy() const
{
    return (_energy);
}

size_t Droid::getAttack() const
{
    return (_attack);
}

size_t Droid::getToughness() const
{
    return (_toughness);
}

std::string Droid::getStatus() const
{
    return (*_status);
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        return;
    _energy = energy;
}

void Droid::setStatus(std::string *status)
{
    if (_status)
        delete _status;
    _status = status;
}

bool Droid::operator==(const Droid &other) const
{
    return (_id == other.getId() && _energy == other.getEnergy()
        && _attack == other.getAttack() && _toughness == other.getToughness()
        && *_status == other.getStatus());
}

bool Droid::operator!=(const Droid &other) const
{
    return (_id != other.getId() || _energy != other.getEnergy()
        || _attack != other.getAttack() || _toughness != other.getToughness()
        || *_status != other.getStatus());
}

void Droid::operator=(const Droid &other)
{
    _id = other.getId();
    _energy = other.getEnergy();
    _status = new std::string(other.getStatus());
}

Droid &Droid::operator<<(size_t &energy)
{
    if (_energy + energy > 100) {
        energy -= (100 - _energy);
        _energy = 100;
    } else {
        _energy += energy;
        energy = 0;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &stream,
    const Droid &droid)
{
    stream << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
        << droid.getEnergy();
    return (stream);
}