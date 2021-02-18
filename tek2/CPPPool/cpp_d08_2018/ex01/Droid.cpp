/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Droid.cpp
*/

#include <iostream>
#include <string>
#include "DroidMemory.hpp"
#include "Droid.hpp"

Droid::Droid(std::string id)
    : _id(id), _energy(50), _attack(25), _toughness(15),
    _status(new std::string("Standing by")), _battleData(new DroidMemory)
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : _id(droid.getId()), _energy(droid.getEnergy()),
    _attack(droid.getAttack()), _toughness(droid.getToughness()),
    _status(new std::string(droid.getStatus())),
    _battleData(new DroidMemory(*droid.getBattleData()))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    if (_battleData)
        delete _battleData;
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

DroidMemory *Droid::getBattleData() const
{
    return (_battleData);
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

void Droid::setBattleData(DroidMemory *memory)
{
    if (_battleData)
        delete _battleData;
    _battleData = memory;
}

bool Droid::operator==(const Droid &other) const
{
    return (*_status == other.getStatus());
}

bool Droid::operator!=(const Droid &other) const
{
    return (*_status != other.getStatus());
}

void Droid::operator=(const Droid &other)
{
    _id = other.getId();
    _energy = other.getEnergy();
    if (_status)
        delete _status;
    _status = new std::string(other.getStatus());
    if (_battleData)
        delete _battleData;
    _battleData = new DroidMemory(*other.getBattleData());
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

std::ostream &operator<<(std::ostream &stream, const Droid &droid)
{
    stream << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
        << droid.getEnergy();
    return (stream);
}

