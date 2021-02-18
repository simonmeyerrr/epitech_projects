/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Object.cpp
*/

#include "Object.hpp"
#include "Toy/LittlePony.hpp"
#include "Toy/Teddy.hpp"

Object::Object(MainTypes mainType, Types type, const std::string &title)
    : _mainType(mainType), _type(type), _title(title)
{
    say("created " + mainTypeName[getMainType()] + " " + typeName[getType()]
        + " " + getTitle());
}

Object::~Object()
{
    say("deleted " + mainTypeName[getMainType()] + " " + typeName[getType()]
    + " " + getTitle());
}

void Object::say(const std::string &message) const
{
    std::cout << "[OBJECT] " << message << std::endl;
}

Object::MainTypes Object::getMainType() const
{
    return (_mainType);
}
Object::Types Object::getType() const
{
    return (_type);
}

std::string Object::getTitle() const
{
    return (_title);
}

std::ostream &operator<<(std::ostream &stream, const Object &obj)
{
    stream << obj.describe();
    return (stream);
}

Object **MyUnitTests()
{
    auto tab = new Object*[2];
    tab[0] = new Teddy;
    tab[1] = new LittlePony;
    return (tab);
}