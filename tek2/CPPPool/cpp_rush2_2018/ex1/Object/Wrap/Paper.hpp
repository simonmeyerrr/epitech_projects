/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Paper.hpp
*/

#ifndef CPP_RUSH2_2018_PAPER_HPP_
# define CPP_RUSH2_2018_PAPER_HPP_

# include "Wrap.hpp"

class Paper : public Wrap {
public:
    Paper(const std::string & = "");
    Paper(Object *);
    ~Paper();

    void say(const std::string &) const;
    std::string describe() const;

    bool wrapMeThat(Object *);
    Object *takeObject();

    const Object *getObject() const;
};

#endif /* CPP_RUSH2_2018_PAPER_HPP_ */
