/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Toy.hpp
*/

#ifndef CPP_RUSH2_2018_TOY_HPP_
# define CPP_RUSH2_2018_TOY_HPP_

# include "../Object.hpp"

class Toy : public Object {
public:
    Toy(Object::Types, const std::string &);
    virtual ~Toy();

    int getObjectCount() const;

    void openMe();
    void closeMe();
    bool isOpen() const;
    bool wrapMeThat(Object *);
    Object *takeObject();

    const Object *getObject() const;
};

#endif /* CPP_RUSH2_2018_TOY_HPP_ */
