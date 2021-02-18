/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** parse_argument.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

static void add_new_path(minicut_t *minicut, char *str)
{
	my_path_t *new = malloc(sizeof(my_path_t));

	if (!new)
		return;
	new->path = my_strdup(str);
	if (!new->path)
		return;
	new->next = NULL;
	new->prev = minicut->last_path;
	if (minicut->last_path)
		minicut->last_path->next = new;
	else
		minicut->first_path = new;
	minicut->last_path = new;
}

static int arg_is_stand(char *str)
{
	int i = 0;

	while (str && str[i] == '-')
		i++;
	if (!str || str[i] != '\0')
		return (0);
	return (1);
}

static void get_argument(minicut_t *minicut, int ac, char **av)
{
	int arg = 0;

	for (int i = 1 ; i < ac && minicut->error == 0 ; i++) {
		if (arg == 0 && (av[i][0] != '-' || arg_is_stand(av[i]) == 1))
			add_new_path(minicut, av[i]);
		else if (arg == 0)
			arg = manage_flag(minicut, av[i]);
		else
			arg = get_arg_flag(minicut, av[i]);
	}
	if (minicut->error == 0 && arg != 0) {
		my_put_err("minicut: option requires an argument.\n");
		minicut->error = 1;
	}
}

minicut_t *parse_argument(int ac, char **av)
{
	minicut_t *minicut = malloc(sizeof(minicut_t));

	if (!minicut)
		return (NULL);
	minicut->type = TYPE_UNDEFINED;
	minicut->delimiter = '\t';
	minicut->nb_tab = NULL;
	minicut->tab_length = 0;
	minicut->first_path = NULL;
	minicut->last_path = NULL;
	minicut->error = 0;
	get_argument(minicut, ac, av);
	if (minicut->error == 0 && minicut->type == TYPE_UNDEFINED) {
		my_put_err("minicut: you must specify a list of bytes, "
		"characters, or fields.\n");
		minicut->error = 1;
	}
	return (minicut);
}
