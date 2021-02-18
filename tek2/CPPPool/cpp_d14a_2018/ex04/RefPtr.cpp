/*
** EPITECH PROJECT, 2018
** cpp_d14a_2018
** File description:
** RefPtr.cpp
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{}

RefPtr::RefPtr(RefPtr const &other) : _rawPtr(nullptr)
{
    _rawPtr = other.get();
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    _rawPtr = other.get();
    return (*this);
}

RefPtr::~RefPtr()
{}

BaseComponent *RefPtr::get() const
{
    return (_rawPtr);
}