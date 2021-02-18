/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** my_str_to_word_array.c
*/

#include "all.h"

static char *get_word(char *str, int *i, char c)
{
	int len = 0;
	char *word;

	if (str[*i] == '\0')
		return (NULL);
	for (int j = *i ; str[j] != '\t' && str[j] != c && str[j] != '\0' ; j++)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	verif_malloc(word);
	for (int j = 0 ; str[*i] != '\t' && str[*i] != '\0' && str[*i] != c ;
	j++) {
		word[j] = str[*i];
		word[j + 1] = '\0';
		*i = *i + 1;
	}
	return (word);
}

static int count_word(char *str, char c)
{
	int word = 0;
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0') {
		for (i ; str[i] == c  || str[i] == '\t' ; i++);
		word = (str[i] != '\0') ? (word + 1) : (word);
		for (i ; str[i] != c && str[i] != '\t' && str[i] != '\0' ; i++);
	}
	return (word);
}

char **my_str_to_word_array(char *str, char c)
{
	int word = count_word(str, c);
	char **tab = (word > 0) ? (malloc(sizeof(char*) * (word + 1))) : (NULL);
	int i = 0;
	int j = 0;

	if (word <= 0)
		return (NULL);
	verif_malloc(tab);
	while (str[i] != '\0' && j < word) {
		for (i ; str[i] == c  || str[i] == '\t' ; i++);
		tab[j] = get_word(str, &i, c);
		j = (tab[j] != NULL) ? (j + 1) : (j);
	}
	tab[j] = NULL;
	return (tab);
}
