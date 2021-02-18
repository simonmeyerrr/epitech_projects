/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Priest.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
    : Mage(name, level)
{
    _strength = 4;
    _stamina = 4;
    _intelligence = 42;
    _spirit = 21;
    _agility = 2;
    _class = "Priest";
    _race = "Orc";
    std::cout << _name << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
    if (!useEnergy(10))
        return (0);

    Range = Character::RANGE;
    std::cout << _name << " uses a spirit explosion" << std::endl;
    return (10 + _spirit);
}

void Priest::Heal()
{
    if (!useEnergy(10))
        return;
    addPv(70);
    std::cout << _name << " casts a little heal spell" << std::endl;
}
