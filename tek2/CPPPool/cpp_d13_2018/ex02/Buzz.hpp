/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Buzz.hpp
*/

#ifndef CPP_D13_2018_BUZZ_HPP_
# define CPP_D13_2018_BUZZ_HPP_

#include <string>
#include "Toy.hpp"

class Buzz : public Toy{
public:
    Buzz(const std::string &name, const std::string &file = "buzz.txt");
    ~Buzz();
};

#endif /* CPP_D13_2018_BUZZ_HPP_ */
