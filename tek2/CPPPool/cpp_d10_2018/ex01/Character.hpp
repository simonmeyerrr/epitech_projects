/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Character.hpp
*/

#ifndef CPP_D10_2018_CHARACTER_HPP_
# define CPP_D10_2018_CHARACTER_HPP_

# include <string>
# include "AWeapon.hpp"
# include "AEnemy.hpp"

class Character {
public:
    Character(const std::string &);
    Character(const Character &);
    ~Character();

    void recoverAP();
    void equip(AWeapon *);
    void attack(AEnemy *);
    const std::string &getName() const {return (_name); }
    int getAp() const { return (_ap); }
    bool haveWeapon() const { return (_weapon != nullptr); }
    const AWeapon &getWeapon() const { return (*_weapon); }

private:
    std::string _name;
    int _ap;
    AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &stream, const Character &c);

#endif /* CPP_D10_2018_CHARACTER_HPP_ */
