/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Toy.cpp
*/

#include <iostream>
#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture()
{}

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
    : _type(type), _name(name), _picture(file)
{}

Toy::Toy(const Toy &other)
    : _type(other.getType()), _name(other.getName()), _picture()
{
    _picture.data = other.getAscii();
}

Toy::~Toy()
{}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return (_picture.getPictureFromFile(file));
}

std::string Toy::getAscii() const
{
    return (_picture.data);
}

void Toy::speak(const std::string &statement) const
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator=(const Toy &other)
{
    _type = other.getType();
    _name = other.getName();
    _picture.data = other.getAscii();
    return (*this);
}