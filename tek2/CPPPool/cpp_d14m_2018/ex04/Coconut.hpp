/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Coconut.hpp
*/

#ifndef CPP_D14M_2018_COCONUT_HPP_
# define CPP_D14M_2018_COCONUT_HPP_

# include "Fruit.hpp"

class Coconut : public Fruit {
public:
    Coconut();
    ~Coconut() = default;

    std::string getName() const;
};

#endif /* CPP_D14M_2018_COCONUT_HPP_ */
