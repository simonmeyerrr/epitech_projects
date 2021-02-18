/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Teddy.hpp
*/

#ifndef CPP_RUSH2_2018_TEDDY_HPP_
# define CPP_RUSH2_2018_TEDDY_HPP_

# include "Toy.hpp"

class Teddy : public Toy {
public:
    Teddy(const std::string & = "cuddles");
    ~Teddy();

    void say(const std::string &) const;
    std::string describe() const;

    void isTaken() const final;
};

#endif /* CPP_RUSH2_2018_TEDDY_HPP_ */
