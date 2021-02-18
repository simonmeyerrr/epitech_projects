/*
** EPITECH PROJECT, 2017
** cat.c
** File description:
** reproduce the cat's shell command
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int my_cat(int ac, char *str)
{
	char buffer[30000];
	int fd;
	int size;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (84);
	size = read(fd, buffer, 29999);
	write(1, &buffer, size);
	close(fd);
}

int main(int ac, char **av)
{
	for (int i = 1 ; i < ac ; i++) {
		my_cat(ac, av[i]);
		write(1, "\n", 1);
	}
	return (0);
}
