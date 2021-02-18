/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** utils_string.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

int is_line_valid(char *line)
{
	if (my_strlen(line) <= 0)
		return (0);
	for (int i = 0 ; line && line[i] ; i++) {
		if (line[i] == ' ' || line[i] == '\t')
			return (0);
	}
	return (1);
}

char *get_hidden_word(hangman_t *hangman, char *word)
{
	char *hidden_word = malloc(sizeof(char) * (my_strlen(word) + 1));
	int i = 0;

	if (!hidden_word) {
		my_put_err("Error while using malloc.\n");
		hangman->error = 1;
		return (NULL);
	}
	while (word && word[i]) {
		hidden_word[i] = '*';
		i++;
	}
	hidden_word[i] = '\0';
	return (hidden_word);
}
