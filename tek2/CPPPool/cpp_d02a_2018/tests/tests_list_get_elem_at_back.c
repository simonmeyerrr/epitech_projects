/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_get_elem_at_back.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_get_elem_at_back, null)
{
    cr_assert_eq(0, list_get_elem_at_back(NULL));
}

Test(list_get_elem_at_back, one)
{
    node_t elem1 = {5, NULL};

    cr_assert_eq(5, list_get_elem_at_back(&elem1));
}

Test(list_get_elem_at_back, four)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {13, &elem2};

    cr_assert_eq(3, list_get_elem_at_back(&elem1));
}