/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** SafeQueue.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_SAFEQUEUE_HPP
#define BOOTSTRAP_PLAZZA_SAFEQUEUE_HPP

#include "ISafeQueue.hpp"

class SafeQueue : public ISafeQueue{
public:
    ~SafeQueue() override;
    SafeQueue();
    void push(int value) override;
    bool tryPop(int &value) override;
private:
};

#endif /* BOOTSTRAP_PLAZZA_SAFEQUEUE_HPP */
