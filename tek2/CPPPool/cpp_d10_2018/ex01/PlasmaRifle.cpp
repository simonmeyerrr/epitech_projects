/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** PlasmaRifle.cpp
*/

#include <iostream>
#include <string>
#include "PlasmaRifle.hpp"
#include "AWeapon.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{}

PlasmaRifle::~PlasmaRifle()
{}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}