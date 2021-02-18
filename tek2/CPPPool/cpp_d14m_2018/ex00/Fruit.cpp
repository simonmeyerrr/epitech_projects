/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, int vitamins)
    : _name(name), _vitamins(vitamins)
{}

Fruit::Fruit(const Fruit &other)
    : _name(other._name), _vitamins(other._vitamins)
{}

std::string Fruit::getName() const
{
    return (_name);
}

int Fruit::getVitamins() const
{
    return (_vitamins);
}

Fruit &Fruit::operator=(const Fruit &other)
{
    _name = other._name;
    _vitamins = other._vitamins;
    return (*this);
}