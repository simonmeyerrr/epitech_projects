/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Victim.hpp
*/

#ifndef CPP_D10_2018_VICTIM_HPP_
# define CPP_D10_2018_VICTIM_HPP_

# include <iostream>
# include <string>

class Victim {
public:
    Victim(std::string);
    ~Victim();

    std::string getName() const { return (_name); }
    virtual void getPolymorphed() const;

protected:
    std::string _name;
};

std::ostream &operator<<(std::ostream &, const Victim &);

#endif /* CPP_D10_2018_VICTIM_HPP_ */
