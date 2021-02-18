/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Ratatouille.cpp
*/

#include "Ratatouille.hpp"

Ratatouille::~Ratatouille()
{}

Ratatouille::Ratatouille()
{}

Ratatouille::Ratatouille(const Ratatouille &other)
{
    _s << other._s.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other)
{
    if (this == &other)
        return (*this);
    _s = std::stringstream{};
    _s << other._s.str();
    return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char vegetable)
{
    _s << vegetable;
    return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int condiment)
{
    _s << condiment;
    return (*this);
}

Ratatouille &Ratatouille::addSpice(double spice)
{
    _s << spice;
    return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string &sauce)
{
    _s << sauce;
    return (*this);
}

std::string Ratatouille::kooc()
{
    return (_s.str());
}