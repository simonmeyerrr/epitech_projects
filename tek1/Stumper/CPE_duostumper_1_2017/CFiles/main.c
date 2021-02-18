/*
** EPITECH PROJECT, 2017
** head
** File description:
** main.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

static void remove_last_file(argument_t *arg)
{
	my_free(arg->last_file->name);
	if (arg->last_file->prev) {
		arg->last_file = arg->last_file->prev;
		my_free(arg->last_file->next);
		arg->last_file->next = NULL;
	} else {
		my_free(arg->last_file);
		arg->last_file = NULL;
		arg->first_file = NULL;
	}
}

static void my_free_arg(argument_t *arg)
{
	if (!arg)
		return;
	while (arg->first_file)
		remove_last_file(arg);
	my_free(arg);
}

int main(int ac, char **av)
{
	argument_t *arg = parse_argument(ac, av);

	if (!arg)
		return (1);
	if (arg->error == 1) {
		my_free_arg(arg);
		return (1);
	}
	display_file(arg);
	if (arg->error == 1) {
		my_free_arg(arg);
		return (1);
	}
	my_free_arg(arg);
	return (0);
}
