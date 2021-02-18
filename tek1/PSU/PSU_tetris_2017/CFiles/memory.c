/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** memory.c
*/

#include "../include/all.h"

void verif_malloc(void *ptr)
{
	if (!ptr) {
		endwin();
		my_putstr_fd("Error while using malloc.\n", 2);
		exit(EXIT_ERROR);
	}
}

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void my_free_tab(char **tab)
{
	for (int i = 0 ; tab && tab[i] ; i++)
		my_free(tab[i]);
	my_free(tab);
}
