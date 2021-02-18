/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** make_maze_imperfect.c
*/

#include "../include/all.h"

static int imperfect_possibility(maze_t *maze, int i, int j)
{
	int pos = 0;

	if (i > 0 && maze->map[i - 1][j] == '*')
		pos++;
	if (i < maze->height - 1 && maze->map[i + 1][j] == '*')
		pos++;
	if (j > 0 && maze->map[i][j - 1] == '*')
		pos++;
	if (j < maze->width - 1 && maze->map[i][j + 1] == '*')
		pos++;
	return (pos);
}

static int add_way(maze_t *maze, int i, int j, int add)
{
	int pos = 0;

	if (maze->map[i][j] == '*')
		return (add);
	pos = imperfect_possibility(maze, i, j);
	if (pos < 2)
		return (add);
	if (add % 10 == 0)
		maze->map[i][j] = '*';
	return (add + 1);
}

void make_maze_imperfect(maze_t *maze, int perfect)
{
	int add = 0;

	if (perfect == 1)
		return;
	for (int i = 0 ; i < maze->height ; i++) {
		for (int j = 0 ; j < maze->width ; j++)
			add = add_way(maze, i, j, add);
	}
}
