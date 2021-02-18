/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** DroidMemory.cpp
*/

#include <random>
#include <iostream>
#include <string>
#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
    : _id(random()), _exp(0)
{}

DroidMemory::DroidMemory(const DroidMemory &other)
    : _id(other.getFingerPrint()), _exp(other.getExp())
{}

DroidMemory::~DroidMemory()
{}

size_t DroidMemory::getFingerPrint() const
{
    return (_id);
}

size_t DroidMemory::getExp() const
{
    return (_exp);
}

void DroidMemory::setFingerPrint(size_t id)
{
    _id = id;
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &other)
{
    _exp += other.getExp();
    _id = _id ^ other.getFingerPrint();
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other) const
{
    other.setExp(other.getExp() + _exp);
    other.setFingerPrint(other.getFingerPrint() ^ _id);
    return (other);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other)
{
    _exp += other.getExp();
    _id = _id ^ other.getFingerPrint();
    return (*this);
}

DroidMemory &DroidMemory::operator+=(size_t const &exp)
{
    _exp += exp;
    _id = _id ^ exp;
    return (*this);
}

DroidMemory &DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory *new_droid = new DroidMemory(*this);

    new_droid->_exp += other.getExp();
    new_droid->_id = new_droid->_id ^ other.getFingerPrint();
    return (*new_droid);
}

DroidMemory &DroidMemory::operator+(size_t const &exp) const
{
    DroidMemory *new_droid = new DroidMemory(*this);

    new_droid->_exp += exp;
    new_droid->_id = new_droid->_id ^ exp;
    return (*new_droid);
}

DroidMemory &DroidMemory::operator=(DroidMemory const &droid)
{
    _id = droid.getFingerPrint();
    _exp = droid.getExp();
    return (*this);
}

bool DroidMemory::operator==(const DroidMemory &other) const
{
    return (_exp == other.getExp() && _id == other.getFingerPrint());
}

bool DroidMemory::operator!=(const DroidMemory &other) const
{
    return (_exp != other.getExp() || _id != other.getFingerPrint());
}

bool DroidMemory::operator<(const DroidMemory &other) const
{
    return (_exp < other.getExp());
}

bool DroidMemory::operator>(const DroidMemory &other) const
{
    return (_exp > other.getExp());
}

bool DroidMemory::operator<=(const DroidMemory &other) const
{
    return (_exp <= other.getExp());
}

bool DroidMemory::operator>=(const DroidMemory &other) const
{
    return (_exp >= other.getExp());
}

bool DroidMemory::operator==(const size_t &other) const
{
    return (_exp == other);
}

bool DroidMemory::operator!=(const size_t &other) const
{
    return (_exp != other);
}

bool DroidMemory::operator<(const size_t &other) const
{
    return (_exp < other);
}

bool DroidMemory::operator>(const size_t &other) const
{
    return (_exp > other);
}

bool DroidMemory::operator<=(const size_t &other) const
{
    return (_exp <= other);
}

bool DroidMemory::operator>=(const size_t &other) const
{
    return (_exp >= other);
}

std::ostream &operator<<(std::ostream &stream, const DroidMemory &droid)
{
    stream << "DroidMemory '" << droid.getFingerPrint() << "', " <<
        droid.getExp();
    return (stream);
}
