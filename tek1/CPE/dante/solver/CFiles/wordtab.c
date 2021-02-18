/*
** EPITECH PROJECT, 2017
** solver
** File description:
** wordtab.c
*/

#include <string.h>
#include <stdlib.h>

static int len_line(char *str)
{
	int i = 0;

	while (str[i] != '\n')
		i++;
	return (i);
}

static int find_words(char *str, char sep)
{
	int i = 0;
	int words = 1;

	while (str[i] != '\0') {
		if (str[i] == sep)
			words++;
		i++;
	}
	return (words + 1);
}

char **my_str_to_wordtab(char *str, char sep)
{
	int i = 0;
	int j;
	int k = 0;
	char **tab = malloc(sizeof(char*) * (find_words(str, sep) + 1));
	int len = len_line(str);

	while (str[k] != '\0') {
		j = 0;
		tab[i] = malloc(sizeof(char) * (len + 1));
		while (str[k] != '\0' && str[k] != sep) {
			tab[i][j] = str[k];
			k++;
			j++;
		}
		tab[i][j] = '\0';
		if (str[k] != '\0')
			k++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
