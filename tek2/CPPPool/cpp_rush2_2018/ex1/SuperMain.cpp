/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** SuperMain.cpp
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

void testObjects(void)
{
    std::cout << "[!] tests objects" << std::endl;
    Object *paper = new Paper;
    Object *box = new Box;
    Object *toy = new Teddy;

    std::cout << *paper << std::endl << *box << std::endl << *toy << std::endl;
    paper->wrapMeThat(box);
    paper->wrapMeThat(toy);
    box->wrapMeThat(paper);
    box->wrapMeThat(toy);
    paper->wrapMeThat(box);
    std::cout << *paper << std::endl;
    paper->takeObject();
    paper->openMe();
    paper->takeObject();
    box->openMe();
    box->takeObject();
    delete paper;
}

void testTable(void)
{
    std::cout << std::endl << "[!] tests table" << std::endl;
    IElf *elf = new Elf;
    ITable *table = createTable();
    ITable *tableRand = createTableRand();

    elf->look(*table);
    elf->look(*tableRand);

    Object *paper1 = new Paper;
    Object *box1 = new Box;
    box1->wrapMeThat(new Teddy);
    paper1->wrapMeThat(box1);
    tableRand->setObjAtPos(paper1, 2);

    Object *paper2 = new Paper;
    Object *box2 = new Box;
    box2->wrapMeThat(new Teddy);
    paper2->wrapMeThat(box2);
    tableRand->setObjAtPos(paper2, 3);

    elf->look(*tableRand);

    delete elf;
    delete table;
    delete tableRand;
}

void testConv(void)
{
    std::cout << std::endl << "[!] tests conv" << std::endl;
    IElf *elf = new Elf;
    IConveyorBelt *conv = createConveyorBelt();
    IConveyorBelt *convRand = createConveyorBeltRand();

    elf->look(*conv);
    elf->look(*convRand);

    elf->in(*conv, Object::BOX);
    elf->in(*conv, Object::BOX);
    elf->in(*convRand, Object::BOX);
    delete convRand->take();
    elf->in(*convRand, Object::BOX);
    elf->out(*convRand);

    conv->put(new Teddy);
    elf->take(*conv);
    elf->put(*convRand);
    elf->out(*convRand);

    delete elf;
    delete conv;
    delete convRand;
}

int main(void)
{
    testObjects();
    testTable();
    testConv();
}