/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** SuperMutant.cpp
*/

#include <iostream>
#include <string>
#include "SuperMutant.hpp"
#include "AEnemy.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;
    if (damage > 0)
        _hp -= damage;
}