/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** string_func.c
*/

#include "all.h"

sfVector2f create_vector(float x, float y)
{
	sfVector2f vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

int my_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
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

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char *pourcent_to_str(int pc)
{
	char *str = malloc(sizeof(char*) * 4);

	str[0] = pc / 10 + 48;
	str[1] = pc % 10 + 48;
	str[2] = '%';
	str[3] = '\0';
	return (str);
}
