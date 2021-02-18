/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** FruitBox.hpp
*/

#ifndef CPP_D14M_2018_FRUITBOX_HPP_
# define CPP_D14M_2018_FRUITBOX_HPP_

# include "FruitNode.hpp"

class FruitBox {
public:
    FruitBox(int);
    ~FruitBox() = default;

    int nbFruits() const;
    bool putFruit(Fruit *);
    Fruit *pickFruit();
    FruitNode *head();

private:
    bool listContain(Fruit *) const;

    int _size;
    FruitNode *_list;
};

#endif /* CPP_D14M_2018_FRUITBOX_HPP_ */
