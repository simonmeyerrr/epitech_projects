/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** put the first element at the end of a list
*/

#include "../include/my.h"

void rotate_a(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_a == NULL || ptrs->begin_a == ptrs->end_a)
		return;
	tmp = ptrs->begin_a->next;
	ptrs->begin_a->next = NULL;
	ptrs->begin_a->prev = ptrs->end_a;
	ptrs->end_a->next = ptrs->begin_a;
	tmp->prev = NULL;
	ptrs->end_a = ptrs->begin_a;
	ptrs->begin_a = tmp;
}

void rotate_b(my_ptrs_t* ptrs)
{
	my_list_t* tmp;

	if (ptrs->begin_b == NULL || ptrs->begin_b == ptrs->end_b)
		return;
	tmp = ptrs->begin_b->next;
	ptrs->begin_b->next = NULL;
	ptrs->begin_b->prev = ptrs->end_b;
	ptrs->end_b->next = ptrs->begin_b;
	tmp->prev = NULL;
	ptrs->end_b = ptrs->begin_b;
	ptrs->begin_b = tmp;
}

void rotate_c(my_ptrs_t* ptrs)
{
	rotate_a(ptrs);
	rotate_b(ptrs);
}
