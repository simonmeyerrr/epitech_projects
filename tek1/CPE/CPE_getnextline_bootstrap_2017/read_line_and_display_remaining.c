/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** read_line_and_display_remaining.c
*/

#include "include/all.h"

static char *my_realloc(char *part1, int size1, char *part2, int size2)
{
	char *new = malloc(sizeof(char*) * (size1 + size2 + 1));
	int j = 0;

	for (int i = 0 ; part1 != NULL && i < size1 ; i++) {
		new[j] = part1[i];
		j++;
	}
	for (int i = 0 ; i < size2 && part2[i] != '\0' ; i++) {
		new[j] = part2[i];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char *read_line_and_display_remaining(int fd, int n)
{
	char *str = NULL;
	int size = 0;
	int end = 0;
	char *buffer = malloc(sizeof(char*) * n);
	int ret;

	if (fd < 0)
		return (NULL);
	while (read(fd, buffer, n) > 0 && end == 0) {
		str = my_realloc(str, size, buffer, n);
		size += n;
		for (int i = 0 ; i < size && str[i] != '\0' && end == 0; i++) {
			(str[i] == '\n') ? (end = i + 1) : (0);
			(str[i] == '\n') ? (str[i] = '\0') : (0);
		}
	}
	for (int i = end ; str[i] != '\0' && i < size ; i++)
		write(1, &(str[i]), 1);
	return (str);
}
