/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tests_my_strlen.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "mem_ptr.h"
#include "tests.h"

Test(my_strlen, normal)
{
    cr_assert_eq(my_strlen("a"), 1);
    cr_assert_eq(my_strlen("abcd"), 4);
    cr_assert_eq(my_strlen("ab cd"), 5);
}

Test(my_strlen, empty_null)
{
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(NULL), 0);
}