/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Kitchen.hpp
*/

#ifndef CPP_PLAZZA_2018_KITCHEN_HPP
# define CPP_PLAZZA_2018_KITCHEN_HPP

#include <deque>
#include <vector>
#include "Cook.hpp"
#include "Stock.hpp"
#include "Serialization.hpp"
#include "MsgQServer.hpp"
#include "MsgQClient.hpp"

class Kitchen {
public:
    ~Kitchen() = default;
    Kitchen(int id, double time_pizza, int
    nb_cooks, int time_restock);

    void listen();
    std::deque<Serialization::SerialNumber> checkCommands();
    bool isActive() const;

private:
    MsgQServer _server;
    MsgQClient _client;
    unsigned int _nb_cooks;
    std::vector<CookPtr> _cooks;
    StockPtr _stock;
};

#endif /* CPP_PLAZZA_2018_KITCHEN_HPP */
