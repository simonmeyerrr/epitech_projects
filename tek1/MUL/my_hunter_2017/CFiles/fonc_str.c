/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** function for strings
*/

#include "all.h"

static int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char *my_strdup(char *src)
{
	char *dest;
	int i = 0;
	int lensrc = my_strlen(src);

	dest = malloc(sizeof(char) * (lensrc + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
