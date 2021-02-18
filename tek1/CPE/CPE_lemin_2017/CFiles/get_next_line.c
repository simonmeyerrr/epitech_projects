/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** init_global.c
*/

#include "../include/all.h"

int is_nb_valid(char *str)
{
	for (int i = 0 ; str && str[i] ; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

static char *add_char(char *str, char c)
{
	int len = my_strlen(str);
	char *new = malloc(sizeof(char) * (len + 2));

	if (!new)
		return (NULL);
	for (int i = 0 ; str && str[i] ; i++)
		new[i] = str[i];
	new[len] = c;
	new[len + 1] = '\0';
	my_free(str);
	return (new);
}

char *get_next_line(int fd)
{
	char *str = malloc(sizeof(char));
	char c = 1;
	int ret;

	if (!str)
		return (NULL);
	str[0] = '\0';
	while (c != '\n' && c != '\0') {
		ret = read(fd, &c, 1);
		if (ret <= 0) {
			my_free(str);
			return (NULL);
		}
		if (c != '\n' && c != '\0')
			str = add_char(str, c);
	}
	return (str);
}
