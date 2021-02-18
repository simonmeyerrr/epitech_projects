/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** KreogCom.cpp
*/

#include <iostream>
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial, KreogCom *link)
    : _x(x), _y(y), m_serial(serial), _link(link), _prev(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (_prev)
        _prev->_link = _link;
    if (_link)
        _link->_prev = _prev;
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    auto *new_link = new KreogCom(x, y, serial, _link);

    new_link->_prev = this;
    if (_link)
        _link->_prev = new_link;
    _link = new_link;
}

void KreogCom::removeCom()
{
    if (_link)
        delete _link;
}

KreogCom *KreogCom::getCom() const
{
    return (_link);
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " <<
        _y << std::endl;
}

void KreogCom::locateSquadTwo() const
{
    this->ping();
    if (_link)
        _link->locateSquadTwo();
}

void KreogCom::locateSquad() const
{
    if (_link)
        _link->locateSquadTwo();
    this->ping();
}