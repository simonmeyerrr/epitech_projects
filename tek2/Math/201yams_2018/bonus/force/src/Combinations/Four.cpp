/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Four.cpp
*/

#include <stdio.h>
#include <iostream>
#include "Four.hpp"

Four::Four(int value): _value(value), _total(0), _success(0)
{}

void Four::compute(int *dices)
{
    (void)dices;
    int objective[] = {0, 0, 0, 0, 0, 0};
    int count = 0;

    objective[_value - 1] = 4;
    _success = getCases(objective);
    for (int i = 0; i < 5; i++) {
        if (dices[i] == _value && count < 4)
            count++;
    }
    objective[_value - 1] = count;
    _total = getCases(objective);
}

void Four::dump() const
{
    std::cout << "chances to get a " << _value << " four-of-a-kind: ";
    if (_total > 0) {
        long double result = (((long double)_success) / ((long double)_total)
            ) * (long double)100.0;
        printf("%.2Lf%%\n", result);
    } else
        std::cout << "0.00%\n" << std::endl;
}