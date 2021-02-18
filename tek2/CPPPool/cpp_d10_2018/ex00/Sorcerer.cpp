/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Sorcerer.cpp
*/

#include <iostream>
#include <string>
#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name),
    _title(title)
{
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title
        << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &stream, const Sorcerer &sorcerer)
{
    stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
        << ", and I like ponies!" << std::endl;
    return (stream);
}