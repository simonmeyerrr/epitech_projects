/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4515.cpp
*/

#include <iostream>
#include "C4515.hpp"
#include "Gates.hpp"

#define HERE "4515"

nts::C4515::C4515(const std::string &name)
    : _name(name)
{
    for (size_t i = 1; i <= 24; i++)
        _pins[i] = nullptr;
}

nts::Tristate nts::C4515::compute(std::size_t pin)
{
    switch (pin) {
    case 4:
        return (exec_compute_three(2, 3, 21, 22, 1, 23));
    case 5:
        return (exec_compute_two(3, 21, 2, 22, 1, 23));
    case 6:
        return (exec_compute_two(2, 21, 3, 22, 1, 23));
    case 7:
        return (exec_compute_one(21, 2, 3, 22, 1, 23));
    case 8:
        return (exec_compute_two(2, 3, 21, 22, 1, 23));
    case 9:
        return (exec_compute_one(2, 3, 21, 22, 1, 23));
    case 10:
        return (exec_compute_one(3, 2, 21, 22, 1, 23));
    case 11:
        return (exec_compute_any(2, 3, 21, 22, 1, 23));
    case 13:
        return (exec_compute_three(2, 21, 22, 3, 1, 23));
    case 14:
        return (exec_compute_two(21, 22, 2, 3, 1, 23));
    case 15:
        return (exec_compute_four(2, 3, 21, 22, 1, 23));
    case 16:
        return (exec_compute_three(3, 21, 22, 2, 1, 23));
    case 17:
        return (exec_compute_two(2, 22, 3, 21, 1, 23));
    case 18:
        return (exec_compute_one(22, 2, 3, 21, 1, 23));
    case 19:
        return (exec_compute_three(2, 3, 22, 21, 1, 23));
    case 20:
        return (exec_compute_two(3, 22, 2, 21, 1, 23));
    default:
        throw nts::PinError("Invalid pin", HERE);
    }
}

void nts::C4515::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    if (getPinType(pin) != IN || other.getPinType(other_pin) != OUT)
        throw nts::PinError("Invalid pin", HERE);
    _pins.erase(pin);
    _pins[pin] = new nts::Link(other, other_pin);
}

void nts::C4515::dump() const
{
    std::cout << "4515 " << getName() << std::endl;
    for (size_t i = 1; i <= 24; i++) {
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

void nts::C4515::updateState(nts::Tristate state)
{
    (void)state;
}

nts::PinType nts::C4515::getPinType(std::size_t pin) const
{
    const PinType pins[] = {NONE, IN, IN, IN, OUT, OUT, OUT, OUT, OUT, OUT, OUT,
        OUT, NONE, OUT, OUT, OUT, OUT, OUT, OUT, OUT, OUT, IN, IN, IN, NONE};
    if (pin <= 24)
        return (pins[pin]);
    return (NONE);
}

nts::Tristate nts::C4515::exec_compute_any(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4, std::size_t pin5, std::size_t pin6)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);
    Link *link5 = _pins.at(pin5);
    Link *link6 = _pins.at(pin6);

    if (!link1 || !link2 || !link3 || !link4 || !link5 || !link6)
        throw nts::PinError("Pin not linked", HERE);
    if (link6->component.compute(link6->pin) == TRUE)
        return (TRUE);
    nts::Tristate value = Gates::anyTrue(
        link1->component.compute(link1->pin),
        link2->component.compute(link2->pin),
        link3->component.compute(link3->pin),
        link4->component.compute(link4->pin)
    );
    if (link5->component.compute(link5->pin) == FALSE)
        value = Gates::reverseState(value);
    return (Gates::reverseState(value));
}

nts::Tristate nts::C4515::exec_compute_one(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4, std::size_t pin5, std::size_t pin6)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);
    Link *link5 = _pins.at(pin5);
    Link *link6 = _pins.at(pin6);

    if (!link1 || !link2 || !link3 || !link4 || !link5 || !link6)
        throw nts::PinError("Pin not linked", HERE);
    if (link6->component.compute(link6->pin) == TRUE)
        return (TRUE);
    nts::Tristate value = Gates::oneTrue(
        link1->component.compute(link1->pin),
        link2->component.compute(link2->pin),
        link3->component.compute(link3->pin),
        link4->component.compute(link4->pin)
    );
    if (link5->component.compute(link5->pin) == FALSE)
        value = Gates::reverseState(value);
    return (Gates::reverseState(value));
}

nts::Tristate nts::C4515::exec_compute_two(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4, std::size_t pin5, std::size_t pin6)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);
    Link *link5 = _pins.at(pin5);
    Link *link6 = _pins.at(pin6);

    if (!link1 || !link2 || !link3 || !link4 || !link5 || !link6)
        throw nts::PinError("Pin not linked", HERE);
    if (link6->component.compute(link6->pin) == TRUE)
        return (TRUE);
    nts::Tristate value = Gates::twoTrue(
        link1->component.compute(link1->pin),
        link2->component.compute(link2->pin),
        link3->component.compute(link3->pin),
        link4->component.compute(link4->pin)
    );
    if (link5->component.compute(link5->pin) == FALSE)
        value = Gates::reverseState(value);
    return (Gates::reverseState(value));
}

nts::Tristate nts::C4515::exec_compute_three(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4, std::size_t pin5, std::size_t pin6)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);
    Link *link5 = _pins.at(pin5);
    Link *link6 = _pins.at(pin6);

    if (!link1 || !link2 || !link3 || !link4 || !link5 || !link6)
        throw nts::PinError("Pin not linked", HERE);
    if (link6->component.compute(link6->pin) == TRUE)
        return (TRUE);
    nts::Tristate value = Gates::threeTrue(
        link1->component.compute(link1->pin),
        link2->component.compute(link2->pin),
        link3->component.compute(link3->pin),
        link4->component.compute(link4->pin)
    );
    if (link5->component.compute(link5->pin) == FALSE)
        value = Gates::reverseState(value);
    return (Gates::reverseState(value));

}

nts::Tristate nts::C4515::exec_compute_four(std::size_t pin1, std::size_t pin2,
    std::size_t pin3, std::size_t pin4, std::size_t pin5, std::size_t pin6)
{
    Link *link1 = _pins.at(pin1);
    Link *link2 = _pins.at(pin2);
    Link *link3 = _pins.at(pin3);
    Link *link4 = _pins.at(pin4);
    Link *link5 = _pins.at(pin5);
    Link *link6 = _pins.at(pin6);

    if (!link1 || !link2 || !link3 || !link4 || !link5 || !link6)
        throw nts::PinError("Pin not linked", HERE);
    if (link6->component.compute(link6->pin) == TRUE)
        return (TRUE);
    nts::Tristate value = Gates::fourTrue(
        link1->component.compute(link1->pin),
        link2->component.compute(link2->pin),
        link3->component.compute(link3->pin),
        link4->component.compute(link4->pin)
    );
    if (link5->component.compute(link5->pin) == FALSE)
        value = Gates::reverseState(value);
    return (Gates::reverseState(value));
}