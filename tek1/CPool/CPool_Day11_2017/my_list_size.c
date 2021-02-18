/*
** EPITECH PROJECT, 2017
** my_list_size.c
** File description:
** return the number of elements of a list
*/

#include "include/mylist.h"
#include <stdio.h>

int my_list_size(linked_list_t const *begin)
{
	int nb;

	while (begin != NULL) {
		begin = begin->next;
		nb++;
	}
	return (nb / 2);
}
