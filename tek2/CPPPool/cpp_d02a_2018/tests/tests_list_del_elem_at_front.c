/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_del_elem_at_front.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"

Test(list_del_elem_at_front, begin_null)
{
    list_t begin = NULL;

    cr_assert_eq(FALSE, list_del_elem_at_front(&begin));
    cr_assert_null(begin);
}

Test(list_del_elem_at_front, one)
{
    node_t elem1 = {3, NULL};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_del_elem_at_front(&begin));
    cr_assert_null(begin);
}

Test(list_del_elem_at_front, normal)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};
    list_t begin = &elem1;

    cr_assert_eq(TRUE, list_del_elem_at_front(&begin));
    cr_assert_null(begin->next->next->next);
    cr_assert_eq(begin->value, 7);
    cr_assert_eq(begin->next->value, 8);
    cr_assert_eq(begin->next->next->value, 3);
}