/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** swap the first to element of a list
*/

#include "../include/my.h"

void swap_a(my_ptrs_t* ptrs)
{
	my_list_t* tmp;
	int nb;

	if (ptrs->begin_a == NULL || ptrs->end_a == ptrs->begin_a)
		return;
	tmp = ptrs->begin_a->next;
	nb = ptrs->begin_a->nb;
	ptrs->begin_a->nb = tmp->nb;
	tmp->nb = nb;
}

void swap_b(my_ptrs_t* ptrs)
{
	my_list_t* tmp;
	int nb;

	if (ptrs->begin_b == NULL || ptrs->end_b == ptrs->begin_b)
		return;
	tmp = ptrs->begin_b->next;
	nb = ptrs->begin_b->nb;
	ptrs->begin_b->nb = tmp->nb;
	tmp->nb = nb;
}

void swap_c(my_ptrs_t* ptrs)
{
	swap_a(ptrs);
	swap_b(ptrs);
}
