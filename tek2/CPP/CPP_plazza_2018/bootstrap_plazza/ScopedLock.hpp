/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** ScopedLock.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_SCOPEDLOCK_HPP
#define BOOTSTRAP_PLAZZA_SCOPEDLOCK_HPP

#include "ManageMutex.hpp"

class ScopedLock {

public:
    ~ScopedLock();
    ScopedLock(ManageMutex &);

private:
    ManageMutex &_mutex;
};

#endif /* BOOTSTRAP_PLAZZA_SCOPEDLOCK_HPP */
