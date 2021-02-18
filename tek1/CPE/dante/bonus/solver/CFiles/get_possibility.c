/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** get_possibility.c
*/

#include "../include/all.h"

static int get_up_possibility(maze_t *maze)
{
	if (maze->pos_i > 0 && maze->map[maze->pos_i - 1][maze->pos_j] == '*')
		return (1);
	return (0);
}

static int get_right_possibility(maze_t *maze)
{
	if (maze->pos_j < maze->width - 1 &&
	maze->map[maze->pos_i][maze->pos_j + 1] == '*')
		return (1);
	return (0);
}

static int get_down_possibility(maze_t *maze)
{
	if (maze->pos_i < maze->height - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j] == '*')
		return (1);
	return (0);
}

static int get_left_possibility(maze_t *maze)
{
	if (maze->pos_j > 0 && maze->map[maze->pos_i][maze->pos_j - 1] == '*')
		return (1);
	return (0);
}

int *get_possibility(maze_t *maze, int *tab)
{
	tab[0] = get_up_possibility(maze);
	tab[1] = get_right_possibility(maze);
	tab[2] = get_down_possibility(maze);
	tab[3] = get_left_possibility(maze);
	if (tab[0] == 1 || tab[1] == 1 || tab[2] == 1 || tab[3] == 1)
		tab[4] = 1;
	else
		tab[4] = 0;
}
