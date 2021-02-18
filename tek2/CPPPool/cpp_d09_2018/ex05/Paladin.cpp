/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Paladin.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Paladin.hpp"
#include "Warrior.hpp"
#include "Priest.hpp"

Paladin::Paladin(const std::string &name, int level, const std::string weapon)
    : Character(name, level), Warrior(name, level, weapon), Priest(name, level)
{
    _strength = 9;
    _stamina = 10;
    _intelligence = 10;
    _spirit = 10;
    _agility = 2;
    _class = "Paladin";
    _race = "Human";
    std::cout << "the light falls on " << _name << std::endl;
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}