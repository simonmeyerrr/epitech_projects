/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** my_get_opt2.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

char verif_arg_long_flag2(my_getopt_t getopt, my_flag_t *flags, int choice)
{
	char end = getopt.av[*(getopt.i)][my_strlen(flags[choice].long_flag)];
	char arg = flags[choice].arg;
	char c = flags[choice].short_flag;

	if (end != '=' && end != '\0') {
		my_put_err("Invalid flag: ");
		my_put_err(getopt.av[*(getopt.i)]);
		my_put_err("\n");
		*(getopt.i) = *(getopt.i) + 1;
		return ('!');
	}
	if (end == '=' && arg == 0) {
		my_put_err("No argument expected.\n");
		*(getopt.i) = *(getopt.i) + 1;
		return ('!');
	}
	*(getopt.i) = *(getopt.i) + 1;
	return (c);
}

char verif_arg_long_flag(my_getopt_t getopt, my_flag_t *flags, int choice)
{
	char end = getopt.av[*(getopt.i)][my_strlen(flags[choice].long_flag)];
	char arg = flags[choice].arg;
	char c = flags[choice].short_flag;

	if (end == '\0' && arg == 1 && *(getopt.i) < getopt.ac - 1) {
		*(getopt.str) = my_strdup(getopt.av[*(getopt.i) + 1]);
		*(getopt.i) = *(getopt.i) + 2;
		return (c);
	} else if (end == '\0' && arg == 1) {
		my_put_err("Argument expected.\n");
		*(getopt.i) = *(getopt.i) + 1;
		return ('!');
	}
	if (end == '=' && arg == 1) {
		*(getopt.str) = my_strdup(getopt.av[*(getopt.i)] +
		my_strlen(flags[choice].long_flag) + 1);
		*(getopt.i) = *(getopt.i) + 1;
		return (c);
	}
	return (verif_arg_long_flag2(getopt, flags, choice));
}

char get_long_flag(my_getopt_t getopt, int len)
{
	int choice = len;

	for (int i = 0 ; i < len ; i++) {
		if (my_strncmp(getopt.flags[i].long_flag,
		getopt.av[*(getopt.i)],
		my_strlen(getopt.flags[i].long_flag) - 1) == 0)
			choice = i;
	}
	if (choice == len) {
		my_put_err("Invalid flag: ");
		my_put_err(getopt.av[*(getopt.i)]);
		my_put_err("\n");
		*(getopt.i) = *(getopt.i) + 1;
		return ('!');
	}
	return (verif_arg_long_flag(getopt, getopt.flags, choice));
}
