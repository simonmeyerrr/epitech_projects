/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** IConveyorBelt.cpp
*/

#include "ConveyorBeltRand.hpp"
#include "ConveyorBelt.hpp"

IConveyorBelt *createConveyorBelt()
{
    return (new ConveyorBelt);
}

IConveyorBelt *createConveyorBeltRand()
{
    return (new ConveyorBeltRand);
}