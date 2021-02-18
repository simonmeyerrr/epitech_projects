/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4069.cpp
*/

#include <iostream>
#include "C4069.hpp"
#include "Gates.hpp"

#define HERE "4069"

nts::C4069::C4069(const std::string &name)
    : _name(name)
{
    for (size_t i = 1; i <= 14; i++)
        _pins[i] = nullptr;
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    switch (pin) {
    case 2:
        return (exec_compute(1));
    case 4:
        return (exec_compute(3));
    case 6:
        return (exec_compute(5));
    case 8:
        return (exec_compute(9));
    case 10:
        return (exec_compute(11));
    case 12:
        return (exec_compute(13));
    default:
        throw nts::PinError("Invalid pin", HERE);
    }
}

void nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
        throw nts::PinError("Invalid pin", HERE);
    _pins.erase(pin);
    _pins[pin] = new nts::Link(other, other_pin);
}

void nts::C4069::dump() const
{
    std::cout << "4069 " << getName() << ":" << std::endl;
    for (size_t i = 1; i <= 14; i++) {
        std::cout << "-pin" << i << ": ";
        if (getPinType(i) == OUT)
            std::cout << "output";
        if (getPinType(i) == NONE)
            std::cout << "none";
        if (getPinType(i) == IN) {
            std::cout << "input ";
            std::cout << (_pins.at(i) ? "linked" : "not linked");
        }
        std::cout << std::endl;
    }
}

void nts::C4069::updateState(nts::Tristate state)
{
    (void)state;
}

nts::PinType nts::C4069::getPinType(std::size_t pin) const
{
    const PinType pins[] = {NONE, IN, OUT, IN, OUT, IN, OUT,
        NONE, OUT, IN, OUT, IN, OUT, IN, NONE};
    if (pin <= 14)
        return (pins[pin]);
    return (NONE);
}

nts::Tristate nts::C4069::exec_compute(std::size_t pin)
{
    Link *link1 = _pins.at(pin);

    if (!link1)
        throw nts::PinError("Pin not linked", HERE);
    return (Gates::reverseState(link1->component.compute(link1->pin)));
}
