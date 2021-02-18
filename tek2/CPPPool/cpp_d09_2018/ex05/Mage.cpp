/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Mage.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
    : Character(name, level)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;
    _class = "Mage";
    _race = "Gnome";
    std::cout << _name << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    if (!useEnergy(10))
        return (0);

    Range = Character::RANGE;
    std::cout << _name << " blinks" << std::endl;
    return (0);
}

int Mage::RangeAttack()
{
    if (!useEnergy(25))
        return (0);

    std::cout << _name << " launches a fire ball" << std::endl;
    return (20 + _spirit);
}

void Mage::RestorePower()
{
    if (_power + 50 + _intelligence > 100)
        _power = 100;
    else
        _power += 50 + _intelligence;
    std::cout << _name << " takes a mana potion" << std::endl;
}