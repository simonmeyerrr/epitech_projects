/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** manage_touch.c
*/

#include "all.h"

static int check_blocked2(int i, int j, var_t* var)
{
	storage_t* tmp = var->storage;

	while (tmp != NULL) {
		if (tmp->x == j && tmp->y == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int check_blocked(char** map, var_t* var, int ret, int a)
{
	for (int i = 1 ; i < var->height ; i++) {
		a = 0;
		for (int j = 1 ; map[i][j] != '\0' ; j++) {
			(map[i][j] == 'X' && map[i - 1][j] == '#' &&
			map[i][j - 1] == '#' && check_blocked2(i, j, var) == 0)
			? a = 1 : (0);
			(map[i][j] == 'X' && map[i - 1][j] == '#' &&
			map[i][j + 1] == '#' && check_blocked2(i, j, var) == 0)
			? a = 1 : (0);
			(map[i][j] == 'X' && map[i + 1][j] == '#' &&
			map[i][j - 1] == '#' && check_blocked2(i, j, var) == 0)
			? a = 1 : (0);
			(map[i][j] == 'X' && map[i + 1][j] == '#' &&
			map[i][j + 1] == '#' && check_blocked2(i, j, var) == 0)
			? a = 1 : (0);
		}
		(a == 1) ? ret++ : (0);
	}
	return (ret);
}

static int check_finished(char** map, var_t* var)
{
	storage_t* tmp = var->storage;

	while (tmp != NULL) {
		if (map[tmp->y][tmp->x] != 'X')
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void manage_touch(int touch, char** map, var_t* var)
{
	int tab_touch[4] = {65, 66, 67, 68};
	void (*tab_fonc[4])(int, char**, var_t*) = {touch_up, touch_down,
		touch_right, touch_left};

	if (touch == 32)
		var->status = -1;
	if (touch == 113)
		var->status = 1;
	for (int i = 0 ; i < 4 ; i++) {
		if (touch == tab_touch[i])
			tab_fonc[i](touch, map, var);
	}
	if (check_finished(map, var) == 1) {
		var->status = 0;
		return;
	}
	if (check_blocked(map, var, 0, 0) >= var->box)
		var->status = 1;
}
