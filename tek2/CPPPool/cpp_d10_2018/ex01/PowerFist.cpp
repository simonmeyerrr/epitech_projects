/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** PowerFist.cpp
*/

#include <iostream>
#include <string>
#include "PowerFist.hpp"
#include "AWeapon.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{}

PowerFist::~PowerFist()
{}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}