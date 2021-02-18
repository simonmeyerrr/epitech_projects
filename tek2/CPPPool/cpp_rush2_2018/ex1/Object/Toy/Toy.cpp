/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy(Object::Types type, const std::string &title)
    : Object(Object::TOY, type, title)
{}

Toy::~Toy()
{}

int Toy::getObjectCount() const
{
    return (1);
}

void Toy::openMe()
{}

void Toy::closeMe()
{}

bool Toy::isOpen() const
{
    return (false);
}

bool Toy::wrapMeThat(Object *obj)
{
    (void)obj;
    return (false);
}

Object *Toy::takeObject()
{
    return (nullptr);
}

const Object *Toy::getObject() const
{
    return (nullptr);
}