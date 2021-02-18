/*
** EPITECH PROJECT, 2017
** main
** File description:
** main evalexpr
*/

#include "all.h"

char *my_resolve(rpn_t *ptr)
{
	while (ptr->next != NULL)
		calcul(&ptr);
	return (ptr->nb);
}

char *eval_expr(char *str)
{
	rpn_t *rpn = NULL;

	my_rpn(str, &rpn);
	my_rev_rpn(&rpn);
	return (my_resolve(rpn));
}
