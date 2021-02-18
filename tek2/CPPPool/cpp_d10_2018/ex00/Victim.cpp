/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Victim.cpp
*/

#include <iostream>
#include <string>
#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << name << " just popped!"
        << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!"
        << std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep!"
        << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Victim &victim)
{
    stream << "I'm " << victim.getName() << " and i like otters!" << std::endl;
    return (stream);
}