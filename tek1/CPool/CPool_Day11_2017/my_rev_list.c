/*
** EPITECH PROJECT, 2017
** my_rev_list.c
** File description:
** reverse a list
*/

#include "include/mylist.h"
#include <stdio.h>

int my_rev_list(linked_list_t **begin)
{
	if (my_list_size(*begin) <= 1)
		return (0);
	struct linked_list *ptr1 = *begin;
	struct linked_list *ptr2 = ptr1->next;
	struct linked_list *ptr3 = ptr2->next;
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
	return (0);
}
