/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _list(nullptr)
{}

int FruitBox::nbFruits() const
{
    auto tmp = _list;
    int count = 0;

    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    return (count);
}

bool FruitBox::putFruit(Fruit *fruit)
{
    if (!fruit || nbFruits() >= _size || listContain(fruit))
        return (false);

    if (!_list) {
        _list = new FruitNode(fruit, nullptr, nullptr);
        return (true);
    }

    auto tmp = _list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new FruitNode(fruit, tmp, nullptr);
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *fruit;
    auto tmp = _list;

    if (!tmp)
        return (nullptr);
    fruit = tmp->fruit;
    if (!tmp->next) {
        delete tmp;
        _list = nullptr;
        return (fruit);
    } else {
        _list = tmp->next;
        delete tmp;
        return (fruit);
    }
}

FruitNode *FruitBox::head() const
{
    return (_list);
}

bool FruitBox::listContain(Fruit *fruit) const
{
    auto tmp = _list;

    while (tmp) {
        if (tmp->fruit == fruit)
            return (true);
        tmp = tmp->next;
    }
    return (false);
}