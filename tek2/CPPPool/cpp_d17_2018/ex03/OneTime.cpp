/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** OneTime.cpp
*/

#include "OneTime.hpp"

OneTime::~OneTime()
{}

OneTime::OneTime(const std::string &key) :_key(key), _offset(0)
{
    _max = _key.size();
    for (unsigned int i = 0; i < _max; i++) {
        if (_key[i] >= 'a' && _key[i] <= 'z') {
            _key[i] -= 'a';
        } else if (_key[i] >= 'A' && _key[i] <= 'Z') {
            _key[i] -= 'A';
        } else {
            _key[i] = -1;
        }
    }
}

OneTime::OneTime(const OneTime &other)
    : _key(other._key), _offset(other._offset), _max(other._max)
{}

OneTime &OneTime::operator=(const OneTime &other)
{
    if (this == &other)
        return (*this);
    _key = other._key;
    _offset = other._offset;
    _max = other._max;
    return (*this);
}

void OneTime::encryptChar(char plainchar)
{
    if (_max == 0)
        return;
    if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'a';
        if (_key[_offset] >= 0)
            plainchar += _key[_offset];
        plainchar = plainchar % 26;
        plainchar += 'a';
    } else if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'A';
        if (_key[_offset] >= 0)
            plainchar += _key[_offset];
        plainchar = plainchar % 26;
        plainchar += 'A';
    }
    std::cout << plainchar;
    _offset++;
    if (_offset >= _max)
        _offset = 0;
}

void OneTime::decryptChar(char cipherchar)
{
    if (_max == 0)
        return;
    if (cipherchar >= 'a' && cipherchar <= 'z') {
        cipherchar -= 'a';
        if (_key[_offset] >= 0)
            cipherchar -= _key[_offset];
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar = cipherchar % 26;
        cipherchar += 'a';
    } else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        cipherchar -= 'A';
        if (_key[_offset] >= 0)
            cipherchar -= _key[_offset];
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar = cipherchar % 26;
        cipherchar += 'A';
    }
    std::cout << cipherchar;
    _offset++;
    if (_offset >= _max)
        _offset = 0;
}

void OneTime::reset()
{
    _offset = 0;
}