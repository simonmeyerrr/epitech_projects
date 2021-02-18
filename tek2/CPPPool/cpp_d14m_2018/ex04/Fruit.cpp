/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::~Fruit()
{}

int Fruit::getVitamins() const
{
    return (_vitamins);
}

void Fruit::setVitamins(int vitamins)
{
    _vitamins = vitamins;
}
