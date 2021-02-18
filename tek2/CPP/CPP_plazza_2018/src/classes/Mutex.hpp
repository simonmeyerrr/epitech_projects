/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Mutex.hpp
*/

#ifndef CPP_PLAZZA_2018_MUTEX_HPP
#define CPP_PLAZZA_2018_MUTEX_HPP

#include <mutex>

class Mutex{
public:
    ~Mutex();
    Mutex();

    void lock();
    void unlock();
    void trylock();

private:
    std::mutex _mutex;
};

#endif /* CPP_PLAZZA_2018_MUTEX_HPP */
