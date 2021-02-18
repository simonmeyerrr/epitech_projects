/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** main.c
*/

#include "../include/all.h"

int not_good(global_t *global)
{
	int end = 0;
	int begin = 0;

	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		if (!global->room[i])
			return (1);
		if (global->room[i]->type == TYPE_BEGIN)
			begin++;
		if (global->room[i]->type == TYPE_END)
			end++;
	}
	if (end > 1 || begin > 1)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	global_t *global = init_global();

	if (!global)
		return (MY_ERROR);
	if (not_good(global))
		return (MY_ERROR);
	search_path(global);
	display_result(global);
	my_free_global(global);
	return (MY_SUCCESS);
}
