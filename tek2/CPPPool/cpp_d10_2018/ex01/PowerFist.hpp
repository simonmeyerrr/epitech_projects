/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** PowerFist.hpp
*/

#ifndef CPP_D10_2018_POWERFIST_HPP_
# define CPP_D10_2018_POWERFIST_HPP_

# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
    PowerFist();
    ~PowerFist();

    void attack() const final;
};

#endif /* CPP_D10_2018_POWERFIST_HPP_ */
