/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** Skat.cpp
*/

#include <iostream>
#include <string>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
    : _name(name), _stimPaks(stimPaks)
{}

Skat::~Skat()
{}

int &Skat::stimPaks()
{
    return (this->_stimPaks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        this->_stimPaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimPaks -= 1;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status() const
{
    std::cout << "Soldier " << this->_name << " reporting " <<
        this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}