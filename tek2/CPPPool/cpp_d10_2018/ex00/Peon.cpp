/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Peon.cpp
*/

#include <iostream>
#include <string>
#include "Victim.hpp"
#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..."<< std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
