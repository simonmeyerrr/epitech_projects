/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** LittlePony.cpp
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title)
    : Toy(Object::LITTLEPONY, title)
{}

LittlePony::~LittlePony()
{}

void LittlePony::say(const std::string &message) const
{
    std::cout << "[LITTLE PONY] " << message << std::endl;
}

std::string LittlePony::describe() const
{
    return ("Little Pony \"" + getTitle() + "\"");
}

void LittlePony::isTaken() const
{
    say("yo man");
}
