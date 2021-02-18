/*
** EPITECH PROJECT, 2017
** head
** File description:
** parse_argument.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

static void add_file_to_list(argument_t *arg, char *name)
{
	list_file_t *new = malloc(sizeof(list_file_t));

	if (!new)
		return;
	arg->nb_file++;
	new->name = my_strdup(name);
	new->next = NULL;
	new->prev = arg->last_file;
	if (arg->last_file)
		arg->last_file->next = new;
	if (!arg->first_file)
		arg->first_file = new;
	arg->last_file = new;
}

static int arg_is_standart_output(char *str)
{
	for (int i = 0 ; str && str[i] ; i++)
		if (str[i] != '-')
			return (0);
	return (1);
}

static void get_argument(argument_t *arg, int ac, char **av)
{
	int arg_status = 0;

	for (int i = 1 ; arg->error == 0 && i < ac ; i++) {
		if ((arg_is_standart_output(av[i]) == 1 ||
		(av[i][0] != '-')) && arg_status == 0)
			add_file_to_list(arg, av[i]);
		else if (arg_status != 0)
			arg_status = get_value_arg(arg, av[i]);
		else
			arg_status = get_special_arg(arg, av[i]);
		if (arg_status == 2)
			arg_status = get_value_arg_spe(arg, av[i]);
	}
	if (arg->error == 0 && arg_status != 0) {
		my_put_error("head: option requires an argument\n");
		my_put_error("Try 'head --help' for more information.\n");
		arg->error = 1;
	}
}

argument_t *parse_argument(int ac, char **av)
{
	argument_t *arg = malloc(sizeof(argument_t));

	if (!arg)
		return (NULL);
	arg->option_name = NAME_NORMAL;
	arg->option_size = SIZE_LINE;
	arg->option_size_int = 10;
	arg->first_file = NULL;
	arg->last_file = NULL;
	arg->nb_file = 0;
	arg->error = 0;
	get_argument(arg, ac, av);
	return (arg);
}
