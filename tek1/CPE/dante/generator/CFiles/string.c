/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** string.c
*/

#include "../include/all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

void my_putstr_fd(char *str, int fd)
{
	write(fd, str, my_strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2) {
		if (!s1 && !s2)
			return (0);
		if (!s1)
			return (-1);
		if (!s2)
			return (1);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int my_getnbr(char *str)
{
	int nb = 0;

	for (int i = 0 ; str && str[i] ; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}
