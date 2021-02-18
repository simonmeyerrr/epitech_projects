/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** ISpaceMarine.hpp
*/

#ifndef CPP_D10_2018_ISPACEMARINE_HPP_
# define CPP_D10_2018_ISPACEMARINE_HPP_

class ISpaceMarine {
public:
    virtual ~ISpaceMarine() {}

    virtual ISpaceMarine *clone() const = 0;
    virtual void battleCry() const = 0;
    virtual void rangedAttack() const = 0;
    virtual void meleeAttack() const = 0;
};

#endif /* CPP_D10_2018_ISPACEMARINE_HPP_ */
