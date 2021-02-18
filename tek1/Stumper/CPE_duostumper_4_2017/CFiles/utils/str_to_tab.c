/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** str_to_tab.c
*/

#include <stdlib.h>
#include "proto.h"

static int is_char_sep(char c, char *sep)
{
	for (int i = 0 ; sep && sep[i] ; i++) {
		if (c == sep[i])
			return (1);
	}
	return (0);
}

static char *get_word(char *str, int *i, char *sep)
{
	int len = 0;
	char *word = NULL;

	if (str[*i] == '\0')
		return (NULL);
	for (int j = *i ; is_char_sep(str[j], sep) == 0 && str[j] != '\0' ; j++)
		len++;
	word = malloc(sizeof(char) * (len + 2));
	if (!word)
		return (NULL);
	for (int j = 0 ; is_char_sep(str[*i], sep) == 0 &&
	str[*i] != '\0' ; j++) {
		word[j] = str[*i];
		word[j + 1] = '\0';
		*i = *i + 1;
	}
	return (word);
}

static int count_word(char *str, char *sep)
{
	int word = 0;
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0') {
		for (i = i ; is_char_sep(str[i], sep) == 1 ; i++);
		word = (str[i] != '\0') ? (word + 1) : (word);
		for (i = i ; is_char_sep(str[i], sep) == 0 && str[i] ; i++);
	}
	return (word);
}

char **str_to_tab(char *str, char *sep)
{
	int word = count_word(str, sep);
	char **tab = (word > 0) ? (malloc(sizeof(char*) * (word + 1))) : (NULL);
	int i = 0;
	int j = 0;

	if (word <= 0 || !tab)
		return (NULL);
	while (j < word) {
		for (i = i ; is_char_sep(str[i], sep) == 1 ; i++);
		tab[j] = get_word(str, &i, sep);
		j = (tab[j] != NULL) ? (j + 1) : (j);
	}
	tab[j] = NULL;
	return (tab);
}
