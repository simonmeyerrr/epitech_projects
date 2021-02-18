/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_get_elem_at_front.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_get_elem_at_front, null)
{
    cr_assert_eq(0, list_get_elem_at_front(NULL));
}

Test(list_get_elem_at_front, one)
{
    node_t elem1 = {5, NULL};

    cr_assert_eq(5, list_get_elem_at_front(&elem1));
}

Test(list_get_elem_at_front, four)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {13, &elem2};

    cr_assert_eq(13, list_get_elem_at_front(&elem1));
}