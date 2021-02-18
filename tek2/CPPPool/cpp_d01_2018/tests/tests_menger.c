/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** tests_menger.c
*/

#include <criterion/criterion.h>
#include "tests.h"

Test(menger, bad_level, .init = redirect_all_std)
{
    menger(9, 0);
    menger(9, -1);
    menger(9, -57476);
    cr_assert(1);
}

Test(menger, normal, .init = redirect_all_std)
{
    menger(9, 1);
    menger(9, 2);
    cr_assert(1);
}
