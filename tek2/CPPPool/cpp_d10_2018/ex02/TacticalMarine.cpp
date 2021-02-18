/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** TacticalMarine.cpp
*/

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine *TacticalMarine::clone() const
{
    return (new TacticalMarine);
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}