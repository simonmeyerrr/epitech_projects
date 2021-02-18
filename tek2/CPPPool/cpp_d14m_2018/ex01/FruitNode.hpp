/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** FruitNode.hpp
*/

#ifndef CPP_D14M_2018_FRUITNODE_HPP_
# define CPP_D14M_2018_FRUITNODE_HPP_

# include "Fruit.hpp"

class FruitNode {
public:
    FruitNode(Fruit *newFruit = nullptr, FruitNode *newPrev = nullptr,
        FruitNode *newNext = nullptr)
        : fruit(newFruit), prev(newPrev), next(newNext)
    {}

    ~FruitNode()
    {
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
    }

    Fruit *fruit;
    FruitNode *prev;
    FruitNode *next;
};

#endif /* CPP_D14M_2018_FRUITNODE_HPP_ */
