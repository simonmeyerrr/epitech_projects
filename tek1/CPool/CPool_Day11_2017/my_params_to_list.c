/*
** EPITECH PROJECT, 2017
** my_params_to_list
** File description:
** create a linked list with arguments
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/mylist.h"

void add_params(struct linked_list **list, int i, char const **av)
{
	struct linked_list *element;

	element = malloc(sizeof(*element));
	element->data = av[i];
	element->next = *list;
	*list = element;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
	struct linked_list *list;
	list = NULL;
	for (int i = 0 ; i < ac ; i++)
		add_params(&list, i, av);
	return (list);
}
