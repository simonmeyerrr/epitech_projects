/*
** EPITECH PROJECT, 2017
** bootstrap BSQ
** File description:
** fs_open_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);

	if (fd < 0)
		write(1, "FAILURE\n", 8);
	else
		write(1, "SUCCESS\n", 8);
	return (fd);
}
