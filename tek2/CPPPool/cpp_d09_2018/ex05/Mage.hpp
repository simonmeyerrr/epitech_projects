/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Mage.hpp
*/

#ifndef CPP_D09_2018_MAGE_HPP_
# define CPP_D09_2018_MAGE_HPP_

# include <string>
# include "Character.hpp"

class Mage : virtual public Character {
public:
    // Ctor and Dtor
    Mage(const std::string &name, int level);

    // Member functions
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
};

#endif /* CPP_D09_2018_MAGE_HPP_ */
