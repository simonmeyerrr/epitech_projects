/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Warrior.hpp
*/

#ifndef CPP_D09_2018_WARRIOR_HPP_
# define CPP_D09_2018_WARRIOR_HPP_

# include <string>
# include "Character.hpp"

class Warrior : virtual public Character {
public:
    // Ctor and Dtor
    Warrior(const std::string &name, int level, const std::string = "hammer");

    // Member functions
    const std::string &getWeapon() const { return (_weapon); }

    int CloseAttack();
    int RangeAttack();

private:
    // Properties
    std::string _weapon;
};

#endif /* CPP_D09_2018_WARRIOR_HPP_ */
