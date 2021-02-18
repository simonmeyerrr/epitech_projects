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

static char* get_map_line(int fd, int len)
{
	char* buffer = malloc(sizeof(char*) * (len + 1));
	int ret;

	if (fd < 0) {
		endwin();
		write(2, "Can't open the map.\n", 20);
		exit (84);
	}
	ret = read(fd, buffer, len + 1);
	if (ret <= 0) {
		write(2, "Error while reading the map.\n", 29);
		exit (84);
	}
	if (buffer[len] != '\n') {
		endwin();
		write(2, "Invalid map.\n", 13);
		exit (84);

	}
	buffer[len] = '\0';
	return (buffer);
}

static int check_valid(char** map)
{
	int player = 0;
	int place = 0;
	int box = 0;

	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int  j = 0 ; map[i][j] != '\0' ; j++) {
			(map[i][j] != 'P' && map[i][j] != 'O' && map[i][j] !=
			'X' && map[i][j] != '#' && map[i][j] != ' ') ?
			(player = 3) : (0);
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
	int fd = open(path, O_RDONLY);
	char** map = malloc(sizeof(char**) * (height + 1));

	for (int i = 0 ; i < height ; i++)
		map[i] = get_map_line(fd, len);
	map[height] = NULL;
	close(fd);
	if (check_valid(map) == 0) {
		endwin();
		write(2, "Invalid map.\n", 13);
		exit (84);
	}
	return (map);
}
