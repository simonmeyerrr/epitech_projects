/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Priest.hpp
*/

#ifndef CPP_D09_2018_PRIEST_HPP_
# define CPP_D09_2018_PRIEST_HPP_

# include <string>
# include "Character.hpp"
# include "Mage.hpp"

class Priest : public Mage {
public:
    // Ctor and Dtor
    Priest(const std::string &name, int level);

    // Member functions
    int CloseAttack();
    void Heal();
    using Mage::RangeAttack;
    using Mage::RestorePower;
};

#endif /* CPP_D09_2018_PRIEST_HPP_ */
