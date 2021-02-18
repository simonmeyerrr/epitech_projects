/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** get_next_line.c
*/

#include "all.h"

static char *my_strcat(char *s1, char *s2)
{
	char *new;
	int len = my_strlen(s1);

	new = malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	for (int i = 0 ; s1 && s1[i] != '\0' ; i++)
		new[i] = s1[i];
	new[len] = s2[0];
	new[len + 1] = '\0';
	if (s1)
		free(s1);
	return (new);
}

static char *end_str(char *str)
{
	char *new;

	if (str)
		return (str);
	new = malloc(sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '\0';
	return (new);
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char));
	char *str = NULL;
	int ret = 1;

	if (!buffer)
		return (NULL);
	while (ret == 1) {
		ret = read(fd, buffer, 1);
		if (ret < 0)
			return (NULL);
		if (ret == 1 && buffer[0] == '\n') {
			str = end_str(str);
			ret = 2;
		} else if (ret == 1)
			str = my_strcat(str, buffer);
	}
	if (buffer)
		free(buffer);
	return (str);
}
