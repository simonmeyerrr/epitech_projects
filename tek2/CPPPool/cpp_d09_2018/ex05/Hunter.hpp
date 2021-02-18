/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Hunter.hpp
*/

#ifndef CPP_D09_2018_HUNTER_HPP_
# define CPP_D09_2018_HUNTER_HPP_

# include <string>
# include "Character.hpp"
# include "Warrior.hpp"

class Hunter : public Warrior {
public:
    // Ctor and Dtor
    Hunter(const std::string &name, int level, const std::string = "sword");
    ~Hunter();

    int RangeAttack();
    void RestorePower();
};

#endif /* CPP_D09_2018_HUNTER_HPP_ */
