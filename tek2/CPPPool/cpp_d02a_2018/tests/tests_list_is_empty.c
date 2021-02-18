/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_is_empty.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_is_empty, null)
{
    cr_assert_eq(TRUE, list_is_empty(NULL));
}

Test(list_is_empty, one)
{
    node_t elem1 = {0, NULL};

    cr_assert_eq(FALSE, list_is_empty(&elem1));
}