/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Lemon.hpp
*/

#ifndef CPP_D14M_2018_LEMON_HPP_
# define CPP_D14M_2018_LEMON_HPP_

# include "Fruit.hpp"

class Lemon : public Fruit {
public:
    Lemon();
    ~Lemon() = default;

    virtual std::string getName() const;
};

#endif /* CPP_D14M_2018_LEMON_HPP_ */
