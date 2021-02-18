/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4012.cpp
*/

#include <iostream>
#include "C4012.hpp"
#include "Gates.hpp"

#define HERE "4012"

nts::C4012::C4012(const std::string &name)
    : _name(name)
{
    for (size_t i = 1; i <= 14; i++)
        _pins[i] = nullptr;
}

nts::Tristate nts::C4012::compute(std::size_t pin)
{
    switch (pin) {
    case 1:
        return (exec_compute(2, 3, 4, 5));
    case 13:
        return (exec_compute(9, 10, 11, 12));
    default:
        throw nts::PinError("Invalid pin", HERE);
    }
}

void nts::C4012::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t other_pin
)
{
    if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
        throw nts::PinError("Invalid pin", HERE);
    _pins.erase(pin);
    _pins[pin] = new nts::Link(other, other_pin);
}

void nts::C4012::dump() const
{
    std::cout << "4012 " << getName() << ":" << std::endl;
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

void nts::C4012::updateState(nts::Tristate state)
{
    (void)state;
}

nts::PinType nts::C4012::getPinType(std::size_t pin) const
{
    const PinType pins[] = {NONE, OUT, IN, IN, IN, IN, NONE, NONE, NONE, IN, IN,
        IN, IN, OUT, NONE};
    if (pin <= 14)
        return (pins[pin]);
    return (NONE);
}

nts::Tristate nts::C4012::exec_compute(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);

    if (!link1 || !link2 || !link3 || !link4)
        throw nts::PinError("Pin not linked", HERE);
    nts::Tristate value1 = Gates::andGate(link1->component.compute(link1->pin),
        link2->component.compute(link2->pin));
    nts::Tristate value2 = Gates::andGate(link3->component.compute(link3->pin),
        link4->component.compute(link4->pin));
    return (Gates::reverseState(Gates::andGate(value1, value2)));
}
