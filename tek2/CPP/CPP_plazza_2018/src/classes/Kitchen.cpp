/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Kitchen.cpp
*/

#include <unistd.h>
#include <iostream>
#include "Kitchen.hpp"

Kitchen::Kitchen(int id, double time_pizza, int nb_cooks, int time_restock)
    : _server(id + 1), _client(id), _nb_cooks(nb_cooks), _cooks(), _stock()
{
    std::cout << "CTOR kitchen " << id << std::endl;
    _cooks.reserve(nb_cooks);
    for (unsigned int i = 0; i < _nb_cooks; i++)
        _cooks.push_back(CookPtr(new Cook(time_pizza)));
    _stock.reset(new Stock(time_restock));
    if (_client.sendMessage(1))
        listen();
    std::cout << "END kitchen " << id << std::endl;
}

void Kitchen::listen()
{
    int end = 0;

    std::cout << "kitchen start listening " << _server.getEncriptionKey() << std::endl;
    while (end == 0) {
        auto res = _server.getMessage();
        if (res == 1) {
            end = 1;
            _server.respond(1);
        } else if (res > 2) {
            std::cout << "Received command " << res << std::endl;
            _server.respond(1);
        }

    }
}

std::deque<Serialization::SerialNumber> Kitchen::checkCommands()
{
    return std::deque<Serialization::SerialNumber>();
};

bool Kitchen::isActive() const
{
    return false;
}