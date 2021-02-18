/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** ManageMutex.cpp
*/

#include "ManageMutex.hpp"

ManageMutex::~ManageMutex()
{
}

ManageMutex::ManageMutex()
    : _safe(PTHREAD_MUTEX_INITIALIZER)
{
}

void ManageMutex::lock()
{
    pthread_mutex_lock(&_safe);
}

void ManageMutex::unlock()
{
    pthread_mutex_unlock(&_safe);
}

void ManageMutex::trylock()
{
    pthread_mutex_trylock(&_safe);
}
