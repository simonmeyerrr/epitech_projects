/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ConveyorBeltRand.hpp
*/

#ifndef CPP_RUSH2_2018_CONVEYORBELTRAND_HPP_
# define CPP_RUSH2_2018_CONVEYORBELTRAND_HPP_

# include "IConveyorBelt.hpp"

class ConveyorBeltRand : public IConveyorBelt {
public:
    ConveyorBeltRand();
    ~ConveyorBeltRand();

    void say(const std::string &) const;

    bool in(Object::Types);
    bool out();

    bool put(Object *);
    Object *take();

    bool isObjectOn() const;
    const Object *getOnConv() const;

private:
    Object *_obj;
};

#endif /* CPP_RUSH2_2018_CONVEYORBELTRAND_HPP_ */
