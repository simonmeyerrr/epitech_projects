/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_add_elem_at_position.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_add_elem_at_position, begin_null)
{
    list_t begin = NULL;

    cr_assert_eq(TRUE, list_add_elem_at_position(&begin, 1, 0));
    cr_assert_not_null(begin);
    cr_assert_null(begin->next);
    cr_assert_eq(begin->value, 1);
}

Test(list_add_elem_at_position, bad_pos)
{
    list_t begin1 = NULL;
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin2 = &elem1;

    cr_assert_eq(FALSE, list_add_elem_at_position(&begin1, 1, 1));
    cr_assert_null(begin1);
    cr_assert_eq(FALSE, list_add_elem_at_position(&begin2, 1, 5));
}

Test(list_add_elem_at_position, mid)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_add_elem_at_position(&begin, 11, 2));
    cr_assert_null(begin->next->next->next->next->next);
    cr_assert_eq(begin->value, 0);
    cr_assert_eq(begin->next->value, 7);
    cr_assert_eq(begin->next->next->value, 11);
    cr_assert_eq(begin->next->next->next->value, 8);
    cr_assert_eq(begin->next->next->next->next->value, 3);
}

Test(list_add_elem_at_position, limit_end)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_add_elem_at_position(&begin, 15, 4));
    cr_assert_null(begin->next->next->next->next->next);
    cr_assert_eq(begin->value, 0);
    cr_assert_eq(begin->next->value, 7);
    cr_assert_eq(begin->next->next->value, 8);
    cr_assert_eq(begin->next->next->next->value, 3);
    cr_assert_eq(begin->next->next->next->next->value, 15);
}