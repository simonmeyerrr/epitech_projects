/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tests_add_mul_2param.c
*/

#include <criterion/criterion.h>
#include "tests.h"

Test(add_mul_2param, normal)
{
    int first = 5;
    int second = 6;
    int add_res = first;
    int mul_res = second;

    add_mul_2param(&add_res, &mul_res);
    cr_assert_eq(add_res, 11);
    cr_assert_eq(mul_res, 30);
}