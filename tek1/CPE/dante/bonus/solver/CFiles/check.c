/*
** EPITECH PROJECT, 2017
** dante solver
** File description:
** check.c
*/

#include "../include/all.h"

static int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

static void check_size(char **maze)
{
	int maze_len = my_strlen(maze[0]);
	int tab_len = my_tab_len(maze);

	if (tab_len <= 0) {
		write(2, "Invalid height.\n", 16);
		exit(84);
	}
	if (maze_len <= 0) {
		write(2, "Invalid length of line.\n", 23);
		exit(84);
	}
	for (int i = 0 ; maze && maze[i] != NULL ; i++)
		if (my_strlen(maze[i]) != maze_len) {
			write(2, "Invalid length of line.\n", 23);
			exit(84);
		}
}

static void check_char(char c)
{
	if (c != '*' && c != 'X') {
		write(2, "Invalid char.\n", 14);
		exit(84);
	}
}

static void is_maze_valid(char **maze)
{
	for (int i = 0 ; maze && maze[i] != NULL ; i++)
		for (int j = 0 ; maze[i][j] != '\0' ; j++)
			check_char(maze[i][j]);
}

void check_maze_valid(char **maze)
{
	check_size(maze);
	is_maze_valid(maze);
}
