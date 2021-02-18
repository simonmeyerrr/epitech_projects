/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Ratatouille.hpp
*/

#ifndef CPP_D16_2018_RATATOUILLE_HPP_
# define CPP_D16_2018_RATATOUILLE_HPP_

# include <iostream>
# include <sstream>
# include <string>

class Ratatouille {
public:
    ~Ratatouille();
    Ratatouille();
    Ratatouille(const Ratatouille &);
    Ratatouille &operator=(const Ratatouille &);

    Ratatouille &addVegetable(unsigned char);
    Ratatouille &addCondiment(unsigned int);
    Ratatouille &addSpice(double);
    Ratatouille &addSauce(const std::string &);

    std::string kooc();

private:
    std::stringstream _s;
};

#endif /* CPP_D16_2018_RATATOUILLE_HPP_ */
