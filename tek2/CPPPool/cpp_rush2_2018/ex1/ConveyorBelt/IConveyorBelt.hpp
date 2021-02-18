/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** IConveyorBelt.hpp
*/

#ifndef CPP_RUSH2_2018_ICONVEYORBELT_HPP_
# define CPP_RUSH2_2018_ICONVEYORBELT_HPP_

# include "../Object/Object.hpp"

class IConveyorBelt {
public:
    virtual ~IConveyorBelt() {}

    virtual void say(const std::string &) const = 0;

    virtual bool in(Object::Types) = 0;
    virtual bool out() = 0;

    virtual bool put(Object *) = 0;
    virtual Object *take() = 0;

    virtual bool isObjectOn() const = 0;
    virtual const Object *getOnConv() const = 0;
};

IConveyorBelt *createConveyorBelt();
IConveyorBelt *createConveyorBeltRand();

#endif /* CPP_RUSH2_2018_ICONVEYORBELT_HPP_ */
