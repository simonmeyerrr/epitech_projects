/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Settings.cpp
*/

#include "Settings.hpp"

Settings::~Settings()
{}

Settings::Settings(Types::DisplayMode type)
    : _displayMode(type), _launched(true)
{}

Settings::Settings(const Settings &other)
    : _displayMode(other._displayMode), _launched(true)
{}

Settings &Settings::operator=(const Settings &other)
{
    if (this == &other)
        return (*this);
    _displayMode = other._displayMode;
    _launched = other._launched;
    return (*this);
}

Types::DisplayMode Settings::getDisplayMode() const
{
    return (_displayMode);
}

void Settings::setDisplayMode(Types::DisplayMode mode)
{
    _displayMode = mode;
}

bool Settings::isLaunched() const
{
    return (_launched);
}

void Settings::closeProg()
{
    _launched = false;
}