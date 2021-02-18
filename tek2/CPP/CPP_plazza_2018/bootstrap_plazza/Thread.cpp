/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** Thread.cpp
*/

#include <pthread.h>
#include "Thread.hpp"

Thread::~Thread()
{
    if (!_join)
        pthread_join(_thre, nullptr);
}

Thread::Thread(void *(*start_routine) (void *), void *arg)
    : _join(false)
{
    pthread_create(&_thre, nullptr, start_routine, arg);
}

void Thread::join()
{
    _join = true;
    pthread_join(_thre, nullptr);
}
