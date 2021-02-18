/*
** EPITECH PROJECT, 2017
** head
** File description:
** util_string.c
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

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char *my_strdup(char *str)
{
	int len = my_strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	for (int i = 0 ; str && new && str[i] ; i++)
		new[i] = str[i];
	if (new)
		new[len] = '\0';
	return (new);
}

int my_get_nbr(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	if (str && str[0] == '-') {
		sign = -1;
		i++;
	}
	while (str && str[i]) {
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (sign * nb);
}
