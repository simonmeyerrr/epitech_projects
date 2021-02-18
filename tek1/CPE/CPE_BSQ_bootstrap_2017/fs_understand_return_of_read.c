/*
** EPITECH PROJECT, 2017
** bootstrap BSQ
** File description:
** fs_understand_return_of_read
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
	int ret = read(fd, buffer, size);

	if (ret == -1)
		write(1, "read failed\n", 12);
	if (ret == 0 && ret != size)
		write(1, "read has nothing more to read\n", 30);
	if (ret < size && ret != 0)
		write(1, "read didn’t complete the entire buffer\n", 39);
	if (ret == size)
		write(1, "read completed the entire buffer\n", 33);
}
