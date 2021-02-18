/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** play_game.c
*/

#include "../include/all.h"

void free_game(my_game_t *game)
{
	my_free(game->option);
	for (int i = 0 ; i < game->nbr_piece ; i++) {
		my_free(game->tab[i]->name);
		my_free(game->tab[i]);
	}
	my_free(game->tab);
	my_free(game);
}

void disp_game(my_game_t *game)
{
	printw("Press %c to exit.", game->option->quit);
}

void manage_touch(my_game_t *game)
{
	char c = getch();

	if (c == game->option->quit)
		game->exit = 1;
}

void prepare_game(my_game_t *game)
{
	game->exit = 0;
}

void play_game(my_game_t *game)
{
	initscr();
	curs_set(0);
	prepare_game(game);
	clear();
	if (LINES < game->option->map_row + 2 ||
	COLS < game->option->map_col + 34)
		mvprintw(LINES / 2, COLS / 2 - 7, "Please resize");
	else
		disp_game(game);
	refresh();
	endwin();
}
