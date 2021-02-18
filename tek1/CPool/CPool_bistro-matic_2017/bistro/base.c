/*
** EPITECH PROJECT, 2017
** base.c
** File description:
** base bistro
*/

#include "all.h"

char *prepresult(char *expr)
{
	char *result = malloc(sizeof(*expr));
	int i = 0;
	int j = 0;

	if (expr[0] == '+')
		i = 1;
	while (i < my_strlen(expr) - 1 && expr[i] == '0')
		i++;
	while (expr[i] != '\0') {
		result[j] = expr[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char compchange(char c, char old, char new)
{
	if (c == old)
		c = new;
	return (c);
}

char *modifchar(char *expr, char *old, char *new)
{
	for (int j = 0 ; expr[j] != '\0' ; j++) {
		for (int i = 0 ; old[i] != '\0' ; i++)
			expr[j] = compchange(expr[j], old[i], new[i]);
	}
	return (expr);
}

char *modifbase(char *expr, char *base, char *ope)
{
	if (my_strlen(base) != 10 || my_strlen(ope) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if (my_strcmp(ope, "()+-*/%") != 0)
		expr = modifchar(expr, ope, "()+-*/%");
	if (my_strcmp(base, "0123456789") != 0)
		expr = modifchar(expr, base, "0123456789");
	return (expr);
}

char *originbase(char *expr, char *base, char *ope)
{
	if (my_strlen(base) != 10 || my_strlen(ope) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if (my_strcmp(ope, "()+-*/%") != 0)
		modifchar(expr, "()+-*/%", ope);
	if (my_strcmp(base, "0123456789") != 0)
		modifchar(expr, "0123456789", base);
	return (expr);
}
