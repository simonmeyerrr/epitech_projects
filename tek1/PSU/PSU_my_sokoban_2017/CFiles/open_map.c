/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** open_map.c
*/

#include "all.h"

static int map_height(char* path)
{
	int fd = open(path, O_RDONLY);
	int ret;
	int height = 0;
	char *buffer = malloc(sizeof(char*));

	if (fd < 0) {
		endwin();
		write(2, "Can't open the map.\n", 20);
		exit (84);
	}
	ret = read(fd, buffer, 1);
	while(ret > 0) {
		if (buffer[0] == '\n')
			height++;
		ret = read(fd, buffer, 1);
	}
	free(buffer);
	close(fd);
	return (height);
}

static int map_width(char* path)
{
	int fd = open(path, O_RDONLY);
	int ret;
	int len = 0;
	char *buffer = malloc(sizeof(char*));

	if (fd < 0) {
		endwin();
		write(2, "Can't open the map.\n", 20);
		exit (84);
	}
	ret = read(fd, buffer, 1);
	while(ret > 0 && buffer[0] != '\n') {
		len++;
		ret = read(fd, buffer, 1);
	}
	free(buffer);
	close(fd);
	return (len);
}

static char* get_map_line(FILE *fd)
{
	char *buffer;
	char *line = malloc(sizeof(char*) * 100);
	size_t n;

	if (fd < 0) {
		endwin();
		write(2, "Can't open the map.\n", 20);
		exit (84);
	}
	getline(&buffer, &n, fd);
	for (int i = 0 ; buffer[i] != '\n' ; i++) {
		line[i] = buffer[i];
		line[i + 1] = '\0';
	}
	return (line);
}

static int check_valid(char** map)
{
	int player = 0;
	int place = 0;
	int box = 0;

	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int  j = 0 ; map[i][j] != '\0' ; j++) {
			(map[i][j] != 'P' && map[i][j] != 'O' && map[i][j] !=
			'X' && map[i][j] != '#' && map[i][j] != ' ' &&
			map[i][j] != '\n') ? (player = 3) : (0);
			(map[i][j] == 'P') ? (player++) : (0);
			(map[i][j] == 'O') ? (place++) : (0);
			(map[i][j] == 'X') ? (box++) : (0);
		}
	}
	if (player != 1 || place == 0 || place - box > 0)
		return (0);
	return (1);
}

char** open_map(char* path)
{
	int height = map_height(path);
	int len = map_width(path);
	FILE *fd = fopen(path, "r");
	char** map = malloc(sizeof(char**) * (height + 1));

	for (int i = 0 ; i < height ; i++) {
		map[i] = get_map_line(fd);
	}
	map[height] = NULL;
	if (check_valid(map) == 0) {
		endwin();
		write(2, "Invalid map.\n", 13);
		exit (84);
	}
	return (map);
}
