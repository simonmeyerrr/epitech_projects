/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** AWeapon.hpp
*/

#ifndef CPP_D10_2018_AWEAPON_HPP_
# define CPP_D10_2018_AWEAPON_HPP_

# include <string>

class AWeapon {
public:
    AWeapon(const std::string &name, int apcost, int damage);
    virtual ~AWeapon();

    const std::string &getName() const { return (_name); }
    int getAPCost() const { return (_cost); }
    int getDamage() const { return (_damage); }

    virtual void attack() const = 0;
private:
    std::string _name;
    int _cost;
    int _damage;
};

#endif /* CPP_D10_2018_AWEAPON_HPP_ */
