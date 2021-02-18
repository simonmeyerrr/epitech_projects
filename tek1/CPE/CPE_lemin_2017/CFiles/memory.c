/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** memory.c
*/

#include "../include/all.h"

int verif_malloc(void *ptr)
{
	if (ptr)
		return (1);
	return (0);
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

int my_tab_len(char **tab)
{
	int len = 0;

	while (tab && tab[len])
		len++;
	return (len);
}
