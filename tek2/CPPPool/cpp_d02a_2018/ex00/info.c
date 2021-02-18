/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** info.c
*/

#include <stdio.h>
#include "simple_list.h"

unsigned int list_get_size(list_t list)
{
    list_t tmp = list;
    unsigned int length = 0;

    while (tmp) {
        length++;
        tmp = tmp->next;
    }
    return (length);
}

bool_t list_is_empty(list_t list)
{
    if (!list)
        return (TRUE);
    else
        return (FALSE);
}

void list_dump(list_t list)
{
    list_t tmp = list;

    while (tmp) {
        printf("%f\n", tmp->value);
        tmp = tmp->next;
    }
}