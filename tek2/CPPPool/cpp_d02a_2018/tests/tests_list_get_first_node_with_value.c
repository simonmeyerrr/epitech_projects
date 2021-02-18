/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_get_first_node_with_value.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_get_first_node_with_value, null)
{
    cr_assert_null(list_get_first_node_with_value(NULL, 0));
    cr_assert_null(list_get_first_node_with_value(NULL, 1));
    cr_assert_null(list_get_first_node_with_value(NULL, 5));
}

Test(list_get_first_node_with_value, one)
{
    node_t elem1 = {5, NULL};

    cr_assert_null(list_get_first_node_with_value(&elem1, 0));
    cr_assert_null(list_get_first_node_with_value(&elem1, 1));
    cr_assert_eq(&elem1, list_get_first_node_with_value(&elem1, 5));
}

Test(list_get_first_node_with_value, four)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {3, &elem3};
    node_t elem1 = {13, &elem2};

    cr_assert_null(list_get_first_node_with_value(&elem1, 0));
    cr_assert_null(list_get_first_node_with_value(&elem1, 5));
    cr_assert_eq(&elem1, list_get_first_node_with_value(&elem1, 13));
    cr_assert_eq(&elem2, list_get_first_node_with_value(&elem1, 3));
    cr_assert_eq(&elem3, list_get_first_node_with_value(&elem1, 8));
}