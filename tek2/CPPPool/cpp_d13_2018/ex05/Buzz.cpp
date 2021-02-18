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

bool Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
    _lastError.type = Error::UNKNOWN;
    return (true);
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " senorita \"" << statement <<
        "\" senorita" << std::endl;
    _lastError.type = Error::UNKNOWN;
    return (true);
}