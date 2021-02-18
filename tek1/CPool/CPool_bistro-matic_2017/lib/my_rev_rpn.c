/*
** EPITECH PROJECT, 2017
** my_rev_rpn.c
** File description:
** reverse rpn
*/

#include "../include/all.h"

void my_rev_rpn(rpn_t **begin)
{
	if (my_rpn_size(*begin) <= 1)
		return;
	rpn_t *ptr1 = *begin;
	rpn_t *ptr2 = ptr1->next;
	rpn_t *ptr3 = ptr2->next;
	ptr1->next = NULL;
	for (int i = 0 ; ptr3 != NULL ; i++) {
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr2->next;
	}
	ptr2->next = ptr1;
	ptr1 = ptr2;
	*begin = ptr2;
}
