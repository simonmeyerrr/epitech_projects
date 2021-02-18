/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** open_map.c
*/

#include "all.h"

void free_map(char **map)
{
	if (map == NULL)
		return;
	for (int  i = 0 ; i < 10 ; i++) {
		if (map[i] != NULL)
			free(map[i]);
	}
	free(map);
}

static int is_map_valid(char **map)
{
	int len = my_strlen(map[0]);
	int player = 0;
	int end = 0;

	for (int i = 0 ; i < 10 ; i++) {
		if (my_strlen(map[i]) != len)
			return (0);
	}
	for (int i = 0 ; i < 10 ; i++) {
		for (int j = 0 ; map[i][j] != '\0' ; j++) {
			(map[i][j] == 'P') ? (player = player + 1) : (0);
			(map[i][j] == 'E') ? (end = end + 1) : (0);
			if (map[i][j] == 'P' && j != 2)
				return (0);
			if (INVALID_BLOCK(map[i][j]))
				return (0);
		}
	}
	return ((player != 1 || end != 1) ? (0) : (1));
}

static int get_map_width(char *path_map, int *error)
{
	int fd = open(path_map, O_RDONLY);
	int width = 0;
	char *buffer = malloc(sizeof(char*));
	int ret = read(fd, buffer, 1);

	while (ret == 1 && buffer[0] != '\n') {
		width++;
		ret = read(fd, buffer, 1);
	}
	if (ret != 1)
		*error = 1;
	close(fd);
	free(buffer);
	return (width);
}

static char** load_map(char *path_map, int *error)
{
	int width = get_map_width(path_map, error);
	char **map = malloc(sizeof(char**) * 11);
	int fd = open(path_map, O_RDONLY);

	for (int i = 0 ; i < 10 ; i++) {
		map[i] = malloc(sizeof(char*) * (width + 1));
		if (read(fd, map[i], width + 1) != width + 1) {
			my_putstr_fd("Error while reading the map.\n", 2);
			*error = 1;
			return (NULL);
		}
		map[i][width] = '\0';
	}
	map[10] = NULL;
	close(fd);
	return (map);
}

char** open_map(char *path_map, int *error)
{
	int fd = open(path_map, O_RDONLY);
	char **map;

	if (fd < 0) {
		my_putstr_fd("Can't open the map.\n", 2);
		*error = 1;
		return (NULL);
	}
	close(fd);
	map = load_map(path_map, error);
	if (*error != 0)
		return (NULL);
	if (is_map_valid(map) == 0) {
		my_putstr_fd("Invalid map format.\n", 2);
		*error = 1;
		return (NULL);
	}
	return (map);
}
