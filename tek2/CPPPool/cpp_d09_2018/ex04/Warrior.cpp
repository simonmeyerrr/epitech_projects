/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Warrior.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string weapon)
    : Character(name, level), _weapon(weapon)
{
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _agility = 7;
    _class = "Warrior";
    _race = "Dwarf";
    std::cout << "I'm " << _name
        << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack()
{
    if (!useEnergy(30))
        return (0);

    std::cout << _name << " strikes with his " << _weapon << std::endl;
    return (20 + _strength);
}

int Warrior::RangeAttack()
{
    if (!useEnergy(10))
        return (0);

    Range = Character::CLOSE;
    std::cout << _name << " intercepts" << std::endl;
    return (0);
}
