/*
** EPITECH PROJECT, 2017
** getnextline
** File description:
** getnextline.c
*/

#include "get_next_line.h"

static char *my_strcat(char *s1, char *s2)
{
	int len = 0;
	char *new;
	int j = 0;

	for (int i = 0 ; s1 != NULL && s1[i] != '\0'; i++)
		len++;
	new = malloc(sizeof(char*) * (len + READ_SIZE + 1));
	if (new == NULL)
		return (NULL);
	for (int i = 0 ; s1 != NULL && s1[i] != '\0' ; i++) {
		new[j] = s1[i];
		j++;
	}
	for (int i = 0 ; s2 != NULL && s2[i] != '\0' && i < READ_SIZE ; i++) {
		new[j] = s2[i];
		j++;
	}
	new[j] = '\0';
	(s1) ? (free(s1)) : (0);
	return (new);
}

char *end_str(char *str)
{
	char *new;

	if (str)
		return (str);
	new = malloc(sizeof(char*));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}

static char *get_rest(char *buffer, int end, int len1, int *tab)
{
	char *rest;
	int len = READ_SIZE - end;

	if (len1 < end)
		return (NULL);
	rest = malloc(sizeof(char*) * (len + 2));
	if (rest == NULL)
		return (NULL);
	for (int i = 0 ; end + i + 1 < tab[0] && i < len  && buffer[end + i + 1]
	>= 0 ; i++)
		rest[i] = buffer[end + i + 1];
	rest[len - 1] = '\0';
	return (rest);
}

char *search_end(char **str, char *buffer, char **ret, int *tab)
{
	int len = 0;

	if (buffer == NULL)
		return (*str);
	for (int i = 0 ; i < tab[0] && buffer[i] != '\0' ; i++)
		len++;
	for (int i = 0 ; i < tab[0] && tab[1] == -1 && buffer[i] != '\0'; i++) {
		if (buffer[i] == '\n') {
			tab[1] = i;
			buffer[i] = '\0';
		}
	}
	*str = my_strcat(*str, buffer);
	if (tab[1] != -1) {
		*ret = end_str(*str);
		return (get_rest(buffer, tab[1], len, tab));
	}
	return (*str);
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char*) * (READ_SIZE + 2));
	static char *str = NULL;
	char *ret = NULL;
	int tab[2] = {READ_SIZE, -1};

	if (fd < 0 || READ_SIZE <= 0 || buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	str = search_end(&str, buffer, &ret, tab);
	while (tab[0] == READ_SIZE && ret == NULL && tab[1] == -1) {
		tab[0] = read(fd, buffer, READ_SIZE);
		if (tab[0] < 0)
			return (NULL);
			buffer[tab[0]] = '\0';
		str = search_end(&str, buffer, &ret, tab);
	}
	free(buffer);
	return (ret);
}
