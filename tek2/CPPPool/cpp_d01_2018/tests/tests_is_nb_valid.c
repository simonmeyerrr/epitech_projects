/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** tests_is_nb_valid.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "tests.h"

Test(is_nb_valid, valid)
{
    cr_assert_eq(1, is_nb_valid("0"));
    cr_assert_eq(1, is_nb_valid("010"));
    cr_assert_eq(1, is_nb_valid("653643"));
}

Test(is_nb_valid, invalid)
{
    cr_assert_eq(0, is_nb_valid(NULL));
    cr_assert_eq(0, is_nb_valid(""));
    cr_assert_eq(0, is_nb_valid("+-+--"));
    cr_assert_eq(0, is_nb_valid("767457 "));
    cr_assert_eq(0, is_nb_valid("764e753"));
}
