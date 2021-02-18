/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** tests_my_strlen.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "string.h"

Test(my_strlen, null)
{
    cr_assert_eq(0, my_strlen(NULL));
}

Test(my_strlen, empty)
{
    cr_assert_eq(0, my_strlen(""));
}

Test(my_strlen, normal)
{
    cr_assert_eq(1, my_strlen("a"));
    cr_assert_eq(14, my_strlen("I love Epitech"));
    cr_assert_eq(25, my_strlen("This unit tests are great"));
}