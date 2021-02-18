/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** Character.hpp
*/

#ifndef CPP_D09_2018_CHARACTER_HPP_
# define CPP_D09_2018_CHARACTER_HPP_

# include <string>

class Character {
public:

    enum AttackRange {
        CLOSE,
        RANGE
    };
    AttackRange Range;

    // Ctor and Dtor
    Character(const std::string &, int);

    // Member functions
    const std::string &getName() const { return (_name); }
    int getLvl() const { return (_lvl); }
    int getPv() const { return (_pv); }
    int getPower() const { return (_power); }
    int getStrength() const { return (_strength); }
    int getStamina() const { return (_stamina); }
    int getIntelligence() const { return (_intelligence); }
    int getSpirit() const { return (_spirit); }
    int getAgility() const { return (_agility); }
    const std::string &getRace() const { return (_race); }

    int CloseAttack();
    void Heal();
    int RangeAttack();
    void RestorePower();
    void TakeDamage(int);

private:
    bool useEnergy(int);
    void addPv(int);
    // Properties
    std::string _name;
    int _lvl;
    int _pv;
    int _power;
    int _strength;
    int _stamina;
    int _intelligence;
    int _spirit;
    int _agility;
    std::string _race;
};

#endif /* CPP_D09_2018_CHARACTER_HPP_ */
