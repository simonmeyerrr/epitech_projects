/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** str_function.c
*/

#include "all.h"

int my_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char *my_strdup(char *str)
{
	char *new;
	char len;

	if (!str)
		return (NULL);
	len = my_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	verif_malloc(new);
	for (int i = 0 ; str[i] != '\0' ; i++)
		new[i] = str[i];
	new[len] = '\0';
	return (new);
}

char *my_putstr_fd(char *str, int fd, int back)
{
	if (!str) {
		if (back)
			write(fd, "\n", 1);
		return (NULL);
	}
	write(fd, str, my_strlen(str));
	if (back)
		write(fd, "\n", 1);
	return (str);
}
