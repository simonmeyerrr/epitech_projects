/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"

Cesar::~Cesar()
{}

Cesar::Cesar() : _decalage(3)
{}

Cesar::Cesar(const Cesar &other) : _decalage(other._decalage)
{}

Cesar &Cesar::operator=(const Cesar &other)
{
    if (this == &other)
        return (*this);
    _decalage = other._decalage;
    return (*this);
}

void Cesar::encryptChar(char plainchar)
{
    if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'a';
        plainchar += _decalage;
        plainchar = plainchar % 26;
        plainchar += 'a';
    } else if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'A';
        plainchar += _decalage;
        plainchar = plainchar % 26;
        plainchar += 'A';
    }
    std::cout << plainchar;
    _decalage++;
    if (_decalage > 25)
        _decalage = 0;
}

void Cesar::decryptChar(char cipherchar)
{
    if (cipherchar >= 'a' && cipherchar <= 'z') {
        cipherchar -= 'a';
        cipherchar -= _decalage;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar = cipherchar % 26;
        cipherchar += 'a';
    } else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        cipherchar -= 'A';
        cipherchar -= _decalage;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar = cipherchar % 26;
        cipherchar += 'A';
    }
    std::cout << cipherchar;
    _decalage++;
    if (_decalage > 25)
        _decalage = 0;
}

void Cesar::reset()
{
    _decalage = 3;
}