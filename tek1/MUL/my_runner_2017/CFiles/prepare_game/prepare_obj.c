/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** prepare_obj.c
*/

#include "all.h"

static void prepare_player(my_player_t *player, char **map)
{
	int y = 0;

	while (map[y][2] != 'P' && map[y] != NULL)
		y++;
	player->rect.top = 0;
	player->rect.left = 0;
	player->rect.width = 75;
	player->rect.height = 120;
	player->pos.x = 200;
	player->pos.y = y * 100 - 20;
	player->move_rect = 0;
}

static int get_type(char c)
{
	int type = TYPE_VOID_BLOCK;

	(c == 'F') ? (type = TYPE_FULL_BLOCK) : (0);
	(c == 'S') ? (type = TYPE_SEMI_BLOCK) : (0);
	(c == 'J') ? (type = TYPE_JUMP_BLOCK) : (0);
	(c == 'E') ? (type = TYPE_END_BLOCK) : (0);
	(c == 'p') ? (type = TYPE_PICK) : (0);
	(c == 'I') ? (type = TYPE_JUMP_INFINITE) : (0);
	return (type);
}

static my_block_t *init_new_block(char c, my_block_t *tmp)
{
	my_block_t *new_block = malloc(sizeof(*new_block));

	new_block->prev = tmp;
	new_block->next = NULL;
	new_block->type = get_type(c);
	new_block->pos.x = tmp->pos.x + 100;
	new_block->pos.y = tmp->pos.y;
	return (new_block);
}

static my_block_t *init_line_block(char *line, int height)
{
	my_block_t *begin = malloc(sizeof(*begin));
	my_block_t *tmp = begin;

	begin->type = get_type(line[0]);
	begin->prev = NULL;
	begin->next = NULL;
	begin->pos.x = 0;
	begin->pos.y = height * 100;
	for (int i = 1 ; line[i] != '\0' ; i++) {
		tmp->next = init_new_block(line[i], tmp);
		tmp = tmp->next;
	}
	return (begin);
}

void prepare_obj(my_object_t *obj, char **map, int *error)
{
	obj->player = malloc(sizeof(*(obj->player)));
	prepare_player(obj->player, map);
	obj->line0 = init_line_block(map[0], 0);
	obj->line1 = init_line_block(map[1], 1);
	obj->line2 = init_line_block(map[2], 2);
	obj->line3 = init_line_block(map[3], 3);
	obj->line4 = init_line_block(map[4], 4);
	obj->line5 = init_line_block(map[5], 5);
	obj->line6 = init_line_block(map[6], 6);
	obj->line7 = init_line_block(map[7], 7);
	obj->line8 = init_line_block(map[8], 8);
	obj->line9 = init_line_block(map[9], 9);
}
