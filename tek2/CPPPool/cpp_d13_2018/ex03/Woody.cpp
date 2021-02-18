/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Woody.cpp
*/

#include <iostream>
#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file)
    : Toy(Toy::WOODY, name, file)
{}

Woody::~Woody()
{}

void Woody::speak(const std::string &statement) const
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
}