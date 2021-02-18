/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** list_get.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_front(list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

double list_get_elem_at_back(list_t list)
{
    if (!list)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    if (position >= list_get_size(list))
        return (0);
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    while (list && list->value != value)
        list = list->next;
    return (list);
}