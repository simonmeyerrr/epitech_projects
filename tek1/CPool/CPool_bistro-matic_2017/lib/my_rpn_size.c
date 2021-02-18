/*
** EPITECH PROJECT, 2017
** my_rpn_size.c
** File description:
** return the number of element in rpn
*/

#include "../include/all.h"

int my_rpn_size(rpn_t *begin)
{
	int nb = 0;
	rpn_t *tmp = begin;

	while (tmp != NULL) {
		tmp = tmp->next;
		nb++;
	}
	return (nb);
}
