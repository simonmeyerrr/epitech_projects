/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Buzz.cpp
*/

#include <iostream>
#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file)
    : Toy(Toy::BUZZ, name, file)
{}

Buzz::~Buzz()
{}

void Buzz::speak(const std::string &statement) const
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}