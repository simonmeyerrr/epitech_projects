/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** Encryption.cpp
*/

#include "Encryption.hpp"

Encryption::~Encryption()
{}

Encryption::Encryption(IEncryptionMethod &method,
    void (IEncryptionMethod::*func)(char)) : _method(method), _func(func)
{}

Encryption::Encryption(const Encryption &other)
    : _method(other._method), _func(other._func)
{}

Encryption &Encryption::operator=(const Encryption &other)
{
    if (this == &other)
        return (*this);
    _method = other._method;
    _func = other._func;
    return (*this);
}

void Encryption::operator()(char c)
{
    (_method.*_func)(c);
}

void Encryption::encryptString(IEncryptionMethod &method,
    const std::string &toEncrypt)
{
    method.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(method, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &method,
    const std::string &toDecrypt)
{
    method.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(method, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}