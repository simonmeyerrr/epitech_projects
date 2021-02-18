/*
** EPITECH PROJECT, 2017
** my_grep.c
** File description:
** reproduce cat and grep shell command
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int disp_line(int i, char *buffer)
{
	
}

int search_str(int i, char *str, char *buffer)
{
	int grep = 1;
	while (buffer[i] != str[0] && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (i);
	for (int j = 0 ; str[j] != '\0' || grep = 1; j++) {
		if (str[j] != buffer[i])
			grep = 0;
	}
	if (grep == 1)
		i = disp_line(i, buffer);
	return (i);
}

int my_grep(char **av)
{
	char buffer[30000];
	int fd;
	int size;
	int i = 0;

	fd = open(av[2], O_RDONLY);
	if (fd == -1)
		return (84);
	size = read(fd, buffer, 29999);
	while (buffer[i] != '\0') {
		i = search_str(i, av[1], buffer);
	}
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (84);
	my_grep(av);
	return (0);
}
