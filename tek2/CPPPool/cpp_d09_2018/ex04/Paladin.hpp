/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Paladin.hpp
*/

#ifndef CPP_D09_2018_PALADIN_HPP_
# define CPP_D09_2018_PALADIN_HPP_

# include <string>
# include "Character.hpp"
# include "Warrior.hpp"
# include "Priest.hpp"

class Paladin : public Warrior, public Priest {
public:
    // Ctor and Dtor
    Paladin(const std::string &name, int level, const std::string = "hammer");

    // Member functions

    using Warrior::CloseAttack;
    using Priest::Heal;
    using Priest::RangeAttack;
    using Warrior::RestorePower;
    int Intercept();
};

#endif /* CPP_D09_2018_PALADIN_HPP_ */
