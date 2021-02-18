/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
    FruitBox &bananas, FruitBox &limes)
{
    Fruit *first = nullptr;
    Fruit *fruit = unsorted.pickFruit();

    while (fruit != first) {
        if (dynamic_cast<Lime *>(fruit)) {
            if (!limes.putFruit(fruit)) {
                unsorted.putFruit(fruit);
                if (first == nullptr)
                    first = fruit;
            }
        } else if (dynamic_cast<Banana *>(fruit)) {
            if (!bananas.putFruit(fruit)) {
                unsorted.putFruit(fruit);
                if (first == nullptr)
                    first = fruit;
            }
        } else if (dynamic_cast<Lemon *>(fruit)) {
            if (!lemons.putFruit(fruit)) {
                unsorted.putFruit(fruit);
                if (first == nullptr)
                    first = fruit;
            }
        } else {
            unsorted.putFruit(fruit);
            if (first == nullptr)
                first = fruit;
        }
        fruit = unsorted.pickFruit();
    }
    if (fruit)
        unsorted.putFruit(fruit);
}