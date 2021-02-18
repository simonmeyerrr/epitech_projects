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
    Fruit *fruit = nullptr;

    while (unsorted.head() && unsorted.head()->fruit != first) {
        fruit = unsorted.pickFruit();
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
    }
    if (fruit)
        unsorted.putFruit(fruit);
}

FruitBox *const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    int len = 0;

    while (coconuts[len])
        len++;

    FruitBox **boxes = new FruitBox *[(len / 6) + 2];
    for (int i = 0; i < (len / 6) + 2; i++)
        boxes[i] = nullptr;

    int j = -1;
    for (int i = 0; i < len; i++) {
        if (i % 6 == 0) {
            j++;
            boxes[j] = new FruitBox(6);
        }
        Coconut *fruit =
            const_cast<Coconut *>(const_cast<const Coconut *>(coconuts[i]));
        boxes[j]->putFruit(fruit);
    }
    return (boxes);
}

void LittleHand::plugMixer(MixerBase &mixer)
{
    Mixer &mix = static_cast<Mixer &>(mixer);
    mix.plugMe();
}

void LittleHand::injectVitamin(Fruit &f, int quantity)
{
    f.setVitamins(quantity);
}