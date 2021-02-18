/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** AssaultTerminator.hpp
*/

#ifndef CPP_D10_2018_ASSAULTTERMINATOR_HPP_
# define CPP_D10_2018_ASSAULTTERMINATOR_HPP_

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
public:
    AssaultTerminator();
    ~AssaultTerminator();

    ISpaceMarine *clone() const override;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif /* CPP_D10_2018_ASSAULTTERMINATOR_HPP_ */
