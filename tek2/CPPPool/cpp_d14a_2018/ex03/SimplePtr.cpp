/*
** EPITECH PROJECT, 2018
** cpp_d14a_2018
** File description:
** SimplePtr.cpp
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{}

SimplePtr::~SimplePtr()
{
    if (_rawPtr)
        delete _rawPtr;
}

BaseComponent *SimplePtr::get() const
{
    return (_rawPtr);
}

SimplePtr::SimplePtr(SimplePtr const &other) : _rawPtr(nullptr)
{
    (void)other;
}

SimplePtr &SimplePtr::operator=(SimplePtr const &other)
{
    (void)other;
    return (*this);
}