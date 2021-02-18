/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_get_elem_at_position.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_get_elem_at_position, null)
{
    cr_assert_eq(0, list_get_elem_at_position(NULL, 0));
    cr_assert_eq(0, list_get_elem_at_position(NULL, 1));
    cr_assert_eq(0, list_get_elem_at_position(NULL, 5));
}

Test(list_get_elem_at_position, one)
{
    node_t elem1 = {5, NULL};

    cr_assert_eq(5, list_get_elem_at_position(&elem1, 0));
    cr_assert_eq(0, list_get_elem_at_position(&elem1, 1));
    cr_assert_eq(0, list_get_elem_at_position(&elem1, 5));
}

Test(list_get_elem_at_position, four)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {13, &elem2};

    cr_assert_eq(13, list_get_elem_at_position(&elem1, 0));
    cr_assert_eq(7, list_get_elem_at_position(&elem1, 1));
    cr_assert_eq(8, list_get_elem_at_position(&elem1, 2));
    cr_assert_eq(3, list_get_elem_at_position(&elem1, 3));
    cr_assert_eq(0, list_get_elem_at_position(&elem1, 4));
}