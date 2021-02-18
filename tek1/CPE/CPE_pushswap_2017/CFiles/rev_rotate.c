/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** put the first element at the end of a list
*/

#include "../include/my.h"

void rev_rotate_a(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_a == NULL || ptrs->begin_a == ptrs->end_a)
		return;
	tmp = ptrs->end_a->prev;
	ptrs->end_a->prev = NULL;
	ptrs->end_a->next = ptrs->begin_a;
	ptrs->begin_a->prev = ptrs->end_a;
	tmp->next = NULL;
	ptrs->begin_a = ptrs->end_a;
	ptrs->end_a = tmp;
}

void rev_rotate_b(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_b == NULL || ptrs->begin_b == ptrs->end_b)
		return;
	tmp = ptrs->end_b->prev;
	ptrs->end_b->prev = NULL;
	ptrs->end_b->next = ptrs->begin_b;
	ptrs->begin_b->prev = ptrs->end_b;
	tmp->next = NULL;
	ptrs->begin_b = ptrs->end_b;
	ptrs->end_b = tmp;
}

void rev_rotate_c(my_ptrs_t* ptrs)
{
	rev_rotate_a(ptrs);
	rev_rotate_b(ptrs);
}
