/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** True.cpp
*/

#include <iostream>
#include "True.hpp"
#include "../Errors.hpp"
#include "Link.hpp"

#define HERE "True"

namespace nts {

    True::True(const std::string &name) : _name(name), _state(TRUE)
    {}

    Tristate True::compute(std::size_t pin)
    {
        switch (pin) {
        case 1:
            return (_state);
        default:
            throw nts::PinError("Invalid pin", HERE);
        }
    }

    void True::setLink(std::size_t pin, nts::IComponent &other,
        std::size_t other_pin)
    {
        if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
            throw nts::PinError("Invalid pin", HERE);
    }

    void True::dump() const
    {
        std::cout << "True " << getName() << std::endl;
    }

    ComponentType True::getType() const
    {
        return (nts::BOOL);
    }

    void True::updateState(nts::Tristate state)
    {
        (void)state;
    }

    std::string True::getName() const
    {
        return (_name);
    }
}

nts::PinType nts::True::getPinType(std::size_t pin) const
{
    if (pin == 1)
        return (OUT);
    return (NONE);
}
