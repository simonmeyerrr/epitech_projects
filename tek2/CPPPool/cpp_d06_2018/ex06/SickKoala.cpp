/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** SickKoala.cpp
*/

#include <algorithm>
#include <iostream>
#include <string>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
    : _name(name), _sick(true)
{}

void SickKoala::say(std::string message)
{
    std::cout << "Mr." << this->_name << ": " << message << std::endl;
}

SickKoala::~SickKoala()
{
    this->say("Kreooogg!! I'm cuuuured!");
}

void SickKoala::poke()
{
    this->say("Gooeeeeerrk!!");
}

bool SickKoala::takeDrug(std::string drug)
{
    this->_sick = false;
    if (drug == "Buronzand") {
        this->say("And you'll sleep right away!");
        return (true);
    }

    std::transform(drug.begin(), drug.end(), drug.begin(), ::tolower);
    if (drug == "mars") {
        this->say("Mars, and it kreogs!");
        return (true);
    }

    this->say("Goerkreog!");
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    size_t pos = str.find("Kreog!");

    while (pos != std::string::npos) {
        str.replace(pos, 6, "1337!");
        pos = str.find("Kreog!");
    }
    this->say(str);
}

std::string SickKoala::getName()
{
    return (this->_name);
};

bool SickKoala::isSick()
{
    return (this->_sick);
}