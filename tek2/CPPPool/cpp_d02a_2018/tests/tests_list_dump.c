/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** tests_list_dump.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "simple_list.h"
#include "tests.h"

Test(list_dump, null, .init = redirect_all_std)
{
    list_dump(NULL);
}

Test(list_dump, one, .init = redirect_all_std)
{
    node_t elem1 = {0, NULL};

    list_dump(&elem1);
}

Test(list_dump, four, .init = redirect_all_std)
{
    node_t elem4 = {3, NULL};
    node_t elem3 = {8, &elem4};
    node_t elem2 = {7, &elem3};
    node_t elem1 = {0, &elem2};

    list_dump(&elem1);
}