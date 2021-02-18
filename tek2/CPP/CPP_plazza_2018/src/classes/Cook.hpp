/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Cook.hpp
*/

#ifndef CPP_PLAZZA_2018_COOK_HPP
# define CPP_PLAZZA_2018_COOK_HPP

#include <deque>
#include <memory>
#include "Serialization.hpp"

class Cook {
public:
    ~Cook() = default;
    Cook(double time_pizza);

    std::deque<Serialization::SerialNumber> checkCommands();
    bool takeCommand(Serialization::SerialNumber);
    bool isActive() const;

private:
    double _time_pizza;

    std::deque<Serialization::SerialNumber> _ready;
    Serialization::SerialNumber _doing;
    bool _working;
};

using CookPtr = std::unique_ptr<Cook>;

#endif /* CPP_PLAZZA_2018_COOK_HPP */
