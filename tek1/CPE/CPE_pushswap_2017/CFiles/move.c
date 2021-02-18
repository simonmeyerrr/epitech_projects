/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** move the first to element of a list to the other one
*/

#include "../include/my.h"

void move_a_to_b(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_a == NULL)
		return;
	tmp = ptrs->begin_a->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	ptrs->begin_a->next = ptrs->begin_b;
	if (ptrs->begin_b != NULL)
		ptrs->begin_b->prev = ptrs->begin_a;
	ptrs->begin_b = ptrs->begin_a;
	ptrs->begin_a = tmp;
	if (tmp == NULL)
		ptrs->end_a = NULL;
	if (ptrs->end_b == NULL)
		ptrs->end_b = ptrs->begin_b;
}

void move_b_to_a(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_b == NULL)
		return;
	tmp = ptrs->begin_b->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	ptrs->begin_b->next = ptrs->begin_a;
	if (ptrs->begin_a != NULL)
		ptrs->begin_a->prev = ptrs->begin_b;
	ptrs->begin_a = ptrs->begin_b;
	ptrs->begin_b = tmp;
	if (tmp == NULL)
		ptrs->end_b = NULL;
	if (ptrs->end_a == NULL)
		ptrs->end_a = ptrs->begin_a;
}
