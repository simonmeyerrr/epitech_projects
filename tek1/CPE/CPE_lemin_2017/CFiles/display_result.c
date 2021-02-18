/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** display_result.c
*/

#include "../include/all.h"

void display_moves(int ants, int length, int *tab, room_t **room)
{
	int *tab_ants = malloc(sizeof(int) * ants);
	int tab_length[2] = {ants, length};

	if (!tab_ants)
		return;
	for (int i = 0 ; i < ants ; i++)
		tab_ants[i] = -1;
	tab_ants[0] = tab[1];
	loop_display(tab_length, tab_ants, tab, room);
}

void display_result2(global_t *global, input_t *tmp, int ants)
{
	if (global->nb_tunnel <= 0)
		return;
	my_putstr_fd("#tunnels\n", 1);
	for (; tmp ; tmp = tmp->next) {
		if (my_tab_len(tmp->tab) == 2) {
			my_putstr_fd(tmp->line, 1);
			my_putstr_fd("\n", 1);
		}
	}
	if (global->end_found != 1)
		return;
	my_putstr_fd("#moves\n", 1);
	if (global->end_found == 1)
		display_moves(ants, global->search_last->tab_length,
		global->search_last->tab_way, global->room);
}

void display_result(global_t *global)
{
	input_t *tmp = global->input_first;
	int ants;

	for (; tmp && tmp->info != INFO_ANTS ; tmp = tmp->next);
	my_putstr_fd("#number_of_ants\n", 1);
	my_putstr_fd(tmp->tab[0], 1);
	ants = my_get_nbr(tmp->tab[0]);
	if (global->nb_room <= 0)
		return;
	my_putstr_fd("\n#rooms\n", 1);
	for (; tmp && tmp->info != INFO_TUNNEL ; tmp = tmp->next) {
		if (tmp->info == INFO_FLAG)
			my_putstr_fd(tmp->line, 1);
		if (tmp->info == INFO_ROOM)
			my_putstr_fd(tmp->line, 1);
		if (tmp->info == INFO_FLAG || tmp->info == INFO_ROOM)
			my_putstr_fd("\n", 1);
	}
	display_result2(global, tmp, ants);
}
