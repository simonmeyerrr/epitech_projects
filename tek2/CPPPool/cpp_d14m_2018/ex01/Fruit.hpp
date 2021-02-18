/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Fruit.hpp
*/

#ifndef CPP_D14M_2018_FRUIT_HPP_
# define CPP_D14M_2018_FRUIT_HPP_

# include <string>

class Fruit {
public:
    virtual ~Fruit();

    virtual std::string getName() const = 0;
    int getVitamins() const;

protected:
    int _vitamins;
};

#endif /* CPP_D14M_2018_FRUIT_HPP_ */
