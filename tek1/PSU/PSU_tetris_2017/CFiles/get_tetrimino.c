/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** get_tetrimino.c
*/

#include "../include/all.h"

static char *get_name(char *str)
{
	int i;
	int len = my_strlen(str);
	char *name = malloc(sizeof(char) * (len - 9));

	for (i = 0 ; i < len - 10 ; i++)
		name[i] = str[i];
	name[i] = '\0';
	return (name);
}

static void save_file(my_game_t *game, struct dirent *dir)
{
	int nb_p = game->nbr_piece;

	if (!game->tab)
		game->tab = malloc(sizeof(tetrimino_t));
	else
		game->tab = realloc(game->tab,
		sizeof(tetrimino_t) * (nb_p + 1));
	game->tab[nb_p] = malloc(sizeof(tetrimino_t));
	game->tab[nb_p]->error = 1;
	game->tab[nb_p]->name = get_name(dir->d_name);
	game->nbr_piece++;
}

static void check_ext(my_game_t *game, struct dirent *dir)
{
	char *file_name = dir->d_name;
	int len = my_strlen(file_name);

	if (len < 10)
		return;
	file_name += (len - 10);
	if (!my_strcmp(file_name, ".tetrimino"))
		save_file(game, dir);
}

static int read_files(my_game_t *game)
{
	struct dirent *dir;
	DIR *fd;

	if (!(fd = opendir("tetriminos")))
		return (EXIT_ERROR);
	while (dir = readdir(fd))
		check_ext(game, dir);
	closedir(fd);
	return (EXIT_SUCCESS);
}

void get_tetrimino(my_game_t *game)
{
	game->nbr_piece = 0;
	game->tab = NULL;
	if (read_files(game))
		return;
	while (tab_sorted(game))
		sort_tab(game);
}
