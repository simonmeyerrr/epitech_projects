/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main bistro-matic
*/

#include "all.h"

static void calcsyntax(char c, char c2)
{
	if ((c < '0' || c > '9') && c != '+' && c != '-' && c != '*' &&
	c != '/' && c != '%' && c != '(' && c != ')') {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if ((c == '*' || c == '/' || c == '%') && c2 != ')' && c2 != '(' &&
	(c2 < '0' || c2 > '9')) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if ((c == '(' && c2 >= '0' && c2 <= '9') || (c == ')' && (c2 < '0' ||
	c2 > '9') && c2 != ')')) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if (c >= '0' && c <= '9' && c2 == ')') {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
}

static int parentheses(char c, int open)
{
	if (c == '(')
		open++;
	if (c == ')')
		open--;
	if (open < 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	return (open);
}

static void verifsyntax(char *str)
{
	int open = parentheses(str[0], 0);
	int i = 1;

	calcsyntax(str[0], 'a');
	while (str[i] != '\0') {
		calcsyntax(str[i], str[i-1]);
		open = parentheses(str[i], open);
		i++;
	}
	if ((str[i - 1] < '0' || str[i - 1] > '9') && str[i - 1] != ')') {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if (open != 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
}

static char *getexpr(int size)
{
	char *expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_ERROR);
	}
	expr = malloc(sizeof(char) * (size + 1));
	if (expr == 0) {
		my_putstr(ERROR_MSG);
		exit (EXIT_ERROR);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit (EXIT_ERROR);
	}
	expr[size] = 0;
	return (expr);
}

int main(int ac, char **av)
{
	int size;
	char *expr;

	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		my_putstr(USAGE);
		return (EXIT_SUCCESS);
	} else if (ac != 4) {
		my_putstr(USAGE);
		return (EXIT_ERROR);
	}
	size = my_getnbr(av[3]);
	expr = getexpr(size);
	expr = modifbase(expr, av[1], av[2]);
	verifsyntax(expr);
	expr = eval_expr(expr);
	expr = prepresult(expr);
	expr = originbase(expr, av[1], av[2]);
	my_putstr(expr);
	return (EXIT_SUCCESS);
}
