/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Squad.cpp
*/

#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad() : _size(0), _tab(nullptr)
{
}

Squad::Squad(const Squad &old) : _size(old.getCount()), _tab(nullptr)
{
    _tab = new ISpaceMarine *[_size];

    for (int i = 0; i < _size; i++)
        _tab[i] = old._tab[i]->clone();
}

Squad &Squad::operator=(const Squad &other)
{
    for (int i = 0; i < _size; i++)
        delete _tab[i];
    if (_tab)
        delete [] _tab;

    if (!other._tab) {
        _tab = nullptr;
        _size = 0;
        return (*this);
    }
    _tab = new ISpaceMarine *[other._size];
    for (int i = 0; i < other._size - 1; i++)
        _tab[i] = other._tab[i]->clone();
    _size = other._size;
    return (*this);
}

Squad::~Squad()
{
    for (int i = 0; i < _size; i++) {
        delete _tab[i];
    }
    if (_tab)
        delete [] _tab;
}

int Squad::getCount() const
{
    int new_size = 0;

    for (int i = 0; i < _size; i++)
        new_size = _tab[i] ? new_size + 1 : new_size;

    return (new_size);
}

ISpaceMarine *Squad::getUnit(int pos)
{
    if (pos < 0 || pos >= _size)
        return (nullptr);
    return (_tab[pos]);
}

int Squad::push(ISpaceMarine *marine)
{
    if (!marine)
        return (_size);
    for (int i = 0; i < _size; i++) {
        if (_tab[i] == marine)
            return (_size);
    }
    _size++;
    ISpaceMarine **new_tab = new ISpaceMarine *[_size];
    for (int i = 0; i < _size - 1; i++)
        new_tab[i] = _tab[i];
    new_tab[_size - 1] = marine;
    if (_tab)
        delete[] _tab;
    _tab = new_tab;
    return (_size);
}