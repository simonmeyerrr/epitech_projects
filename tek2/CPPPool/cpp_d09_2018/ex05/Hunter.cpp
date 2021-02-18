/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Hunter.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Warrior.hpp"
#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, const std::string weapon)
    : Character(name, level), Warrior(name, level, weapon)
{
    _strength = 9;
    _stamina = 9;
    _intelligence = 5;
    _spirit = 6;
    _agility = 25;
    _class = "Hunter";
    _race = "Elf";
    std::cout << _name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{}

int Hunter::RangeAttack()
{
    if (!useEnergy(25))
        return (0);

    std::cout << _name << " uses his bow" << std::endl;
    return (20 + _agility);
}

void Hunter::RestorePower()
{
    _power = 100;
    std::cout << _name << " meditates" << std::endl;
}
