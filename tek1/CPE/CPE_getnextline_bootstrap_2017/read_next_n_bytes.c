/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** read_next_n_bytes.c
*/

#include "include/all.h"

char *read_next_n_bytes(int fd , int n)
{
	char *buffer;
	int ret;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char*) * n);
	if (read(fd, buffer, n) <= 0) {
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
