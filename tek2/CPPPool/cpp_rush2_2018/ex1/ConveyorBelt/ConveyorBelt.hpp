/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ConveyorBelt.hpp
*/

#ifndef CPP_RUSH2_2018_CONVEYORBELT_HPP_
# define CPP_RUSH2_2018_CONVEYORBELT_HPP_

# include "IConveyorBelt.hpp"

class ConveyorBelt : public IConveyorBelt {
public:
    ConveyorBelt();
    ~ConveyorBelt();

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

#endif /* CPP_RUSH2_2018_CONVEYORBELT_HPP_ */
