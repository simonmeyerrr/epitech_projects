/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Algo.hpp
*/

#ifndef CPP_RUSH2_2018_ALGO_HPP_
# define CPP_RUSH2_2018_ALGO_HPP_

#include "../ConveyorBelt/IConveyorBelt.hpp"
#include "../Object/Object.hpp"
#include "../Table/ITable.hpp"
#include "../Elf/IElf.hpp"

class Algo {
public:
    // Ctor and Dtor
    Algo(IConveyorBelt *conv, ITable *table, IElf *elf);
    ~Algo();

    void say(const std::string &) const;
    void getContents();
    bool doSomething();
    bool isThereAToy();
    bool containsAToy(const Object *);

    bool action1();
    bool action2();
    bool action3();
    bool action4();
    bool action5();
    bool action6();
    bool action7();
    bool action8();
    bool action9();
    bool action10();

private:
    IConveyorBelt *_conv;
    ITable *_table;
    IElf *_elf;

    Object const *_convContent;
    Object *const * _tableContent;
    Object const *_elfContent;
};

#endif /* CPP_RUSH2_2018_ALGO_HPP_ */
