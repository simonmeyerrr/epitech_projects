/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** tests_my_get_nbr.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "tests.h"

Test(my_get_nbr, zero)
{
    cr_assert_eq(0, my_get_nbr("0"));
}

Test(my_get_nbr, pos)
{
    cr_assert_eq(1, my_get_nbr("1"));
}

Test(my_get_nbr, max_min)
{
    cr_assert_eq(2147483647, my_get_nbr("2147483647"));
}

Test(my_get_nbr, special)
{
    cr_assert_eq(0, my_get_nbr(NULL));
    cr_assert_eq(0, my_get_nbr(""));
}