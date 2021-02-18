/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** my_get_opt.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static int is_simple_arg(my_getopt_t getopt)
{
	int i = 0;

	if (getopt.av[*(getopt.i)][0] != '-') {
		*(getopt.str) = my_strdup(getopt.av[*(getopt.i)]);
		*(getopt.i) = *(getopt.i) + 1;
		return (1);
	}
	for (i = 0 ; getopt.av[*(getopt.i)][i] == '-' ; i++);
	if (getopt.av[*(getopt.i)][i] == '\0') {
		*(getopt.str) = my_strdup(getopt.av[*(getopt.i)]);
		*(getopt.i) = *(getopt.i) + 1;
		return (1);
	}
	return (0);
}

static char verif_arg_short_flag2(my_getopt_t getopt, my_flag_t *flags,
int choice)
{
	char end = getopt.av[*(getopt.i)][*(getopt.j) + 1];
	char arg = flags[choice].arg;
	char c = flags[choice].short_flag;

	if (end != '\0' && arg == 1) {
		*(getopt.str) =
		my_strdup(getopt.av[*(getopt.i)] + *(getopt.j) + 1);
		*(getopt.i) = *(getopt.i) + 1;
		*(getopt.j) = 1;
		return (c);
	}
	*(getopt.j) = *(getopt.j) + 1;
	if (getopt.av[*(getopt.i)][*(getopt.j)] == '\0') {
		*(getopt.j) = 1;
		*(getopt.i) = *(getopt.i) + 1;
	}
	return (c);
}

static char verif_arg_short_flag(my_getopt_t getopt, my_flag_t *flags,
int choice)
{
	char end = getopt.av[*(getopt.i)][*(getopt.j) + 1];
	char arg = flags[choice].arg;
	char c = flags[choice].short_flag;

	if (end == '\0' && arg == 1 && *(getopt.i) < getopt.ac - 1) {
		*(getopt.str) = my_strdup(getopt.av[*(getopt.i) + 1]);
		*(getopt.i) = *(getopt.i) + 2;
		*(getopt.j) = 1;
		return (c);
	} else if (end == '\0' && arg == 1) {
		my_put_err("Argument expected.\n");
		*(getopt.i) = *(getopt.i) + 1;
		*(getopt.j) = 1;
		return ('!');
	}
	return (verif_arg_short_flag2(getopt, flags, choice));
}

static char get_short_flag(my_getopt_t getopt, int len)
{
	int choice = len;

	for (int i = 0 ; i < len ; i++)
		if (getopt.flags[i].short_flag ==
		getopt.av[*(getopt.i)][*(getopt.j)])
			choice = i;
	if (choice == len) {
		my_put_err("Invalid flag: \'");
		write(2, &(getopt.av[*(getopt.i)][*(getopt.j)]), 1);
		my_put_err("\'\n");
		*(getopt.j) = *(getopt.j) + 1;
		if (getopt.av[*(getopt.i)][*(getopt.j)] == '\0') {
			*(getopt.j) = 1;
			*(getopt.i) = *(getopt.i) + 1;
		}
		return ('!');
	}
	return (verif_arg_short_flag(getopt, getopt.flags, choice));
}

char my_getopt(my_flag_t *flags, char **str, int ac, char **av)
{
	int error = 0;
	char flag;
	static int i = 1;
	static int j = 1;
	my_getopt_t getopt = {flags, str, ac, av, &error, &i, &j};

	my_free(*str);
	*str = NULL;
	if (i >= ac)
		return ('.');
	if (is_simple_arg(getopt))
		return (':');
	flag = (getopt.av[*(getopt.i)][0] == '-' && getopt.av[*(getopt.i)][1]
	== '-') ? (get_long_flag(getopt, 3)) : (get_short_flag(getopt, 3));
	if (error != 0 || flag == '!') {
		my_free(*str);
		*str = NULL;
		return ('!');
	} else
		return (flag);
}
