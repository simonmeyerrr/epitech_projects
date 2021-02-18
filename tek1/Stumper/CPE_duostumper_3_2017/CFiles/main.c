/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** main.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static void remove_last_path(minicut_t *minicut)
{
	if (minicut->first_path == minicut->last_path) {
		my_free(minicut->first_path->path);
		my_free(minicut->first_path);
		minicut->first_path = NULL;
		minicut->last_path = NULL;
	} else {
		minicut->last_path = minicut->last_path->prev;
		my_free(minicut->last_path->next->path);
		my_free(minicut->last_path->next);
	}
}

static int free_minicut(minicut_t *minicut)
{
	int ret = MY_SUCCESS;

	if (minicut->error != 0)
		ret = MY_ERROR;
	my_free(minicut->nb_tab);
	while (minicut->first_path)
		remove_last_path(minicut);
	free(minicut);
	return (ret);
}

int main(int ac, char **av)
{
	minicut_t *minicut = parse_argument(ac, av);

	if (!minicut || minicut->error != 0)
		return (MY_ERROR);
	display_minicut(minicut);
	return (free_minicut(minicut));
}
