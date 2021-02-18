/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tests_add_str.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "mem_ptr.h"
#include "tests.h"

Test(add_str, normal)
{
    char *str1 = "Hey , ";
    char *str2 = "it works!";
    char *res;

    add_str(str1, str2, &res);
    cr_assert_str_eq(res, "Hey , it works!");
}

Test(add_str, null)
{
    char *str1 = "Hey , ";
    char *str2 = "it works!";
    char *res1;
    char *res2;

    add_str(str1, NULL, &res1);
    add_str(NULL, str2, &res2);
    cr_assert_str_eq(res1, "Hey , ");
    cr_assert_str_eq(res2, "it works!");
}