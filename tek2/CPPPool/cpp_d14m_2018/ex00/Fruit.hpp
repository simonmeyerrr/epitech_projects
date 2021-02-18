/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Fruit.hpp
*/

#ifndef CPP_D14M_2018_FRUIT_HPP_
# define CPP_D14M_2018_FRUIT_HPP_

# include <string>

class Fruit {
public:
    ~Fruit() = default;
    Fruit(const std::string &, int);
    Fruit(const Fruit &);

    std::string getName() const;
    int getVitamins() const;

    Fruit &operator=(const Fruit &);

private:
    std::string _name;
    int _vitamins;
};

#endif /* CPP_D14M_2018_FRUIT_HPP_ */
