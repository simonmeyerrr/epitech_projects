/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ITable.cpp
*/

#include <random>
#include "../Object/Wrap/Box.hpp"
#include "../Object/Wrap/Paper.hpp"
#include "../Object/Toy/Teddy.hpp"
#include "../Object/Toy/LittlePony.hpp"
#include "TableRand.hpp"
#include "Table.hpp"

ITable *createTable()
{
    ITable *table = new Table;

    table->setObjAtPos(new Teddy, 0);
    table->setObjAtPos(new LittlePony, 1);
    return (table);
}

static Object *giveRandObj()
{
    if (random() % 2 == 0) {
        if (random() % 2 == 0)
            return (new Teddy);
        else
            return (new LittlePony);
    } else {
        if (random() % 2 == 0)
            return (new Paper);
        else
            return (new Box);
    }
}

static Object *generateRandObj()
{
    if (random() % 2 == 0)
        return (nullptr);
    else
        return (giveRandObj());
}

ITable *createTableRand()
{
    ITable *table = new TableRand;
    for (int i = 0 ; i < 10 ; i++)
        table->setObjAtPos(generateRandObj(), i);
    return (table);
}