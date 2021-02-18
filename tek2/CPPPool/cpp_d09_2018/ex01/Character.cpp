/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Character.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"

Character::Character(const std::string &name, int level)
    : Range(Character::CLOSE), _name(name), _lvl(level), _pv(100), _power(100),
    _strength(5), _stamina(5), _intelligence(5), _spirit(5), _agility(5),
    _race("Koala")
{
    std::cout << name << " Created" << std::endl;
}

bool Character::useEnergy(int energy)
{
    if (_power >= energy) {
        _power -= energy;
        return (true);
    } else {
        std::cout << _name << " out of power" << std::endl;
        return (false);
    }
}

void Character::addPv(int pv)
{
    if (_pv + pv > 100)
        _pv = 100;
    else
        _pv += pv;
}

int Character::CloseAttack()
{
    if (!useEnergy(10))
        return (0);

    std::cout << _name << " strikes with a wooden stick" << std::endl;
    return (10 + _strength);
}

void Character::Heal()
{
    addPv(50);
    std::cout << _name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (!useEnergy(10))
        return (0);

    std::cout << _name << " tosses a stone" << std::endl;
    return (5 + _strength);
}

void Character::RestorePower()
{
    _power = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    addPv(-damage);

    if (_pv > 0)
        std::cout << _name << " takes " << damage << " damage" << std::endl;
    else
        std::cout << _name << " out of combat" << std::endl;
}