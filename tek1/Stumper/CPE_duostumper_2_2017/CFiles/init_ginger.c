/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** init_ginger.c
*/

#include "../include/all.h"

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void verif_malloc(void *ptr)
{
	if (!ptr) {
		write(2, "Error while using malloc.\n", 26);
		exit(MY_ERROR);
	}
}

static void add_pos_to_list(ginger_t *ginger, int i, int j, type_t type)
{
	position_t *new = malloc(sizeof(position_t));

	verif_malloc(new);
	new->type = type;
	new->pos[0] = j;
	new->pos[1] = i;
	new->prev = NULL;
	if (type == TOKEN) {
		new->next = ginger->list_token;
		if (ginger->list_token)
			ginger->list_token->prev = new;
		ginger->list_token = new;
	} else {
		new->next = ginger->list_food;
		if (ginger->list_food)
			ginger->list_food->prev = new;
		ginger->list_food = new;
	}
}

static void manage_char(ginger_t *ginger, int i, int j, char c)
{
	switch (c) {
	case 'F':
		add_pos_to_list(ginger, i, j, FOOD);
		break;
	case '.':
		break;
	case 'G':
		ginger->pos[0] = j;
		ginger->pos[1] = i;
		break;
	case 'T':
		add_pos_to_list(ginger, i, j, TOKEN);
		ginger->total_token += 1;
		break;
	default:
		write(2, "Invalid char in the map.\n", 25);
		exit(MY_ERROR);
	}
}

static void verif_map(ginger_t *ginger)
{
	ginger->width = my_strlen(ginger->map[0]);
	for (int i = 0 ; ginger->map && ginger->map[i] ; i++) {
		if (my_strlen(ginger->map[i]) != ginger->width) {
			write(2, "Every line should be equal.\n", 28);
			exit(84);
		}
		for (int j = 0 ; ginger->map[i][j] ; j++)
			manage_char(ginger, i, j, ginger->map[i][j]);
		ginger->height = i + 1;
	}
	if (ginger->pos[0] == -1) {
		write(2, "There is no ginger.\n", 20);
		exit(MY_ERROR);
	}
	ginger->map[ginger->pos[1]][ginger->pos[0]] = '.';
	ginger->width -= 1;
}

ginger_t *init_ginger(int ac, char **av)
{
	ginger_t *ginger = malloc(sizeof(ginger_t));

	verif_malloc(ginger);
	ginger->map = NULL;
	ginger->list_token = NULL;
	ginger->list_food = NULL;
	ginger->pos[0] = -1;
	ginger->pos[1] = -1;
	ginger->total_token = 0;
	ginger->eaten_token = 0;
	ginger->move_init = -1;
	ginger->end = 0;
	parse_argument(ginger, ac, av);
	verif_map(ginger);
	if (ginger->total_token == 0)
		ginger->end = 1;
	return (ginger);
}
