/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** main.c
*/

#include "all.h"

static int valid_square2(int i, int* tab, int size, char** map)
{
	for (int j = 0 ; j < size ; j++) {
		if (map[i + tab[1]][j + tab[0]] != '.')
			return(0);
	}
	return (1);
}

static int valid_square(int x, int y, int size, char** map)
{
	int tab[2] = {x, y};
	for (int i = 0 ; i < size ; i++) {
		if (valid_square2(i, tab, size, map) == 0)
			return (0);
	}
	return (1);
}

static void check_square(int x, int y, char** map, my_var_t* var)
{
	int i = 1;
	int size;

	while (i == 1) {
		size = var->size + 1;
		if (x + size > var->size_x || y + size > var->size_y)
			return;
		i = valid_square(x, y, size, map);
		if (i == 1) {
			var->size++;
			var->x = x;
			var->y = y;
		}
	}
}

void search_square(char** map, my_var_t* var)
{
	for (int y = 0 ; y < var->size_y - var->size ; y++) {
		for (int x = 0 ; x < var->size_x - var->size ; x++) {
			check_square(x, y, map, var);
		}
	}
}
