/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Stock.cpp
*/

#include <iostream>
#include "Stock.hpp"

Stock::~Stock()
{
    _mutex.unlock();
    _stop = true;
    _thread.join();
}

Stock::Stock(int timeRestock)
    : _time_restock(timeRestock), _stop(false), _mutex()
{
    _time = std::chrono::system_clock::now();
    for (unsigned short int i = DOE; i < UNDEFINED_ING; i++)
        _stock[i] = 5;
    _thread = std::thread(&Stock::restock, this);
}

void Stock::restock()
{
    while (!_stop) {
        Chrono_pt now = std::chrono::system_clock::now();
        int tmp = std::chrono::duration_cast<std::chrono::milliseconds>(now -
            _time).count();
        if (tmp >= _time_restock) {
            _mutex.lock();
            for (auto i = _stock.begin(); i != _stock.end(); ++i)
                i->second = 5;
            _time = now;
            _mutex.unlock();
        }
    }
}

bool Stock::isPossible(Recipe recipe)
{
    Ingredients list(std::get<1>(recipe));

    _mutex.lock();
    for (auto i = list.begin(); i != list.end(); ++i) {
        if (_stock[*i] < 1) {
            _mutex.unlock();
            return (false);
        }
    }
    _mutex.unlock();
    return (true);
}

void Stock::takeIngredients(Recipe recipe)
{
    Ingredients list(std::get<1>(recipe));

    _mutex.lock();
    for (auto i = list.begin(); i != list.end(); ++i) {
            _stock[*i] -= 1;
    }
    _mutex.unlock();
}