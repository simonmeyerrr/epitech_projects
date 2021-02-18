/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** TacticalMarine.hpp
*/

#ifndef CPP_D10_2018_TACTICALMARINE_HPP_
# define CPP_D10_2018_TACTICALMARINE_HPP_

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
    TacticalMarine();
    ~TacticalMarine();

    ISpaceMarine *clone() const override;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif /* CPP_D10_2018_TACTICALMARINE_HPP_ */
