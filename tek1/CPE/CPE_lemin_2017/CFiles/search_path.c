/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** search_path.c
*/

#include "../include/all.h"

void add_new_path(global_t *global, search_t *to_copy, int new_room)
{
	search_t *new = malloc(sizeof(search_t));

	if (!new)
		return;
	new->next = NULL;
	new->prev = global->search_last;
	global->search_last->next = new;
	global->search_last = new;
	new->tab_length = to_copy->tab_length + 1;
	new->tab_way = malloc(sizeof(int) * new->tab_length);
	for (int i = 0 ; i < to_copy->tab_length ; i++)
		new->tab_way[i] = to_copy->tab_way[i];
	new->tab_way[new->tab_length - 1] = new_room;
	global->room[new_room]->is_used = 1;
}

search_t *get_first_search(global_t *global)
{
	search_t *first = malloc(sizeof(search_t));

	if (!first)
		return (NULL);
	first->tab_length = 1;
	first->tab_way = malloc(sizeof(int));
	first->tab_way[0] = -1;
	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		if (global->room[i]->type == TYPE_BEGIN) {
			first->tab_way[0] = i;
			global->room[i]->is_used = 1;
		}
	}
	first->prev = NULL;
	first->next = NULL;
	return (first);
}

void search_next_path(global_t *global, search_t *search)
{
	for (int i = 0 ; i <
	global->room[search->tab_way[search->tab_length - 1]]->already_put ;
	i++) {
		if (global->room[search->tab_way[search->tab_length -
		1]]->next[i]->is_used == 0)
			add_new_path(global, search, global->room[search->
			tab_way[search->tab_length - 1]]->next[i]->tab_pos);
		if (global->room[search->tab_way[search->tab_length - 1]]->
		next[i]->type == TYPE_END) {
			global->end_found = 1;
			return;
		}
	}
}

void search_path(global_t *global)
{
	global->end_found = 0;
	for (int i = 0 ; i < global->nb_room ; i++)
		global->room[i]->tab_pos = i;
	if (global->nb_room < 2 || global->nb_tunnel < 1)
		return;
	global->search_first = get_first_search(global);
	if (!global->search_first || global->search_first->tab_way[0] == -1)
		return;
	global->search_last = global->search_first;
	for (search_t *tmp = global->search_first ; tmp &&
	global->end_found == 0; tmp = tmp->next)
		search_next_path(global, tmp);
}
