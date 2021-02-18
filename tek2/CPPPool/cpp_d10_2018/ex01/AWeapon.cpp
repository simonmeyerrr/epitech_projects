/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** AWeapon.cpp
*/

#include <string>
#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name),
    _cost(apcost), _damage(damage)
{}

AWeapon::~AWeapon()
{}