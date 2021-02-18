/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** push_swap
*/

#include "../include/my.h"

int search_min(my_ptrs_t* ptrs)
{
	int min = ptrs->begin_a->nb;
	int pos = 0;
	int i = 0;
	my_list_t* tmp = ptrs->begin_a;
	while (tmp != NULL) {
		if (min > tmp->nb) {
			pos = i;
			min = tmp->nb;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int my_list_is_sorted(my_ptrs_t* ptrs)
{
	my_list_t* tmp1;
	my_list_t* tmp2;

	tmp1 = ptrs->begin_a;
	tmp2 = tmp1->next;
	while (tmp2 != NULL) {
		if (tmp1->nb > tmp2->nb)
			return (0);
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	return (1);
}

int put_min_first(int space, my_ptrs_t* ptrs, int size, int pos)
{
	if (pos > size / 2) {
		for (int i = 0 ; i < size - pos ; i++) {
			space = disp_ope(space, "rra");
			rev_rotate_a(ptrs);
		}
	} else {
		for (int i = 0 ; i < pos ; i++) {
			space = disp_ope(space, "ra");
			rotate_a(ptrs);
		}
	}
	return (space);
}
void my_pushswap(my_ptrs_t* ptrs, int size)
{
	int space = 0;
	int pos;

	while (my_list_is_sorted(ptrs) != 1) {
		pos = search_min(ptrs);
		space = put_min_first(space, ptrs, size, pos);
		space = disp_ope(space, "pb");
		move_a_to_b(ptrs);
		size--;
	}
	while (ptrs->begin_b != NULL) {
		space = disp_ope(space, "pa");
		move_b_to_a(ptrs);
	}
}
