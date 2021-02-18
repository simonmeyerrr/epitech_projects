/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban.c
*/

#include "all.h"

static void print_map(char** map)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int j = 0 ; map[i][j] != '\0' ; j++) {
			(map[i][j] == '#') ? addch(ACS_CKBOARD) : (0);
			attron(COLOR_PAIR(2));
			(map[i][j] == 'O') ? addch(ACS_DIAMOND) : (0);
			attron(COLOR_PAIR(3));
			(map[i][j] == 'P') ? printw("P") : (0);
			attron(COLOR_PAIR(1));
			(map[i][j] == 'X') ? printw("X") : (0);
			attroff(COLOR_PAIR(1));
			(map[i][j] == ' ') ? printw(" ") : (0);
		}
		printw("\n");
	}
}

static int free_map_var(char** map, var_t* var)
{
	storage_t* tmp = var->storage;
	int ret = var->status;

	while (tmp != NULL) {
		tmp = tmp->next;
		free(var->storage);
		var->storage = tmp;
	}
	for (int i = 0 ; map[i] != NULL ; i++)
		free(map[i]);
	free(map);
	free(var);
	return (ret);
}

static void add_storage(int y, int x, var_t* var)
{
	storage_t* new_storage = malloc(sizeof(*new_storage));

	new_storage->x = x;
	new_storage->y = y;
	new_storage->next = var->storage;
	var->storage = new_storage;
}

static var_t* init_var(char** map)
{
	var_t* var = malloc(sizeof(*var));

	var->storage = NULL;
	var->status = 2;
	var->box = 0;
	for (int i = 0 ; map[i] != NULL ; i++)
		var->height = i;
	for (int i = 0 ; map[0][i] != '\0' ; i++)
		var->width = i;
	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int j = 0 ; map[i][j] != '\0' ; j++) {
			(map[i][j] == 'X') ? var->box = var->box + 1 : (0);
			(map[i][j] == 'P') ? var->player_x = j : (0);
			(map[i][j] == 'P') ? var->player_y = i : (0);
			(map[i][j] == 'O') ? (add_storage(i, j, var)) : (0);
		}
	}
	(check_blocked(map, var, 0, 0) >= var->box) ? exit(84) : (0);
	return (var);
}

int sokoban(char* path)
{
	char** map = open_map(path);
	var_t* var = init_var(map);

	while (1) {
		clear();
		if (LINES < var->height + 1 || COLS < var->width + 1)
			mvprintw(LINES / 2, COLS / 2 - 7, "Please resize");
		else
			print_map(map);
		refresh();
		manage_touch(getch(), map, var);
		if (var->status == 0 || var->status == 1) {
			return (free_map_var(map, var));
		} else if (var->status == -1) {
			free_map_var(map, var);
			return (sokoban(path));
		}
	}
}
