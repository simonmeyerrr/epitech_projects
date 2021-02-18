/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** memory.c
*/

#include "../include/all.h"

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void my_free_tab(char **tab)
{
	for (int i = 0 ; tab && tab[i] ; i++)
		free(tab[i]);
	my_free(tab);
}

void verif_malloc(void *ptr)
{
	if (!ptr) {
		my_putstr_fd("Error while using malloc.\n", 2);
		exit(MY_ERROR);
	}
}

void my_free_maze(maze_t *maze)
{
	if (!maze)
		return;
	my_free_tab(maze->map);
	my_free(maze);
}
