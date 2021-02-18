/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** tests_my_pow.c
*/

#include <criterion/criterion.h>
#include "tests.h"

Test(my_pow, zero)
{
    cr_assert_eq(1, my_pow(0, 0));
    cr_assert_eq(0, my_pow(0, 4));
    cr_assert_eq(1, my_pow(453, 0));
    cr_assert_eq(1, my_pow(-6536, 0));
}

Test(my_pow, pos)
{
    cr_assert_eq(1, my_pow(1, 654));
    cr_assert_eq(25, my_pow(5, 2));
    cr_assert_eq(27, my_pow(3, 3));
}

Test(my_pow, neg)
{
    cr_assert_eq(-1, my_pow(-1, 1));
    cr_assert_eq(1, my_pow(1, 2));
    cr_assert_eq(-64, my_pow(-4, 3));
    cr_assert_eq(16, my_pow(-4, 2));
}