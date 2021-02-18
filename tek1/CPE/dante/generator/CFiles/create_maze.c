/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** create_maze.c
*/

#include "../include/all.h"

void display_maze(maze_t *maze)
{
	for (int i = 0 ; i < maze->height ; i++) {
		maze->map[i][maze->width] = '\n';
		write(1, maze->map[i],
		maze->width + ((i == maze->height - 1) ? (0) : (1)));
		maze->map[i][maze->width] = '\0';
	}
}

static char **init_map(int width, int height)
{
	char **map = malloc(sizeof(char*) * (height + 1));

	verif_malloc(map);
	for (int i = 0 ; i < height ; i++) {
		map[i] = malloc(sizeof(char) * (width + 1));
		verif_malloc(map[i]);
		memset(map[i], 'X', width);
		map[i][width] = '\0';
	}
	map[height] = NULL;
	return (map);
}

static maze_t *init_maze(int width, int height)
{
	maze_t *maze = malloc(sizeof(*maze));

	verif_malloc(maze);
	if (width <= 0 || height <= 0) {
		write(2, "Positive number expected.\n", 26);
		exit(84);
	}
	maze->map = init_map(width, height);
	maze->width = width;
	maze->height = height;
	maze->pos_i = 0;
	maze->pos_j = 0;
	maze->way = NULL;
	return (maze);
}

static void add_end(maze_t *maze)
{
	if (maze->width >= 2 &&
	maze->map[maze->height - 1][maze->width - 3] == '*')
		maze->map[maze->height - 1][maze->width - 2] = '*';
	else if (maze->height >= 2)
		maze->map[maze->height - 2][maze->width - 1] = '*';
}

void create_maze(int width, int height, int perfect)
{
	maze_t *maze = init_maze(width, height);

	maze->map[0][0] = '*';
	if (maze->width > 1 && maze->height > 1)
		maze->map[maze->height - 2][maze->width - 2] = '*';
	maze->map[maze->height - 1][maze->width - 1] = '*';
	srand(time(NULL));
	generate_maze(maze);
	add_end(maze);
	if (width == 3 && height == 3)
		maze->map[0][1] = '*';
	make_maze_imperfect(maze, perfect);
	display_maze(maze);
	my_free_maze(maze);
}
