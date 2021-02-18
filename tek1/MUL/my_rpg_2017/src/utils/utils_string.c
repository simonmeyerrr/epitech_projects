/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** utils_string.c
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
	int len = my_strlen(s1);
	char *s2 = malloc(sizeof(char) * (len + 1));

	if (!s2)
		return (NULL);
	for (int i = 0 ; s1 && s1[i] ; i++)
		s2[i] = s1[i];
	s2[len] = '\0';
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

char *my_strcat(char *s1, char *s2)
{
	char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	int i = 0;

	if (!str)
		return (NULL);
	for (int j = 0 ; s1 && s1[j] ; j++) {
		str[i] = s1[j];
		i++;
	}
	for (int j = 0 ; s2 && s2[j] ; j++) {
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
