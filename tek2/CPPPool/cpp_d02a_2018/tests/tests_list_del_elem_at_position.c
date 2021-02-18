/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_del_elem_at_position.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_del_elem_at_position, bad_pos)
{
    list_t begin1 = NULL;
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin2 = &elem1;

    cr_assert_eq(FALSE, list_del_elem_at_position(&begin1, 0));
    cr_assert_null(begin1);
    cr_assert_eq(FALSE, list_del_elem_at_position(&begin1, 1));
    cr_assert_null(begin1);
    cr_assert_eq(FALSE, list_del_elem_at_position(&begin1, 5));
    cr_assert_null(begin1);
    cr_assert_eq(FALSE, list_del_elem_at_position(&begin2, 4));
    cr_assert_not_null(begin2);
    cr_assert_eq(FALSE, list_del_elem_at_position(&begin2, 5));
    cr_assert_not_null(begin2);
}

Test(list_del_elem_at_position, mid)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_del_elem_at_position(&begin, 1));
    cr_assert_eq(TRUE, list_del_elem_at_position(&begin, 1));
    cr_assert_null(begin->next->next);
    cr_assert_eq(begin->value, 0);
    cr_assert_eq(begin->next->value, 3);
}

Test(list_del_elem_at_position, limits)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_del_elem_at_position(&begin, 3));
    cr_assert_eq(TRUE, list_del_elem_at_position(&begin, 0));
    cr_assert_null(begin->next->next);
    cr_assert_eq(begin->value, 7);
    cr_assert_eq(begin->next->value, 8);
}