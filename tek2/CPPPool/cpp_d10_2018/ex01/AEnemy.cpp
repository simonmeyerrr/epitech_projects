/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** AEnemy.cpp
*/

#include <string>
#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) :_hp(hp), _type(type)
{}

AEnemy::~AEnemy()
{}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0)
        _hp -= damage;
}