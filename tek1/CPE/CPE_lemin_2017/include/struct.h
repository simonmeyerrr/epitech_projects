/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct search
{
	int tab_length;
	int *tab_way;

	struct search *prev;
	struct search *next;
} search_t;

typedef enum
{
	TYPE_NORMAL = 0,
	TYPE_BEGIN = 1,
	TYPE_END = 2
} my_type_t;

typedef struct room
{
	char *name;
	int tab_pos;
	my_type_t type;
	int pos_x;
	int pos_y;

	char is_used;

	int nb_next;
	int already_put;
	struct room **next;
} room_t;

typedef enum
{
	INFO_ANTS,
	INFO_ROOM,
	INFO_TUNNEL,
	INFO_FLAG,
	INFO_COMMENT
} info_t;

typedef struct input
{
	char *line;
	char **tab;

	info_t info;

	struct input *next;
	struct input *prev;
} input_t;

typedef struct global
{
	input_t *input_first;
	input_t *input_last;

	int ants;
	int nb_room;
	int nb_tunnel;
	room_t **room;

	int end_found;
	search_t *search_first;
	search_t *search_last;
} global_t;

#endif	/* STRUCT_H_ */
