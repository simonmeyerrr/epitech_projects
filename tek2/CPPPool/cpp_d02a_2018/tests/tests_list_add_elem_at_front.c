/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_add_elem_at_front.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_add_elem_at_front, begin_null)
{
    list_t begin = NULL;

    cr_assert_eq(TRUE, list_add_elem_at_front(&begin, 1));
    cr_assert_not_null(begin);
    cr_assert_null(begin->next);
    cr_assert_eq(begin->value, 1);
}

Test(list_add_elem_at_front, one)
{
    node_t elem1 = {3, NULL};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_add_elem_at_front(&begin, 1));
    cr_assert_null(begin->next->next);
    cr_assert_eq(begin->value, 1);
    cr_assert_eq(begin->next->value, 3);
}

Test(list_add_elem_at_front, normal)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_add_elem_at_front(&begin, 1));
    cr_assert_null(begin->next->next->next->next->next);
    cr_assert_eq(begin->value, 1);
    cr_assert_eq(begin->next->value, 0);
    cr_assert_eq(begin->next->next->value, 7);
    cr_assert_eq(begin->next->next->next->value, 8);
    cr_assert_eq(begin->next->next->next->next->value, 3);
}