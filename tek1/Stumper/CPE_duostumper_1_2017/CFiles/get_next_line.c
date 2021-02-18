/*
** EPITECH PROJECT, 2017
** head
** File description:
** get_next_line.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void my_put_error(char *str)
{
	write(2, str, my_strlen(str));
}

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

static char *combin_str(char *str, char c)
{
	char *dest = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	if (!dest)
		return (NULL);
	while (str && i < my_strlen(str)) {
		dest[i] = str[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	my_free(str);
	return (dest);
}

char *get_next_line(int fd)
{
	int ret = 1;
	char c = 1;
	char *str = NULL;

	while (ret == 1 && c != '\n' && c != '\0') {
		ret = read(fd, &c, 1);
		if (ret < 0) {
			my_free(str);
			return (NULL);
		}
		if (ret == 1)
			str = combin_str(str, c);
	}
	return (str);
}
