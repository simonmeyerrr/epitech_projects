/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Reception.cpp
*/

#include <unistd.h>
#include <thread>
#include "Reception.hpp"

Reception::~Reception()
{
    _stop = true;
    for (unsigned int i = 0; i < _threads.size(); i++)
        _threads[i].join();
}

Reception::Reception(double time_pizza, int nb_cooks, int time_restock)
    : _time_pizza(time_pizza), _nb_cooks(nb_cooks), _time_restock(time_restock),
    _command_id(1), _connection_id(1), _stop(false), _mutex()
{
}

void Reception::nothing() const
{}

void Reception::order(const std::string &order)
{
    auto pizzas = Pizza::parsePizzas(order);
    int nb = 0;
    short id = 0;

    for (unsigned int i = 0; i < pizzas.size(); i++) {
        nb += std::get<2>(pizzas[i]);
    }
    _mutex.lock();
    id = _command_id;
    _commands[id] = pizzas.size();
    _command_id++;
    if (_command_id == 0)
        _command_id = 1;
    _mutex.unlock();

    for (unsigned int i = 0; i < pizzas.size(); i++) {
        auto pizza = Serialization::pack(id, std::get<0>(pizzas[0]),
            std::get<1>(pizzas[i]));
        for (int j = 0; j < std::get<2>(pizzas[i]); j++) {
            std::cout << "pizza " << pizza << std::endl;
            sendPizza(pizza);
        }
    }
}

void Reception::sendPizza(Serialization::SerialNumber pizza)
{
    _mutex.lock();
    for (unsigned int i = 0; i < _ipcs.size(); i++) {
        auto res = std::get<1>(_ipcs[i]).sendMessage(pizza);
        if (res == 1) {
            _mutex.unlock();
            return;
        }
    }
    _mutex.unlock();
    std::thread thread(&Reception::createKitchen, this, pizza);
    thread.detach();
}

void Reception::createKitchen(Serialization::SerialNumber pizza)
{
    _mutex.lock();
    int id = _connection_id;
    _connection_id += 4;
    _mutex.unlock();
    std::cout << "fork" << std::endl;
    pid_t child_pid = fork();

    if (child_pid == 0) {
        Kitchen(id, _time_pizza, _nb_cooks, _time_restock);
    } else if (child_pid > 0) {
        _mutex.lock();
        _ipcs.push_back(
            std::tuple<int, MsgQClient, bool>(id, MsgQClient(id + 1), false));
        _threads.push_back(
            std::thread(&Reception::listenKitchen, this, id, pizza));
        _mutex.unlock();
    }
}

void Reception::listenKitchen(int id, Serialization::SerialNumber pizza)
{
    (void)pizza;
    MsgQServer server(id);

    int ok = 0;
    unsigned int place = 0;
    for (unsigned int i = 0; i < _ipcs.size(); i++) {
        if (std::get<0>(_ipcs[i]) == id) {
            place = i;
            break;
        }
    }
    std::tuple<int, MsgQClient, bool> &info = _ipcs[place];
    while (!_stop) {
        _mutex.lock();
        if (std::get<2>(info))
            return;
        _mutex.unlock();
        auto res = server.getMessage();
        if (res == 1 && ok == 0) {
            ok = 1;
            server.respond(1);
        } else if (res > 2) {
            std::cout << "pizza ready " << res << std::endl;
            server.respond(1);
        }
        if (ok == 1 && std::get<1>(info).sendMessage(pizza)) {
            ok = 2;
        }
    }
    std::get<1>(info).sendMessage(1);
}