/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** sort.c
*/

#include "../include/all.h"

int tab_sorted(my_game_t *game)
{
	int i;

	for (i = 0 ; i < game->nbr_piece - 1 ; i++)
		if (my_strcmp(game->tab[i]->name, game->tab[i + 1]->name) > 0)
			return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

void sort_tab(my_game_t *game)
{
	int i;
	tetrimino_t *tmp;

	for (i = 0 ; i < game->nbr_piece - 1 ; i++)
		if (game->tab[i]->name[0] > game->tab[i + 1]->name[0]) {
			tmp = game->tab[i];
			game->tab[i] = game->tab[i + 1];
			game->tab[i + 1] = tmp;
		}
}
