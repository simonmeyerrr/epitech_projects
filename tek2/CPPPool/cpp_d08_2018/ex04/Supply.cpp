/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Supply.cpp
*/

#include <iostream>
#include <string>
#include "Droid.hpp"
#include "Supply.hpp"

Supply::Supply(Types type, size_t amount, Droid **wrecks)
    : _type(type), _amount(amount), _wrecks(wrecks)
{
}

Supply::~Supply()
{
    if (_type == Wreck && _wrecks) {
        for (size_t i = _amount - 1; i < _amount; i--) {
            if (_wrecks[i])
                delete _wrecks[i];
            _wrecks[i] = nullptr;
        }
    }
}

Droid *&Supply::operator*()
{
    return (_wrecks[0]);
}

Droid *&Supply::operator->()
{
    return (_wrecks[0]);
}

Supply &Supply::operator++()
{
    if (_amount == 0 || _amount == 1)
        return (*this);

    auto tmp = _wrecks[0];
    for (size_t i = 0; i < _amount - 1; i++) {
        _wrecks[i] = _wrecks[i + 1];
    }
    _wrecks[_amount - 1] = tmp;
    return (*this);
}

Supply &Supply::operator--()
{
    if (_amount == 0 || _amount == 1)
        return (*this);

    auto tmp = _wrecks[_amount - 1];
    for (size_t i = 0; i < _amount - 1; i++) {
        _wrecks[i + 1] = _wrecks[i];
    }
    _wrecks[0] = tmp;
    return (*this);
}

Supply &Supply::operator!()
{
    if (_type == Wreck && _wrecks) {
        for (size_t i = _amount - 1; i < _amount; i--) {
            if (_wrecks[i])
                delete _wrecks[i];
            _wrecks[i] = nullptr;
        }
    }
    _wrecks = nullptr;
    _amount = 0;
    return (*this);
}

bool Supply::operator==(const Supply &other) const
{
    return (this->getType() == other.getType());
}

bool Supply::operator!=(const Supply &other) const
{
    return (this->getType() != other.getType());
}

Supply::operator size_t() const
{
    return (_amount);
}

std::ostream &operator<<(std::ostream &stream, const Supply &supply)
{
    std::string tab[4] = {"", "Iron", "Silicon", "Wreck"};
    stream << "Supply : " << supply.getAmount() << ", " <<
        tab[supply.getType()];
    if (supply.getType() == Supply::Wreck) {
        if (supply.getAmount() > 0)
            stream << std::endl;
        for (size_t i = 0; i < supply.getAmount(); i++) {
            stream << *supply.getWrecks()[i];
            if (i != supply.getAmount() - 1)
                stream << std::endl;
        }
    }
    return (stream);
}