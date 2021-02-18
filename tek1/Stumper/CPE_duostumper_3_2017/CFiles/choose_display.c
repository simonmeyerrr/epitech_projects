/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** choose_display.c
*/

#include "struct.h"
#include "proto.h"
#include <unistd.h>
#include <stdlib.h>

static char *create_delim(minicut_t *minicut)
{
	char *str = malloc(sizeof(char) * 2);

	str[0] = minicut->delimiter;
	str[1] = '\0';
	return (str);
}

static void char_type(minicut_t *minicut, char *str)
{
	int i = 0;

	for (; minicut->tab_length > i && minicut->nb_tab[i] != -1
	&& str && str[i] != '\0' ; i++) {
		if (minicut->nb_tab[i] == 1)
			write(1, &str[i], 1);
	}
	if (minicut->nb_tab[minicut->tab_length - 1] == -1) {
		for (; str && str[i] != '\0' ; i++)
			write(1, &str[i], 1);
	}
	write(1, "\n", 1);
}

static void field_type(minicut_t *minicut, char *str)
{
	int i = 0;
	char *delim = create_delim(minicut);
	char **tab = str_to_tab(str, delim);

	for (; minicut->tab_length > i && tab && tab[i]
	&& minicut->nb_tab[i] != -1 ; i++) {
		if (i != 0)
			write(1, delim, 1);
		if (minicut->nb_tab[i] == 1)
			my_putstr(tab[i]);
	}
	for (; minicut->nb_tab[minicut->tab_length - 1] == -1 && tab &&
	tab[i] ; i++) {
			write(1, delim, 1);
			my_putstr(tab[i]);
	}
	write(1, "\n", 1);
	my_free(delim);
	my_free_tab(tab);
}

void display(minicut_t *minicut, char *str)
{
	if (minicut->type == TYPE_CHAR)
		char_type(minicut, str);
	else if (minicut->type == TYPE_FIELD)
		field_type(minicut, str);
}
