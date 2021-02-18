/*
** EPITECH PROJECT, 2017
** my_apply_on_nodes.c
** File description:
** apply a fonction on list
*/

#include <stdio.h>
#include "include/mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
	linked_list_t *tmp = begin;

	while (tmp != NULL) {
		(*f)(tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
