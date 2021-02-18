/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** utils_string.c
*/

#include <stdlib.h>

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

	if (!s1 || !s2) {
		if (!s1 && !s2)
			return (0);
		else if (!s1)
			return (-1);
		else
			return (1);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (!s1 || !s2) {
		if (!s1 && !s2)
			return (0);
		else if (!s1)
			return (-1);
		else
			return (1);
	}
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

char *my_strcat(char *s1, char *s2)
{
	int i = 0;
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	char *new = malloc(sizeof(char) * (len1 + len2 + 1));

	if (!new)
		return (NULL);
	for (int j = 0 ; j < len1 ; j++) {
		new[i] = s1[j];
		i++;
	}
	for (int j = 0 ; j < len2 ; j++) {
		new[i] = s2[j];
		i++;
	}
	new[i] = '\0';
	return (new);
}
