/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** init_global.c
*/

#include "../include/all.h"

static void add_input(global_t *global, char *str, int *error)
{
	input_t *new = malloc(sizeof(*new));

	if (my_strlen(str) == 0 || !new) {
		*error = 1;
		my_free(new);
		return;
	}
	new->line = my_strdup(str);
	new->tab = str_to_tab(new->line);
	new->info = INFO_COMMENT;
	new->next = NULL;
	new->prev = global->input_last;
	if (!global->input_first)
		global->input_first = new;
	if (global->input_last)
		global->input_last->next = new;
	global->input_last = new;
	get_info_input(global, new, error);
}

static void get_input(global_t *global)
{
	char *str = NULL;
	int error = 0;

	str = get_next_line(0);
	while (str && error == 0) {
		add_input(global, str, &error);
		my_free(str);
		str = get_next_line(0);
	}
	my_free(str);
}

global_t *init_global(void)
{
	global_t *global = malloc(sizeof(*global));

	if (!global)
		return (NULL);
	global->input_first = NULL;
	global->input_last = NULL;
	global->ants = 0;
	global->nb_room = 0;
	global->nb_tunnel = 0;
	global->room = NULL;
	get_input(global);
	if (global->nb_room < 2 || global->nb_tunnel < 1)
		return (NULL);
	global->room = malloc(sizeof(room_t*) * global->nb_room);
	if (!global->room)
		return (NULL);
	init_room(global);
	init_tunnel(global);
	add_tunnel_to_room(global);
	return (global);
}
