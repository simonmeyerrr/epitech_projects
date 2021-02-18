/*
** EPITECH PROJECT, 2017
** bootstrap BSQ
** File description:
** fs_cat_x_bytes
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void fs_cat_x_bytes(char const *filepath, int x)
{
	int fd = open(filepath, O_RDONLY);
	int ret;
	char *buffer = malloc(sizeof(char) * x);

	if (fd < 0) {
		free(buffer);
		return;
	}
	ret = read(fd, buffer, x);
	if (ret > 0)
		write(1, buffer, ret);
	close(fd);
	free(buffer);
}
