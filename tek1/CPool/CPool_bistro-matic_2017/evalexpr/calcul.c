/*
** EPITECH PROJECT, 2017
** calcul
** File description:
** calcul
*/

#include "all.h"

char *doop(char *nbr1, char *nbr2, char ope)
{
	char *result;

	switch(ope) {
		case '+':
			result = addinf(nbr1, nbr2);
			break;
		case '-':
			result = subinf(nbr1, nbr2);
			break;
		case '*':
			result = multinf(nbr1, nbr2);
			break;
		case '/':
			result = nbr1;
			break;
		case '%':
			result = nbr2;
			break;
	}
	return (result);
}

void calcul(rpn_t **begin)
{
	char *result;
	rpn_t *ptr1 = *begin;
	rpn_t *ptr2 = ptr1->next;
	rpn_t *ptr3 = ptr2->next;

	while (ptr3->ope == 0) {
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr2->next;
	}
	result = doop(ptr1->nb, ptr2->nb, ptr3->ope);
	ptr1->nb = result;
	ptr1->next = ptr3->next;
	free(ptr2);
	free(ptr3);
}
