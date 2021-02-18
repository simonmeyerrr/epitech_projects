/*
** EPITECH PROJECT, 2018
** cpp_d10_2018
** File description:
** Squad.hpp
*/

#ifndef CPP_D10_2018_SQUAD_HPP_
# define CPP_D10_2018_SQUAD_HPP_

# include "ISpaceMarine.hpp"
# include "ISquad.hpp"

class Squad : public ISquad {
public:
    Squad();
    Squad(const Squad &);
    ~Squad();

    int getCount() const;
    ISpaceMarine *getUnit(int);
    int push(ISpaceMarine *);
    Squad &operator=(const Squad &other);

private:
    int _size;
    ISpaceMarine **_tab;
};

#endif /* CPP_D10_2018_SQUAD_HPP_ */
