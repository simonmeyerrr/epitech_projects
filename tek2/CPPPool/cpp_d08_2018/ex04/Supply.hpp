/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Supply.hpp
*/

#ifndef CPP_D08_2018_SUPPLY_HPP_
# define CPP_D08_2018_SUPPLY_HPP_

# include <string>
# include "Droid.hpp"

class Supply{
public:
    enum Types {
        Iron = 1,
        Silicon = 2,
        Wreck = 3
    };
    // Ctor and Dtor
    Supply(Types, size_t, Droid** = nullptr);
    ~Supply();

    Droid *&operator*();
    Droid *&operator->();
    Supply &operator++();
    Supply &operator--();
    Supply &operator!();
    bool operator==(const Supply &) const;
    bool operator!=(const Supply &) const;
    operator size_t() const;

    // Member functions
    Types getType() const { return(_type); }
    size_t getAmount() const { return(_amount); }
    Droid **getWrecks() const { return(_wrecks); }

private:
    // Properties
    Types _type;
    size_t _amount;
    Droid **_wrecks;

};

std::ostream &operator<<(std::ostream &, const Supply &);

#endif /* CPP_D08_2018_SUPPLY_HPP_ */
