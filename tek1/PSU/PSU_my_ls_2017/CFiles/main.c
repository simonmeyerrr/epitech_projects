/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** main.c
*/

#include "all.h"

static void detect_flag(flags_t* flag, char* str)
{
	for (int i = 1 ; str[i] != '\0' ; i++) {
		if (str[i] == 'l')
			flag->list = 1;
		if (str[i] == 'R')
			flag->recursive = 1;
		if (str[i] == 'd')
			flag->d = 1;
		if (str[i] == 'r')
			flag->reverse = 1;
		if (str[i] == 't')
			flag->t = 1;
		if (str[i] == 'g') {
			flag->g = 1;
			flag->list = 1;
		}
		if (str[i] == 'o') {
			flag->rev_g = 1;
			flag->list = 1;
		}
	}
}

static flags_t* search_flag(int ac, char** av)
{
	flags_t* flag = malloc(sizeof(*flag));

	flag->list = 0;
	flag->recursive = 0;
	flag->d = 0;
	flag->reverse = 0;
	flag->t = 0;
	flag->g = 0;
	flag->rev_g = 0;
	flag->total = 0;
	flag->elem = 0;
	flag->len_link = 0;
	flag->len_user = 0;
	flag->len_group = 0;
	flag->len_size = 0;
	for (int i = 1 ; i < ac ; i++) {
		if (av[i][0] == '-')
			detect_flag(flag, av[i]);
	}
	return (flag);
}

int main(int ac, char **av)
{
	flags_t* flag = search_flag(ac, av);

	if (flag->d == 0)
		ls_normal(flag, ac, av);
	else
		ls_d(flag, ac, av);
	return (EXIT_SUCCESS);
}
