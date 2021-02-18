/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Mixer.cpp
*/

#include "Mixer.hpp"

Mixer::Mixer() : MixerBase()
{}

static int mixFunc(FruitBox &fruits)
{
    int vitamins = 0;
    Fruit *first = nullptr;
    Fruit *fruit = fruits.pickFruit();

    while (fruit && fruit != first) {
        vitamins += fruit->getVitamins();
        if (!first)
            first = fruit;
        fruits.putFruit(fruit);
        fruit = fruits.pickFruit();
    }
    fruits.putFruit(fruit);
    return (vitamins);
}

void Mixer::plugMe()
{
    _plugged = true;
    _mixfunc = &mixFunc;
}