/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** json_parser.c
*/

#include "all.h"

static char *get_string(char *str, int *j)
{
	int len = 0;
	char *new = NULL;

	for (int i = *j ; str[i] && str[i] != '\"' ; i++)
		len++;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	for (int i = 0 ; str[*j] && str[*j] != '\"' ; i++) {
		new[i] = str[*j];
		*j = *j + 1;
	}
	new[len] = '\0';
	return (new);
}

static int count_string(char *str)
{
	int string = 0;

	for (int i = 0 ; str && str[i] ; i++)
		if (str[i] == '\"')
			string++;
	return (string / 2);
}

char **json_parser(char *str)
{
	int j = 0;
	int string = count_string(str);
	char **tab = malloc(sizeof(char*) * (string + 1));

	if (!string || !tab || string == 0)
		return (NULL);
	for (int i = 0 ; i < string ; i++) {
		for (j ; str[j] && str[j] != '\"' ; j++);
		j++;
		tab[i] = get_string(str, &j);
		j++;
	}
	tab[string] = NULL;
	return (tab);
}
