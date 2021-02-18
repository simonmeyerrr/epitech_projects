/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** Droid.hpp
*/

#ifndef CPP_D08_2018_DROID_HPP_
# define CPP_D08_2018_DROID_HPP_

#include <string>

class Droid {
public:
    // Ctor and Dtor
    Droid(std::string = "");
    Droid(const Droid &);
    ~Droid();

    // Member functions
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string getStatus() const;

    void setId(std::string);
    void setEnergy(size_t);
    void setStatus(std::string *);

    bool operator==(const Droid &) const;
    bool operator!=(const Droid &) const;
    void operator=(const Droid &);
    Droid &operator<<(size_t &);

private:
    // Properties
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
};

std::ostream &operator<<(std::ostream &stream, const Droid &droid);

#endif /* CPP_D08_2018_DROID_HPP_ */
