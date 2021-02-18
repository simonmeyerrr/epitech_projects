/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** init_global.c
*/

#include "../include/all.h"

static char *get_word(char *str, int *i)
{
	int len = 0;
	char *new = NULL;

	for (int j = *i ; str[j] != ' ' && str[j] != '\t' && str[j] &&
	str[j] != '#' ; j++)
		len++;
	new = malloc(sizeof(char) * (len + 1));
	for (int j = 0 ; str[*i] != ' ' && str[*i] != '\t' && str[*i] &&
	str[*i] != '#' ; j++) {
		new[j] = str[*i];
		*i = *i + 1;
	}
	new[len] = '\0';
	return (new);
}

static int count_word(char *str)
{
	int i = 0;
	int nb_word = 0;

	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '#') {
		for (; str[i] == ' ' || str[i] == '\t' ; i++);
		for (; str[i] != ' ' && str[i] != '\t' && str[i] &&
		str[i] != '#' ; i++);
		if (str[i - 1] != ' ' && str[i - 1] != '\t')
			nb_word++;
	}
	return (nb_word);
}

char **str_to_tab(char *str)
{
	int nb_word = count_word(str);
	char **tab = malloc(sizeof(char*) * (nb_word + 1));
	int i = 0;
	int j = 0;

	if (nb_word <= 0 || !tab || !str) {
		my_free(tab);
		return (NULL);
	}
	while (j < nb_word) {
		for (; str[i] == ' ' || str[i] == '\t' ; i++);
		tab[j] = get_word(str, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
