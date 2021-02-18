/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** main.cpp
*/

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include "IMutex.hpp"
#include "Thread.hpp"
#include "ScopedLock.hpp"

ManageMutex mutex = ManageMutex();

void incrementCounter(int &nb)
{
    ScopedLock scope = ScopedLock(mutex);
    for (int i =  0; i < 10; i++) {
        ++nb;
        printf("printError %d\n", nb);
        std::cout << nb << std::endl;
    }
}

int main()
{
    int nb = 2;
    Thread thre = Thread((void *(*)(void *))incrementCounter, &nb);
    Thread threp = Thread((void *(*)(void *))incrementCounter, &nb);
    thre.join();
    return 0;
}