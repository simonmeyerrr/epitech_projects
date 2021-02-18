/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Sorcerer.hpp
*/

#ifndef CPP_D10_2018_SORCERER_HPP_
# define CPP_D10_2018_SORCERER_HPP_

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer {
public:
    Sorcerer(std::string, std::string);
    ~Sorcerer();

    std::string getName() const { return (_name); }
    std::string getTitle() const { return (_title); }
    void polymorph(const Victim &) const;

private:
    std::string _name;
    std::string _title;
};

std::ostream &operator<<(std::ostream &, const Sorcerer &);

#endif /* CPP_D10_2018_SORCERER_HPP_ */
