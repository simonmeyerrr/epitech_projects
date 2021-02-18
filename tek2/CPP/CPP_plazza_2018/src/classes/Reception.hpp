/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Reception.hpp
*/

#ifndef CPP_PLAZZA_2018_RECEPTION_HPP
# define CPP_PLAZZA_2018_RECEPTION_HPP

#include <unordered_map>
#include <deque>
#include <string>
#include "Serialization.hpp"
#include "Kitchen.hpp"

class Reception {
public:
    ~Reception();
    Reception(double time_pizza, int nb_cooks, int time_restock);

    void nothing() const;
    void order(const std::string &order);

    void createKitchen(Serialization::SerialNumber pizza);

    void listenKitchen(int id, Serialization::SerialNumber pizza);

private:
    void sendPizza(Serialization::SerialNumber pizza);

    double _time_pizza;
    int _nb_cooks;
    int _time_restock;

    short _command_id;
    int _connection_id;

    std::deque<std::tuple<int, MsgQClient, bool>> _ipcs;
    std::deque<std::thread> _threads;
    std::deque<Serialization::SerialNumber> _ready;
    std::unordered_map<short, unsigned int> _commands;

    bool _stop;
    Mutex _mutex;
};

#endif /* CPP_PLAZZA_2018_RECEPTION_HPP */
