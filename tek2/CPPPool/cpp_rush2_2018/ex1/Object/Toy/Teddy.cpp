/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Teddy.cpp
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title)
    : Toy(Object::TEDDY, title)
{}

Teddy::~Teddy()
{}

void Teddy::say(const std::string &message) const
{
    std::cout << "[TEDDY] " << message << std::endl;
}

std::string Teddy::describe() const
{
    return ("Teddy \"" + getTitle() + "\"");
}

void Teddy::isTaken() const
{
    say("gra hu");
}
