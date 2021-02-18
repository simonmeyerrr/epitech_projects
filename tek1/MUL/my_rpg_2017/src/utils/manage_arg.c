/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** manage_arg.c
*/

#include "all.h"

static int check_arg(char *arg, int ret)
{
	if (my_strcmp(arg, "--help") == 0)
		return (2);
	if (my_strcmp(arg, "--offline") == 0) {
		if (ret == 2)
			return (ret);
		else
			return (1);
	}
	for (int i = 1 ; arg[0] == '-' && arg[i] ; i++) {
		if (arg[i] == 'h' || (arg[i] == 'o' && ret == 2))
			return (2);
		else if (arg[i] == 'o')
			return (1);
		else
			return (3);
	}
	return (3);
}

int manage_arg(int ac, char **av, char **env)
{
	int ret = 0;

	for (int i = 1 ; i < ac && ret != '3' ; i++)
		ret = check_arg(av[i], ret);
	if (ret > 2)
		my_putstr_fd("Invalid argument, use -h for more informations.\n"
		, 2);
	if (ret < 2 && (!env || !env[0])) {
		my_putstr_fd("Programm need an environement to work.\n", 2);
		ret = 3;
	}
	return (ret);
}
