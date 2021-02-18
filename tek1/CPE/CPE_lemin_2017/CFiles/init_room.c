/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** init_room.c
*/

#include "../include/all.h"

room_t *get_info_room(input_t *input, my_type_t flag)
{
	room_t *room = malloc(sizeof(room_t));

	if (!room)
		return (NULL);
	room->name = my_strdup(input->tab[0]);
	room->pos_x = my_get_nbr(input->tab[1]);
	room->pos_y = my_get_nbr(input->tab[2]);
	room->type = flag;
	room->is_used = 0;
	room->nb_next = 0;
	room->already_put = 0;
	room->next = NULL;
	return (room);
}

void init_room(global_t *global)
{
	input_t *tmp = global->input_first;
	my_type_t flag = TYPE_NORMAL;

	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		while (tmp && tmp->info != INFO_ROOM && tmp->info != INFO_FLAG)
			tmp = tmp->next;
		if (tmp && tmp->info == INFO_FLAG && my_strcmp(tmp->line,
		"##start") == 0)
			flag = TYPE_BEGIN;
		if (tmp && tmp->info == INFO_FLAG && my_strcmp(tmp->line,
		"##end") == 0)
			flag = TYPE_END;
		while (tmp && tmp->info != INFO_ROOM)
			tmp = tmp->next;
		global->room[i] = get_info_room(tmp, flag);
		flag = TYPE_NORMAL;
		tmp = tmp->next;
	}
}
