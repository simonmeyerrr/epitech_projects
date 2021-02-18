/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Box.hpp
*/

#ifndef CPP_RUSH2_2018_BOX_HPP_
# define CPP_RUSH2_2018_BOX_HPP_

# include "Wrap.hpp"

class Box : public Wrap {
public:
    Box(const std::string & = "");
    Box(Object *);
    ~Box();

    void say(const std::string &) const;
    std::string describe() const;

    bool wrapMeThat(Object *);
    Object *takeObject();

    const Object *getObject() const;
};

#endif /* CPP_RUSH2_2018_BOX_HPP_ */
