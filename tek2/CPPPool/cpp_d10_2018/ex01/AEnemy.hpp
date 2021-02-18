/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** AEnemy.hpp
*/

#ifndef CPP_D10_2018_AENEMY_HPP_
# define CPP_D10_2018_AENEMY_HPP_

# include <string>

class AEnemy {
public:
    AEnemy(int, const std::string &);
    virtual ~AEnemy();

    virtual void takeDamage(int);
    const std::string &getType() const { return (_type); }
    int getHP() const { return (_hp); }

protected:
    int _hp;
    std::string _type;
};

#endif /* CPP_D10_2018_AENEMY_HPP_ */
