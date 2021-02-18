/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** add_tunnel_to_room.c
*/

#include "../include/all.h"

void put_tunnel(int room, int next, global_t *global)
{
	global->room[room]->next[global->room[room]->already_put] =
	global->room[next];
	global->room[room]->already_put = global->room[room]->already_put + 1;
}

void add_tunnel(char **tab, global_t *global)
{
	int room1 = -1;
	int room2 = -1;

	if (tab[0] && tab[1] && my_strcmp(tab[0], tab[1]) == 0)
		return;
	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		if (my_strcmp(tab[0], global->room[i]->name) == 0)
			room1 = i;
		if (my_strcmp(tab[1], global->room[i]->name) == 0)
			room2 = i;
	}
	if (room1 == -1 || room2 == -1)
		return;
	put_tunnel(room1, room2, global);
	put_tunnel(room2, room1, global);
}

void add_tunnel_to_room(global_t *global)
{
	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		global->room[i]->next = malloc(sizeof(room_t*) *
		(global->room[i]->nb_next + 5));
		for (int j = 0 ; j < global->room[i]->nb_next + 5 ; j++)
			global->room[i]->next[j] = NULL;
	}
	for (input_t *tmp = global->input_first ; tmp ; tmp = tmp->next) {
		if (tmp->info == INFO_TUNNEL && my_tab_len(tmp->tab) == 2)
			add_tunnel(tmp->tab, global);
	}
}
