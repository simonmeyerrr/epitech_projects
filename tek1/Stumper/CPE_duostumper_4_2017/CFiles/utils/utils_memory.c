/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** utils_memory.c
*/

#include <stdlib.h>
#include "proto.h"
#include "macro.h"

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void my_free_tab(char **tab)
{
	for (int i = 0 ; tab && tab[i] ; i++)
		free(tab[i]);
	if (tab)
		free(tab);
}

int my_tab_len(char **tab)
{
	int len = 0;

	while (tab && tab[len])
		len++;
	return (len);
}

void verif_malloc(void *ptr)
{
	if (!ptr) {
		my_put_err("Error while using malloc.\n");
		exit(MY_ERROR);
	}
}
