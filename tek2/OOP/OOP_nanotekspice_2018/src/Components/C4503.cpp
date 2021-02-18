/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4503.cpp
*/

#include "C4503.hpp"

#include <iostream>
#include "C4503.hpp"
#include "Gates.hpp"

#define HERE "4503"

nts::C4503::C4503(const std::string &name)
    : _name(name)
{
    for (size_t i = 1; i <= 16; i++)
        _pins[i] = nullptr;
}

nts::Tristate nts::C4503::compute(std::size_t pin)
{
    switch (pin) {
    case 3:
        return (exec_compute(1, 2));
    case 5:
        return (exec_compute(1, 4));
    case 7:
        return (exec_compute(1, 6));
    case 9:
        return (exec_compute(1, 10));
     case 11:
         return (exec_compute(15, 12));
     case 13:
         return (exec_compute(15, 14));
    default:
        throw nts::PinError("Invalid pin", HERE);
    }
}

void nts::C4503::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
        throw nts::PinError("Invalid pin", HERE);
    _pins.erase(pin);
    _pins[pin] = new nts::Link(other, other_pin);
}

void nts::C4503::dump() const
{
    std::cout << "4503 " << getName() << ":" << std::endl;
    for (size_t i = 1; i <= 16; i++) {
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

void nts::C4503::updateState(nts::Tristate state)
{
    (void)state;
}

nts::PinType nts::C4503::getPinType(std::size_t pin) const
{
    const PinType pins[] = {NONE, IN, IN, OUT, IN, OUT, IN,
        OUT, NONE, OUT, IN, OUT, IN, OUT, IN, IN, NONE};
    if (pin <= 16)
        return (pins[pin]);
    return (NONE);
}

nts::Tristate nts::C4503::exec_compute(std::size_t pin1, std::size_t pin2)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);

    if (!link1 || !link2)
        throw nts::PinError("Pin not linked", HERE);
    nts::Tristate value = Gates::reverseState(
        link1->component.compute(link1->pin));
    return (Gates::andGate(value, link2->component.compute(link2->pin)));
}
