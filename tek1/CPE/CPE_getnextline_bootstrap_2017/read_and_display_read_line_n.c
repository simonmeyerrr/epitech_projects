/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** read_and_display_read_line_n.c
*/

#include "include/all.h"

void read_and_display_read_line_n(int fd, int n)
{
	char *buffer;
	int end = 0;

	if (fd < 0)
		return;
	buffer = malloc(sizeof(char*) * n);
	while (read(fd, buffer, n) > 0 && end == 0) {
		for (int i = 0 ; i < n && end == 0 ; i++) {
			(buffer[i] == '\0' || buffer[i] == '\n') ? (end = 1) :
			write(1, &(buffer[i]), 1);
		}
	}
	free(buffer);
}
