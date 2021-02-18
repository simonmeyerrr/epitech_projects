/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** get_possibility.c
*/

#include "../include/all.h"

static int get_up_possibility(maze_t *maze)
{
	if (maze->pos_i == 0)
		return (0);
	if (maze->pos_i == 1 &&
	(maze->map[maze->pos_i - 1][maze->pos_j] == '*') ||
	(maze->pos_j != 0 && maze->map[maze->pos_i - 1][maze->pos_j - 1] == '*')
	|| (maze->pos_j != maze->width - 1 &&
	maze->map[maze->pos_i - 1][maze->pos_j + 1] == '*'))
		return (0);
	if (maze->pos_i > 1 &&
	((maze->map[maze->pos_i - 1][maze->pos_j] == '*') ||
	(maze->pos_j != 0 && maze->map[maze->pos_i - 1][maze->pos_j - 1] == '*')
	|| (maze->pos_j != maze->width - 1 &&
	maze->map[maze->pos_i - 1][maze->pos_j + 1] == '*') ||
	(maze->map[maze->pos_i - 2][maze->pos_j] == '*')))
		return (0);
	return (1);
}

static int get_right_possibility(maze_t *maze)
{
	if (maze->pos_j == maze->width - 1)
		return (0);
	if (maze->pos_j == maze->width - 2 &&
	((maze->map[maze->pos_i][maze->pos_j + 1] == '*') ||
	(maze->pos_i != 0 && maze->map[maze->pos_i - 1][maze->pos_j + 1] == '*')
	|| (maze->pos_i != maze->height - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j + 1] == '*')))
		return (0);
	if (maze->pos_j < maze->width - 2 &&
	((maze->map[maze->pos_i][maze->pos_j + 1] == '*') ||
	(maze->pos_i != 0 && maze->map[maze->pos_i - 1][maze->pos_j + 1] == '*')
	|| (maze->pos_i != maze->height - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j + 1] == '*') ||
	(maze->map[maze->pos_i][maze->pos_j + 2] == '*')))
		return (0);
	return (1);
}

static int get_down_possibility(maze_t *maze)
{
	if (maze->pos_i == maze->height - 1)
		return (0);
	if (maze->pos_i == maze->height - 2 &&
	((maze->map[maze->pos_i + 1][maze->pos_j] == '*') ||
	(maze->pos_j != 0 && maze->map[maze->pos_i + 1][maze->pos_j - 1] == '*')
	|| (maze->pos_j != maze->width - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j + 1] == '*')))
		return (0);
	if (maze->pos_i < maze->height - 2 &&
	((maze->map[maze->pos_i + 1][maze->pos_j] == '*') ||
	(maze->pos_j != 0 && maze->map[maze->pos_i + 1][maze->pos_j - 1] == '*')
	|| (maze->pos_j != maze->width - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j + 1] == '*') ||
	(maze->map[maze->pos_i + 2][maze->pos_j] == '*')))
		return (0);
	return (1);
}

static int get_left_possibility(maze_t *maze)
{
	if (maze->pos_j == 0)
		return (0);
	if (maze->pos_j == 1 &&
	((maze->map[maze->pos_i][maze->pos_j - 1] == '*') ||
	(maze->pos_i != 0 && maze->map[maze->pos_i - 1][maze->pos_j - 1] == '*')
	|| (maze->pos_i != maze->height - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j - 1] == '*')))
		return (0);
	if (maze->pos_j > 1 &&
	((maze->map[maze->pos_i][maze->pos_j - 1] == '*') ||
	(maze->pos_i != 0 && maze->map[maze->pos_i - 1][maze->pos_j - 1] == '*')
	|| (maze->pos_i != maze->height - 1 &&
	maze->map[maze->pos_i + 1][maze->pos_j - 1] == '*') ||
	(maze->map[maze->pos_i][maze->pos_j - 2] == '*')))
		return (0);
	return (1);
}

int *get_possibility(maze_t *maze, int *tab)
{
	tab[0] = get_up_possibility(maze);
	tab[1] = get_right_possibility(maze);
	tab[2] = get_down_possibility(maze);
	tab[3] = get_left_possibility(maze);
	tab[4] = tab[0] + tab[1] + tab[2] + tab[3];
}
