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
    FruitNode(Fruit *fruit, FruitNode *prev, FruitNode *next)
        : _fruit(fruit), _prev(prev), _next(next)
    {}

    ~FruitNode()
    {
        if (_prev)
            _prev->_next = _next;
        if (_next)
            _next->_prev = _prev;
    }

    Fruit *getFruit() { return (_fruit); }
    FruitNode *getPrev() { return (_prev); }
    FruitNode *getNext() { return (_next); }

    void setPrev(FruitNode *prev) { _prev = prev; }
    void setNext(FruitNode *next) { _next = next; }

private:
    Fruit *_fruit;
    FruitNode *_prev;
    FruitNode *_next;
};

#endif /* CPP_D14M_2018_FRUITNODE_HPP_ */
