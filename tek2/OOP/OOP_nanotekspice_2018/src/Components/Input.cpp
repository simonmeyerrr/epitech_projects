/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Input.cpp
*/

#include <iostream>
#include "Input.hpp"
#include "../Errors.hpp"
#include "Link.hpp"

#define HERE "Input"

namespace nts {

    Input::Input(const std::string &name)
        : _name(name), _state(UNDEFINED)
    {}

    Tristate Input::compute(std::size_t pin)
    {
        switch (pin) {
        case 1:
            return (_state);
        default:
            throw nts::PinError("Invalid pin", HERE);
        }
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other,
        std::size_t other_pin)
    {
        if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
            throw nts::PinError("Invalid pin", HERE);
    }

    void Input::dump() const
    {
        std::cout << "Input " << getName();
        std::cout << " = " << tristateToString(_state) << std::endl;
    }

    ComponentType Input::getType() const
    {
        return (nts::INPUT);
    }

    void Input::updateState(nts::Tristate state)
    {
        _state = state;
    }

    std::string Input::getName() const
    {
        return (_name);
    }
}

nts::PinType nts::Input::getPinType(std::size_t pin) const
{
    if (pin == 1)
        return (OUT);
    return (NONE);
}