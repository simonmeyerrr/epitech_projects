/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Woody.hpp
*/

#ifndef CPP_D13_2018_WOODY_HPP_
# define CPP_D13_2018_WOODY_HPP_

#include <string>
#include "Toy.hpp"

class Woody : public Toy{
public:
    Woody(const std::string &name, const std::string &file = "woody.txt");
    ~Woody();

    void speak(const std::string &statement) const;
};

#endif /* CPP_D13_2018_WOODY_HPP_ */
