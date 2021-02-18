/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Main.cpp
*/

#include <random>
#include <iostream>
#include <string>
#include "Table/Table.hpp"
#include "Elf/Elf.hpp"
#include "Object/Object.hpp"
#include "Object/Toy/Teddy.hpp"
#include "Object/Wrap/Paper.hpp"
#include "Object/Wrap/Box.hpp"
#include "ConveyorBelt/ConveyorBeltRand.hpp"
#include "Algo/Algo.hpp"

int main(void)
{
    srandom(2);
    IElf *elf = new Elf;
    IConveyorBelt *conv = createConveyorBeltRand();
    ITable *table = createTableRand();
    Algo algo(conv, table, elf);
    return (0);
}