/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** RadScorpion.cpp
*/

#include <iostream>
#include <string>
#include "RadScorpion.hpp"
#include "AEnemy.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}