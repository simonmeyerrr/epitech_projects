/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tests_add_mul_4param.c
*/

#include <criterion/criterion.h>
#include "tests.h"

Test(add_mul_4param, normal)
{
    int first = 5;
    int second = 6;
    int sum;
    int product;

    add_mul_4param(first, second, &sum, &product);
    cr_assert_eq(sum, 11);
    cr_assert_eq(product, 30);
}