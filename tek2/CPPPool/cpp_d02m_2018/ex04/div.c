/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    float a_bis = a;
    float b_bis = b;

    if (b_bis == 0)
        return (0);
    return (a_bis / b_bis);
}

void exec_div(division_t *operation)
{
    integer_op_t *integer;
    decimale_op_t *decimale;

    if (operation->div_type == INTEGER) {
        integer = operation->div_op;
        integer->res = integer_div(integer->a, integer->b);
    } else {
        decimale = operation->div_op;
        decimale->res = decimale_div(decimale->a, decimale->b);
    }
}