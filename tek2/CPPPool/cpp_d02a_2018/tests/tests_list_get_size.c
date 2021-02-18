/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_get_size.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_get_size, null)
{
    cr_assert_eq(0, list_get_size(NULL));
}

Test(list_get_size, one)
{
    node_t elem1 = {0, NULL};

    cr_assert_eq(1, list_get_size(&elem1));
}

Test(list_get_size, four)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};

    cr_assert_eq(4, list_get_size(&elem1));
}