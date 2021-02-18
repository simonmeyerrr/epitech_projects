/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** PlasmaRifle.hpp
*/

#ifndef CPP_D10_2018_PLASMARIFLE_HPP_
# define CPP_D10_2018_PLASMARIFLE_HPP_

# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
    PlasmaRifle();
    ~PlasmaRifle();

    void attack() const final;
};

#endif /* CPP_D10_2018_PLASMARIFLE_HPP_ */
