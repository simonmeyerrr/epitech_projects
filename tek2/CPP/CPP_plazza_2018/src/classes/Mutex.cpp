/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Mutex.cpp
*/

#include "Mutex.hpp"

Mutex::~Mutex()
{
}

Mutex::Mutex()
{
}

void Mutex::lock()
{
    _mutex.lock();
}

void Mutex::unlock()
{
    _mutex.unlock();
}

void Mutex::trylock()
{
    _mutex.try_lock();
}

