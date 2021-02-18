/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Output.cpp
*/

#include <iostream>
#include "Output.hpp"
#include "../Errors.hpp"

#define HERE "Output"

namespace nts {

    Output::Output(const std::string &name)
        : _name(name), _state(nts::UNDEFINED)
    {
        for (size_t i = 1; i <= 1; i++)
            _pins[i] = nullptr;
    }

    Tristate Output::compute(std::size_t pin)
    {
        Link *link;

        switch (pin) {
        case 0:
            link = _pins.at(1);
            if (!link)
                throw nts::PinError("Pin not linked", HERE);
            _state = link->component.compute(link->pin);
            return (_state);
        case 1:
            return (_state);
        default:
            throw nts::PinError("Invalid pin", HERE);
        }
    }

    void Output::setLink(std::size_t pin, nts::IComponent &other,
        std::size_t other_pin)
    {
        if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
            throw nts::PinError("Invalid pin", HERE);
        _pins.erase(pin);
        _pins[pin] = new nts::Link(other, other_pin);
    }

    void Output::dump() const
    {
        std::cout << "Output " << getName() << ":" << std::endl;
        std::cout << "-pin" << 1 << ": input ";
        std::cout << (_pins.at(1) ? "linked" : "not linked");
        std::cout << std::endl;
    }

    ComponentType Output::getType() const
    {
        return (nts::OUTPUT);
    }

    void Output::updateState(nts::Tristate state)
    {
        (void)state;
    }

    std::string Output::getName() const
    {
        return (_name);
    }
}

nts::PinType nts::Output::getPinType(std::size_t pin) const
{
    if (pin == 1)
        return (IN);
    return (NONE);
}