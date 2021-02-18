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

int my_tab_len(char **tab)
{
	int len = 0;

	while (tab && tab[len])
		len++;
	return (len);
}
