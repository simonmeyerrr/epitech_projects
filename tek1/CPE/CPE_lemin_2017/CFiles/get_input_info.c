/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** get_input_info.c
*/

#include "../include/all.h"

static int check_prog2(global_t *global, input_t *input, int *error)
{
	int len = my_tab_len(input->tab);

	if (len == 0)
		return (2);
	if (len == 1) {
		input->info = INFO_TUNNEL;
		global->nb_tunnel = global->nb_tunnel + 1;
		return (2);
	}
	*error = 1;
	return (2);
}

static int check_prog1_2(global_t *global, input_t *input, int *error)
{
	int len = my_tab_len(input->tab);

	if (len == 3 && is_nb_valid(input->tab[1]) &&
	is_nb_valid(input->tab[2])) {
		input->info = INFO_ROOM;
		global->nb_room = global->nb_room + 1;
		return (1);
	}
	if (len == 0)
		return (1);
	*error = 1;
	return (1);
}

static int check_prog1(global_t *global, input_t *input, int *error)
{
	static int start = 0;
	static int end = 0;
	int len = my_tab_len(input->tab);

	if (len == 1 && start == 1 && end == 1)
		return (2);
	if (len == 0 && my_strcmp(input->line, "##start") == 0 && start == 0) {
		start = 1;
		input->info = INFO_FLAG;
		return (1);
	}
	if (len == 0 && my_strcmp(input->line, "##end") == 0 && end == 0) {
		end = 1;
		input->info = INFO_FLAG;
		return (1);
	}
	return (check_prog1_2(global, input, error));
}

static int check_prog0(global_t *global, input_t *input, int *error)
{
	int len = my_tab_len(input->tab);

	if (len == 0)
		return (0);
	if (len > 1) {
		*error = 1;
		return (0);
	}
	if (len == 1 && is_nb_valid(input->tab[0])) {
		input->info = INFO_ANTS;
		return (1);
	}
	*error = 1;
	return (0);
}

void get_info_input(global_t *global, input_t *input, int *error)
{
	static int prog = 0;

	if (prog == 0) {
		prog = check_prog0(global, input, error);
		return;
	}
	if (prog == 1)
		prog = check_prog1(global, input, error);
	if (prog == 2)
		prog = check_prog2(global, input, error);
}
