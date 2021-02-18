/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Character.cpp
*/

#include <iostream>
#include <string>
#include "Character.hpp"
#include "AWeapon.hpp"
#include "AEnemy.hpp"

Character::Character(const std::string &name) : _name(name), _ap(40),
    _weapon(nullptr)
{
}

Character::Character(const Character &c) : _name(c.getName()), _ap(c.getAp()),
    _weapon(c._weapon)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
    if (_ap + 10 > 40)
        _ap = 40;
    else
        _ap += 10;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (!_weapon || !enemy || _ap < _weapon->getAPCost())
        return;
    std::cout << _name << " attacks " << enemy->getType() << " with a "
        << _weapon->getName() << std::endl;
    _weapon->attack();
    _ap -= _weapon->getAPCost();
    enemy->takeDamage(_weapon->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::ostream &operator<<(std::ostream &stream, const Character &c)
{
    if (c.haveWeapon()) {
        stream << c.getName() << " has " << c.getAp() << " AP and wields a "
            << c.getWeapon().getName() << std::endl;
    } else {
        stream << c.getName() << " has " << c.getAp() << " AP and is unarmed"
            << std::endl;
    }
    return (stream);
}