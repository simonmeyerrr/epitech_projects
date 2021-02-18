/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** SuperMutant.hpp
*/

#ifndef CPP_D10_2018_SUPERMUTANT_HPP_
# define CPP_D10_2018_SUPERMUTANT_HPP_

# include <string>
# include "AEnemy.hpp"

class SuperMutant : public AEnemy {
public:
    SuperMutant();
    ~SuperMutant();

    void takeDamage(int) override;
};

#endif /* CPP_D10_2018_SUPERMUTANT_HPP_ */
