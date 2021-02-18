/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Serialization.cpp
*/

#include <iostream>
#include "Serialization.hpp"

Serialization::SerialNumber Serialization::pack(short command_id,
    PizzaType type, PizzaSize size)
{
    SerialNumber nb = 0;
    nb += command_id;
    nb <<= 8;
    nb += type;
    nb <<= 8;
    nb += size;
    return nb;
}

std::tuple<short, PizzaType, PizzaSize> Serialization::unpack(SerialNumber nb)
{
    SerialNumber cpy = nb;
    cpy >>= 16;
    short command_id = (short)cpy;
    cpy = nb;
    cpy <<= 16;
    cpy >>= 24;
    PizzaType type = (PizzaType)cpy;
    cpy = nb;
    cpy <<= 24;
    cpy >>= 24;
    PizzaSize size = (PizzaSize)cpy;
    return {command_id, type, size};
}