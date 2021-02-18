/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** move.c
*/

#include "all.h"

static void put_storage(char** map, var_t* var)
{
	storage_t* tmp = var->storage;

	while (tmp != NULL) {
		if (map[tmp->y][tmp->x] == ' ')
			map[tmp->y][tmp->x] = 'O';
		tmp = tmp->next;
	}
}

void touch_up(int touch, char** map, var_t* var)
{
	if (var->player_y < 2)
		return;
	var->next1 = map[var->player_y - 1][var->player_x];
	var->next2 = map[var->player_y - 2][var->player_x];
	if (var->next1 == ' ' || var->next1 == 'O') {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y - 1][var->player_x] = 'P';
		var->player_y--;
	}
	if (var->next1 == 'X' && (var->next2 == ' ' || var->next2 == 'O')) {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y - 1][var->player_x] = 'P';
		map[var->player_y - 2][var->player_x] = 'X';
		var->player_y--;
	}
	put_storage(map, var);
}

void touch_down(int touch, char** map, var_t* var)
{
	if (var->player_y > var->height  - 2)
		return;
	var->next1 = map[var->player_y + 1][var->player_x];
	var->next2 = map[var->player_y + 2][var->player_x];
	if (var->next1 == ' ' || var->next1 == 'O') {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y + 1][var->player_x] = 'P';
		var->player_y++;
	}
	if (var->next1 == 'X' && (var->next2 == ' ' || var->next2 == 'O')) {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y + 1][var->player_x] = 'P';
		map[var->player_y + 2][var->player_x] = 'X';
		var->player_y++;
	}
	put_storage(map, var);
}

void touch_right(int touch, char** map, var_t* var)
{
	if (var->player_x > var->width  - 2)
		return;
	var->next1 = map[var->player_y][var->player_x + 1];
	var->next2 = map[var->player_y][var->player_x + 2];
	if (var->next1 == ' ' || var->next1 == 'O') {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y][var->player_x + 1] = 'P';
		var->player_x++;
	}
	if (var->next1 == 'X' && (var->next2 == ' ' || var->next2 == 'O')) {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y][var->player_x + 1] = 'P';
		map[var->player_y][var->player_x + 2] = 'X';
		var->player_x++;
	}
	put_storage(map, var);
}

void touch_left(int touch, char** map, var_t* var)
{
	if (var->player_x < 2)
		return;
	var->next1 = map[var->player_y][var->player_x - 1];
	var->next2 = map[var->player_y][var->player_x - 2];
	if (var->next1 == ' ' || var->next1 == 'O') {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y][var->player_x - 1] = 'P';
		var->player_x--;
	}
	if (var->next1 == 'X' && (var->next2 == ' ' || var->next2 == 'O')) {
		map[var->player_y][var->player_x] = ' ';
		map[var->player_y][var->player_x - 1] = 'P';
		map[var->player_y][var->player_x - 2] = 'X';
		var->player_x--;
	}
	put_storage(map, var);
}
