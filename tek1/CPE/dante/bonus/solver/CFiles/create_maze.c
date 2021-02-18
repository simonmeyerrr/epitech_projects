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
	for (int i = 0 ; i < maze->height ; i++) {
		maze->map[i][maze->width] = '\n';
		write(1, maze->map[i],
		maze->width + ((i == maze->height - 1) ? (0) : (1)));
		maze->map[i][maze->width] = '\0';
	}
}

static char **init_map(char *path)
{
	char **map = NULL;
	char *buffer;
	int fd;
	struct stat file;

	if (stat(path, &file) == -1)
		exit(84);
	buffer = malloc(sizeof(char) * (file.st_size) + 1);
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(84);
	if (read(fd, buffer, file.st_size) == -1)
		exit(84);
	buffer[file.st_size] = '\0';
	map = my_str_to_wordtab(buffer, '\n');
	if (!map)
		exit(84);
	check_maze_valid(map);
	return (map);
}

static maze_t *init_maze(char *path)
{
	maze_t *maze = malloc(sizeof(*maze));

	verif_malloc(maze);
	maze->map = init_map(path);
	maze->width = strlen(maze->map[0]);
	maze->height = my_tab_len(maze->map);
	maze->pos_i = 0;
	maze->pos_j = 0;
	maze->last_pos = NULL;
	maze->end_found = 0;
	return (maze);
}

void create_maze(char *path)
{
	maze_t *maze = init_maze(path);

	initscr();
	start_color();
	use_default_colors();
	curs_set(0);
	solve_maze(maze);
	endwin();
	if (maze->end_found == 1)
		display_maze(maze);
	else
		printf("no solution found\n");
	my_free_maze(maze);
}
