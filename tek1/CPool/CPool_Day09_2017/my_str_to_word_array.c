/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** split a string into words
*/

#include <stdlib.h>

int alphanum(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

int separator(char const *str)
{
	int sep = 0;

	for (int i = 1 ; str[i] != '\0' ; i++) {
		if (alphanum(str[i]) == 0 && alphanum(str[i - 1]) == 1)
			sep++;
	}
	return (sep);
}

char *whilean(char const *str, int *i)
{
	int wordlen = 0;

	for (int j = *i ; alphanum(str[j]) == 1 ; j++)
		wordlen++;
	char *word = malloc(sizeof(char) * (wordlen + 2));
	for (int j = 0 ; j < wordlen ; j++) {
		word[j] = str[*i];
		*i = *i + 1;
	}
	word[wordlen] = '\0';
	return (word);
}

int whilesep(char const *str, int i)
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
	char **array = malloc(sizeof(char*) * (separator(str) + 2));
	int t = 0;
	int i = 0;

	while (str[i] != '\0') {
		i = whilesep(str, i);
		array[t] = whilean(str, &i);
		t++;
	}
	if (alphanum(str[i - 1]) == 0)
	    t = t - 1;
	array[t] = 0;
	return (array);
}
