/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** list_del.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "simple_list.h"

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (!tmp)
        return (FALSE);
    *front_ptr = tmp->next;
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (!tmp)
        return (FALSE);
    while (tmp->next && tmp->next->next) {
        tmp = tmp->next;
    }
    if (!tmp->next) {
        *front_ptr = NULL;
    } else {
        tmp->next = NULL;
    }
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = *front_ptr;

    if (position >= list_get_size(tmp)) {
        return (FALSE);
    } else if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    for (unsigned int i = 1; i < position; i++)
        tmp = tmp->next;
    tmp->next = tmp->next->next;
    return (TRUE);
}