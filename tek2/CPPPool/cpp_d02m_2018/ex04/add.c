/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** add.c
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    int a_bis = (a < 0) ? (-a) : (a);
    int b_bis = (b < 0) ? (-b) : (b);

    return (a_bis + b_bis);
}

void exec_add(addition_t *operation)
{
    int (*func[2])(int, int) = {normal_add, absolute_add};

    operation->add_op.res = func[operation->add_type](operation->add_op.a,
        operation->add_op.b);
}