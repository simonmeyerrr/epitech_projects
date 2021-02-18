/*
** EPITECH PROJECT, 2017
** ope_to_rpm.c
** File description:
** put ope in rpm list
*/

#include "all.h"

void ope_to_rpn2(rpn_t **rpn, ope_t **ope)
{
	rpn_t *new_rpn;

	new_rpn = malloc(sizeof(*new_rpn));
	new_rpn->nb = "\0";
	new_rpn->ope = (*ope)->ope;
	new_rpn->next = *rpn;
	*rpn = new_rpn;
	*ope = (*ope)->next;
}

void ope_to_rpn(rpn_t **rpn, ope_t **ope)
{
	if (*ope == NULL)
		return;
	while ((*ope)->ope != '(' && (*ope)->next != NULL)
		ope_to_rpn2(rpn, ope);
	if ((*ope)->ope == '(')
		*ope = (*ope)->next;
	else
		ope_to_rpn2(rpn, ope);
}
