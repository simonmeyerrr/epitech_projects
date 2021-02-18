/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** main.c
*/

#include "all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

void my_putstr_fd(char *str, int fd)
{
	if (str && fd >= 0)
		write(fd, str, my_strlen(str));
}

char *my_strdup(char *s1)
{
	int len = 0;
	char *s2;

	while (s1 && s1[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	s2[len] = '\0';
	for (int i = 0 ; s1 && s1[i] ; i++)
		s2[i] = s1[i];
	return (s2);
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

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (!s1 || !s2 || n <= 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}
