/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tests_add_str_struct.c
*/


#include <criterion/criterion.h>
#include <stdlib.h>
#include "mem_ptr.h"
#include "tests.h"

Test(add_str_struct, normal)
{
    char *str1 = "Hey , ";
    char *str2 = "it works!";
    str_op_t str_op;

    str_op.str1 = str1;
    str_op.str2 = str2;
    add_str_struct(&str_op);
    cr_assert_str_eq(str_op.res, "Hey , it works!");
}

Test(add_str_struct, null)
{
    char *str1 = "Hey , ";
    char *str2 = "it works!";
    str_op_t str_op1;
    str_op_t str_op2;

    str_op1.str1 = str1;
    str_op1.str2 = NULL;
    str_op2.str1 = NULL;
    str_op2.str2 = str2;
    add_str_struct(&str_op1);
    add_str_struct(&str_op2);
    cr_assert_str_eq(str_op1.res, "Hey , ");
    cr_assert_str_eq(str_op2.res, "it works!");
}