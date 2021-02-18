/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** KoalaBot.cpp
*/

#include <iostream>
#include <string>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string const &serial)
    : _serial(serial)
{}

KoalaBot::~KoalaBot()
{}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    auto tmp = arms;
    arms = _arms;
    _arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    auto tmp = legs;
    legs = _legs;
    _legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    auto tmp = head;
    head = _head;
    _head = tmp;
}

bool KoalaBot::status() const
{
    return (_arms.isFunctional() && _legs.isFunctional() &&
        _head.isFunctional());
}