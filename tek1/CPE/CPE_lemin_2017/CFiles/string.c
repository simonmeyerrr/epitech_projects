/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** string.c
*/

#include "../include/all.h"

void my_putstr_fd(char *str, int fd)
{
	write(fd, str, my_strlen(str));
}

char *my_strdup(char *str)
{
	int len = my_strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	for (int i = 0 ; i < len ; i++)
		new[i] = str[i];
	new[len] = '\0';
	return (new);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
