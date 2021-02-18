/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Carrier.hpp
*/

#ifndef CPP_D08_2018_CARRIER_HPP_
# define CPP_D08_2018_CARRIER_HPP_

# include <string>
# include "Droid.hpp"

class Carrier{
public:
    // Ctor and Dtor
    Carrier(const std::string = "");
    ~Carrier();

    // Member functions
    const std::string &getId() const { return (_id); }
    size_t getEnergy() const { return (_energy); }
    size_t getAttack() const { return (_attack); }
    size_t getToughness() const { return (_toughness); }
    size_t getSpeed() const { return (_speed); }
    size_t getNbDroids() const { return (_nbDroids); }

    Carrier &operator<<(Droid *&);
    Carrier &operator>>(Droid *&);
    Droid *&operator[](const size_t &);
    Droid *operator[](const size_t &) const;
    Carrier &operator~();
    bool operator()(const int &, const int &);
    Carrier &operator<<(size_t &);

private:
    void updateSpeed();
    // Properties
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    size_t _speed;
    size_t _nbDroids;
    Droid *_droids[5];
    int _x;
    int _y;
};

std::ostream &operator<<(std::ostream &stream, const Carrier &carrier);

#endif /* CPP_D08_2018_CARRIER_HPP_ */
