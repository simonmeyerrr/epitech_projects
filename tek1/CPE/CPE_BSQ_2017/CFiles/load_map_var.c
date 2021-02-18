/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** main.c
*/

#include "all.h"

static int get_size_x(int fd)
{
	int ret;
	int nb = 0;
	char *buffer = malloc(sizeof(char*));

	buffer[0] = '0';
	if (fd < 0) {
		free(buffer);
		exit (84);
	}
	ret = read(fd, buffer, 1);
	while(buffer[0] != '\n' && ret > 0) {
		if (buffer[0] != '.' && buffer[0] != 'o')
			exit(84);
		nb++;
		ret = read(fd, buffer, 1);
	}
	free(buffer);
	return (nb);
}

static int get_nbr_first_line(int fd)
{
	int ret;
	int nb = 0;
	char *buffer = malloc(sizeof(char*));

	buffer[0] = '0';
	if (fd < 0) {
		free(buffer);
		exit (84);
	}
	ret = read(fd, buffer, 1);
	while(buffer[0] != '\n' && ret > 0) {
		if (buffer[0] < '0' || buffer[0] > '9')
			exit(84);
		nb = nb * 10 + buffer[0] - '0';
		ret = read(fd, buffer, 1);
	}
	free(buffer);
	return (nb);
}

static int init_struct(char* path, my_var_t* var)
{
	int fd = open(path, O_RDONLY);

	if (fd < 0)
		exit (84);
	var->size_y = get_nbr_first_line(fd);
	var->size_x = get_size_x(fd);
	var->x = 0;
	var->y = 0;
	var->size = 0;
	close (fd);
	return (0);
}

static char* line_to_str(int fd, my_var_t* var)
{
	char* map = malloc(sizeof(char*) * (var->size_x + 1));
	int ret = read(fd, map, var->size_x + 1);

	if (ret < 0)
		exit (84);
	map[var->size_x] = '\0';
	return (map);
}

char** load_map_var(char* path, my_var_t* var)
{
	int i = init_struct(path, var);
	char** map = malloc(sizeof(char**) * (var->size_y + 1));
	int fd = open(path, O_RDONLY);

	if (fd < 0)
		exit(84);
	get_nbr_first_line(fd);
	for (int i = 0 ; i < var->size_y ; i++)
		map[i] = line_to_str(fd, var);
	map[var->size_y] = NULL;
	close(fd);
	return (map);
}
