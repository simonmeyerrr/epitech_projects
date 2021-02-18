/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** main.c
*/

#include "all.h"

static void disp_map(char** map, my_var_t* var)
{
	for (int i = 0 ; map[i] != NULL ; i++) {
		write(1, map[i], var->size_x);
		write(1, "\n", 1);
		free(map[i]);
	}
	free(map);
}

static void draw_square(char** map, my_var_t* var)
{
	for (int i = 0 ; i < var->size ; i++) {
		for (int j = 0 ; j < var->size ; j++) {
			map[var->y + i][var->x + j] = 'x';
		}
	}
}

int main(int ac, char **av)
{
	char** map;
	my_var_t* var = malloc(sizeof(*var));

	if (ac != 2)
		return (84);
	map = load_map_var(av[1], var);
	search_square(map, var);
	draw_square(map, var);
	disp_map(map, var);
	free(var);
	return (0);
}
