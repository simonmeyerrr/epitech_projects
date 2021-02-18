/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** ISquad.hpp
*/

#ifndef CPP_D10_2018_ISQUAD_HPP_
# define CPP_D10_2018_ISQUAD_HPP_

#include "ISpaceMarine.hpp"

class ISquad {
public:
    virtual ~ISquad() {}

    virtual int getCount() const = 0;
    virtual ISpaceMarine *getUnit(int) = 0;
    virtual int push(ISpaceMarine *) = 0;
};

#endif /* CPP_D10_2018_ISQUAD_HPP_ */
