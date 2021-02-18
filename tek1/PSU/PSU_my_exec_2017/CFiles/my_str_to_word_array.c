/*
** EPITECH PROJECT, 2017
** my_exec
** File description:
** my_str_to_word_array.c
*/

#include "all.h"

static int alphanum(char c)
{
	if (c != ' ' && c != '\0')
		return (1);
	else
		return (0);
}

static int separator(char const *str)
{
	int sep = 0;

	for (int i = 1 ; str[i] != '\0' ; i++) {
		if (alphanum(str[i]) == 0 && alphanum(str[i - 1]) == 1)
			sep++;
	}
	return (sep);
}

static char *whilean(char const *str, int *i)
{
	int wordlen = 0;

	for (int j = *i ; alphanum(str[j]) == 1 ; j++)
		wordlen++;
	if (wordlen == 0)
		return (NULL);
	char *word = malloc(sizeof(char) * (wordlen + 3));
	for (int j = 0 ; j < wordlen ; j++) {
		word[j] = str[*i];
		*i = *i + 1;
	}
	word[wordlen] = '\0';
	return (word);
}

static int whilesep(char const *str, int i)
{
	while(alphanum(str[i]) == 0) {
		if (str[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char **my_str_to_word_array(char const *str)
{
	char **array = malloc(sizeof(char**) * (separator(str) + 3));
	int t = 0;
	int i = 0;

	while (str[i] != '\0') {
		i = whilesep(str, i);
		array[t] = whilean(str, &i);
		t++;
	}
	array[t] = NULL;
	return (array);
}
