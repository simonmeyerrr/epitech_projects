/*
** EPITECH PROJECT, 2017
** info_file
** File description:
** main.c
*/

#include "all.h"

int main(int ac, char **av)
{
	if (ac < 2)	{
		write(2, "Not enough arguments.\n", 22);
		return (EXIT_ERROR);
	} else if (ac > 2) {
		write(2, "Too much arguments.\n", 20);
		return (EXIT_ERROR);
	}
	info_file(av[1]);
	return (EXIT_SUCCESS);
}
