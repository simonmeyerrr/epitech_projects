/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Stock.hpp
*/

#ifndef CPP_PLAZZA_2018_STOCK_HPP
# define CPP_PLAZZA_2018_STOCK_HPP

#include <thread>
#include <memory>
#include <chrono>
#include <ctime>
#include <map>
#include "Pizza.hpp"
#include "Mutex.hpp"

using Chrono_pt = std::chrono::time_point<std::chrono::system_clock>;

class Stock {
public:
    ~Stock();
    Stock(int time_restock);

    bool isPossible(Recipe recipe);
    void takeIngredients(Recipe recipe);

private:
    void restock();

    Chrono_pt _time;
    int _time_restock;
    std::map<int, unsigned short int> _stock;
    bool _stop;
    std::thread _thread;
    Mutex _mutex;
};

using StockPtr = std::unique_ptr<Stock>;

#endif /* CPP_PLAZZA_2018_STOCK_HPP */
