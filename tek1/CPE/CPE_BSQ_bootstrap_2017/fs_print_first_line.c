/*
** EPITECH PROJECT, 2017
** bootstrap BSQ
** File description:
** fs_print_first_line
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void fs_print_first_line(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);
	int ret;
	char *buffer = malloc(sizeof(char));

	buffer[0] = '0';
	if (fd < 0) {
		free(buffer);
		return;
	}
	ret = read(fd, buffer, 1);
	while(buffer[0] != '\0' && buffer[0] != '\n' && ret > 0) {
		write(1, buffer, 1);
		ret = read(fd, buffer, 1);
	}
	close(fd);
	free(buffer);
}
