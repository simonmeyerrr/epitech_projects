/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** read_next_n_bytes.c
*/

#include "include/all.h"

char *get_sentence_chunk_by_chunk(void)
{
	static int i = 0;
	char *str = "Hello my name is Chucky. Do you want to be my friend?";
	char *ret = malloc(sizeof(char*) * 6);

	if (str[i] == '\0')
		return (NULL);
	for (int j = 0 ; j < 5 && str[i] != '\0' ; j++) {
		ret[j] = str[i];
		i++;
	}
	ret[5] = '\0';
	return (ret);
}
