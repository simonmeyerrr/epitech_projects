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
    if (!_picture.getPictureFromFile(file)) {
        _lastError.type = Error::PICTURE;
        return (false);
    } else {
        _lastError.type = Error::UNKNOWN;
        return (true);
    }
}

std::string Toy::getAscii() const
{
    return (_picture.data);
}

bool Toy::speak(const std::string &statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
    _lastError.type = Error::UNKNOWN;
    return (true);
}

bool Toy::speak_es(const std::string &statement)
{
    (void)statement;
    _lastError.type = Error::SPEAK;
    return (false);
}

Toy &Toy::operator=(const Toy &other)
{
    _type = other.getType();
    _name = other.getName();
    _picture.data = other.getAscii();
    return (*this);
}

std::string Toy::Error::what() const
{
    switch (type) {
    case PICTURE:
        return ("bad new illustration");
    case SPEAK:
        return ("wrong mode");
    default:
        return ("");
    }
}

std::string Toy::Error::where() const
{
    switch (type) {
    case PICTURE:
        return ("setAscii");
    case SPEAK:
        return ("speak_es");
    default:
        return ("");
    }
}

Toy::Error Toy::getLastError() const
{
    return (_lastError);
}

Toy &Toy::operator<<(const std::string &other)
{
    _picture.data = other;
    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return (stream);
}