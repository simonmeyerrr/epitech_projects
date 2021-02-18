/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** ManageMutex.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_MANAGEMUTEX_HPP
#define BOOTSTRAP_PLAZZA_MANAGEMUTEX_HPP

#include <pthread.h>
#include "IMutex.hpp"

class ManageMutex : public Imutex {

public:
    ~ManageMutex() override;
    ManageMutex();

    void lock() override;
    void unlock () override;
    void trylock () override;

private:
    pthread_mutex_t _safe;
};

#endif /*BOOTSTRAP_PLAZZA_MANAGEMUTEX_HPP*/
