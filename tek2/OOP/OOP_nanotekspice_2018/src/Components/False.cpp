/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** False.cpp
*/

#include <iostream>
#include "False.hpp"
#include "../Errors.hpp"
#include "Link.hpp"

#define HERE "False"

namespace nts {

    False::False(const std::string &name) : _name(name), _state(FALSE)
    {}

    Tristate False::compute(std::size_t pin)
    {
        switch (pin) {
        case 1:
            return (_state);
        default:
            throw nts::PinError("Invalid pin", HERE);
        }
    }

    void False::setLink(std::size_t pin, nts::IComponent &other,
        std::size_t other_pin)
    {
        if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
            throw nts::PinError("Invalid pin", HERE);
    }

    void False::dump() const
    {
        std::cout << "False " << getName() << std::endl;
    }

    ComponentType False::getType() const
    {
        return (nts::BOOL);
    }

    void False::updateState(nts::Tristate state)
    {
        (void)state;
    }

    std::string False::getName() const
    {
        return (_name);
    }
}

nts::PinType nts::False::getPinType(std::size_t pin) const
{
    if (pin == 1)
        return (OUT);
    return (NONE);
}
