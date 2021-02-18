/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Peon.hpp
*/

#ifndef CPP_D10_2018_PEON_HPP_
# define CPP_D10_2018_PEON_HPP_

# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(std::string);
    ~Peon();

    void getPolymorphed() const;
};

#endif /* CPP_D10_2018_PEON_HPP_ */
