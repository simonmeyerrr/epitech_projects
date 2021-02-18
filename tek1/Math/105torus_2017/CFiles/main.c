/*
** EPITECH PROJECT, 2017
** 105torus_2017
** File description:
** main.c
*/

#include "all.h"

static int is_valid_int(char *str, int a)
{
	int i = (str[0] == '-' && a != 7) ? (1) : (0);

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int check_error(int ac, char **av)
{
	if (ac != 8)
		return (1);
	if (strcmp(av[1], "1") != 0 && strcmp(av[1], "2") != 0 &&
	strcmp(av[1], "3") != 0)
		return (1);
	for (int i = 2 ; i < 8 ; i++) {
		if (is_valid_int(av[i], i) == 1)
			return (1);
	}
	if (atoi(av[7]) <= 0)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int error = check_error(ac, av);

	if (error == 1)
		return (EXIT_ERROR);
	if (av[1][0] == '1')
		bisection(av);
	else if (av[1][0] == '2')
		newton(av);
	else
		secant(av);
	return (EXIT_SUCCESS);
}
