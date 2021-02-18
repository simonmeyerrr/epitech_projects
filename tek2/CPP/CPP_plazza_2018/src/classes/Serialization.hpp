/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Serialization.hpp
*/

#ifndef CPP_PLAZZA_2018_SERIALIZATION_HPP
# define CPP_PLAZZA_2018_SERIALIZATION_HPP

#include <tuple>
#include "Pizza.hpp"

class Serialization {
public:
    using SerialNumber = unsigned int;

    static SerialNumber pack(short command_id, PizzaType type, PizzaSize size);
    static std::tuple<short, PizzaType, PizzaSize> unpack(SerialNumber nb);
};

#endif /* CPP_PLAZZA_2018_SERIALIZATION_HPP */
