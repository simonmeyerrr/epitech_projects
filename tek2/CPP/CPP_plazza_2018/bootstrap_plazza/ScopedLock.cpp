/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** ScopedLock.cpp
*/

#include "ScopedLock.hpp"

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}

ScopedLock::ScopedLock(ManageMutex &mutex)
    : _mutex(mutex)
{
    _mutex.lock();
}
