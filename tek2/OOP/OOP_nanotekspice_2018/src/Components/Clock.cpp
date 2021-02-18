/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Clock.cpp
*/

#include <iostream>
#include "Clock.hpp"
#include "../Errors.hpp"
#include "Link.hpp"

#define HERE "Clock"

namespace nts {

    Clock::Clock(const std::string &name)
        : _name(name), _state(UNDEFINED)
    {
    }

    Tristate Clock::compute(std::size_t pin)
    {
        switch (pin) {
        case 1:
            if (_state == UNDEFINED)
                throw nts::PinError("State uninitialized", HERE);
            return (_state);
        default:
            throw nts::PinError("Invalid pin", HERE);
        }
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other,
        std::size_t other_pin)
    {
        (void)pin;
        (void)other;
        (void)other_pin;
        throw nts::PinError("Invalid pin", HERE);
    }

    void Clock::dump() const
    {
        std::cout << "Clock " << getName();
        std::cout << " = " << tristateToString(_state) << std::endl;
    }

    ComponentType Clock::getType() const
    {
        return (nts::CLOCK);
    }

    void Clock::updateState(nts::Tristate state)
    {
        if (state != UNDEFINED) {
            _state = state;
        } else if (_state != UNDEFINED) {
            _state = (_state == TRUE ? FALSE : TRUE);
        }
    }

    std::string Clock::getName() const
    {
        return (_name);
    }
}

nts::PinType nts::Clock::getPinType(std::size_t pin) const
{
    if (pin == 1)
        return (OUT);
    return (NONE);
}