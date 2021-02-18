/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** create_maze.c
*/

#include <time.h>
#include <string.h>
#include "../include/all.h"

void display_maze(maze_t *maze)
{
	for (int i = 0 ; i < maze->height ; i++) {
		for (int j = 0 ; j < maze->width ; j++) {
			(maze->map[i][j] == 'p') ?
			(maze->map[i][j] = '*') : (0);
		}
	}
	for (int i = 0 ; i < maze->height - 1 ; i++) {
		maze->map[i][maze->width] = '\n';
		write(1, maze->map[i], maze->width + 1);
		maze->map[i][maze->width] = '\0';
	}
	write(1, maze->map[maze->height - 1], maze->width);
}

static char **init_map(char *path)
{
	char **map;
	char *buffer;
	int fd;
	struct stat file;

	stat(path, &file);
	buffer = malloc(sizeof(char) * (file.st_size) + 1);
	fd = open(path, O_RDONLY);
	read(fd, buffer, file.st_size);
	buffer[file.st_size] = '\0';
	map = my_str_to_wordtab(buffer, '\n');
	return (map);
}

static maze_t *init_maze(char *path)
{
	maze_t *maze = malloc(sizeof(*maze));

	maze->map = init_map(path);
	maze->width = strlen(maze->map[0]);
	maze->height = my_tab_len(maze->map);
	maze->pos_i = 0;
	maze->pos_j = 0;
	maze->last_pos = NULL;
	return (maze);
}

int main(int ac, char **av)
{
	maze_t *maze = init_maze(av[1]);

	solve_maze(maze);
	display_maze(maze);
	return (MY_SUCCESS);
}
