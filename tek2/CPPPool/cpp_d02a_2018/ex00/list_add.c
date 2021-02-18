/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** list_add.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (FALSE);
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t tmp = *front_ptr;
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (FALSE);
    new_node->value = elem;
    new_node->next = NULL;
    while (tmp && tmp->next)
        tmp = tmp->next;
    if (tmp) {
        tmp->next = new_node;
    } else {
        *front_ptr = new_node;
    }
    return (TRUE);
}

bool_t list_add_elem_at_position(list_t *front_ptr, double elem,
unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (FALSE);
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    new_node->value = elem;
    new_node->next = NULL;
    while (tmp && --position)
        tmp = tmp->next;
    if (position)
        return (FALSE);
    new_node->next = tmp->next;
    tmp->next = new_node;
    return (TRUE);
}