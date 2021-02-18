/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** main.c
*/

#include "struct.h"
#include "proto.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void display_stand(minicut_t *minicut)
{
	char *buffer;

	while ((buffer = get_next_line(0)) != NULL)
		display(minicut, buffer);
	free(buffer);
}

static void display_path(minicut_t *minicut, char *path)
{
	char **tab;
	char *buffer;
	int fd = open(path, O_RDONLY);
	struct stat info;

	if (fd < 0) {
		my_put_err("minicut: ");
		my_put_err(path);
		my_put_err(": No such file or directory\n");
		minicut->error = 1;
		return;
	}
	stat(path, &info);
	buffer = malloc(sizeof(char) * info.st_size + 1);
	read(fd, buffer, info.st_size);
	buffer[info.st_size] = '\0';
	tab = str_to_tab(buffer, "\n");
	my_free(buffer);
	for (int i = 0 ; tab && tab[i] != NULL ; i++)
		display(minicut, tab[i]);
	my_free_tab(tab);
}

void display_minicut(minicut_t *minicut)
{
	for (my_path_t *tmp = minicut->first_path ; tmp ; tmp = tmp->next)
		if (tmp->path[0] == '-')
			display_stand(minicut);
		else
			display_path(minicut, tmp->path);
	if (!minicut->first_path)
		display_stand(minicut);
}
