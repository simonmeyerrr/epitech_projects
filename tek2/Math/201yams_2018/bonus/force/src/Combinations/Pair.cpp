/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Pair.cpp
*/

#include <stdio.h>
#include <iostream>
#include "Pair.hpp"

Pair::Pair(int value): _value(value), _total(0), _success(0)
{}

void Pair::compute(int *dices)
{
    (void)dices;
    int objective[] = {0, 0, 0, 0, 0, 0};
    int count = 0;

    objective[_value - 1] = 2;
    _success = getCases(objective);
    for (int i = 0; i < 5; i++) {
        if (dices[i] == _value && count < 2)
            count++;
    }
    objective[_value - 1] = count;
    _total = getCases(objective);
}

void Pair::dump() const
{
    std::cout << "chances to get a " << _value << " pair-of-a-kind: ";
    if (_total > 0) {
        long double result = (((long double)_success) / ((long double)_total)
            ) * (long double)100.0;
        printf("%.2Lf%%\n", result);
    } else
        std::cout << "0.00%\n" << std::endl;
}
