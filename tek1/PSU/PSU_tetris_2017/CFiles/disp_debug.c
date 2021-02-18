/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** disp_debug.c
*/

#include "../include/all.h"

void disp_key(char key)
{
	if (key > 32) {
		write(1, &key, 1);
		return;
	}
	if (key == ' ') {
		write(1, "(space)", 7);
		return;
	}
	if (key < 0) {
		write(1, "^E", 2);
		return;
	}
}

static void disp_tetriminos(tetrimino_t *tetri)
{
	my_putstr_fd("Tetriminos :  Name ", 1);
	my_putstr_fd(tetri->name, 1);
	if (tetri->error == 1) {
		my_putstr_fd(" :  Error\n", 1);
		return;
	}
	my_putstr_fd("\n", 1);
}

static void disp_debug2(my_game_t *game)
{
	my_putstr_fd("*", 1);
	my_put_nbr(game->option->map_col);
	my_putstr_fd("\nTetriminos :  ", 1);
	my_put_nbr(game->nbr_piece);
	my_putstr_fd("\n", 1);
	for (int i = 0 ; i < game->nbr_piece ; i++)
		disp_tetriminos(game->tab[i]);
}

void disp_debug(my_game_t *game)
{
	my_putstr_fd("*** DEBUG MODE ***\nKey Left :  ", 1);
	disp_key(game->option->left);
	my_putstr_fd("\nKey Right :  ", 1);
	disp_key(game->option->right);
	my_putstr_fd("\nKey Turn :  ", 1);
	disp_key(game->option->turn);
	my_putstr_fd("\nKey Drop :  ", 1);
	disp_key(game->option->drop);
	my_putstr_fd("\nKey Quit :  ", 1);
	disp_key(game->option->quit);
	my_putstr_fd("\nKey Pause :  ", 1);
	disp_key(game->option->pause);
	my_putstr_fd("\nNext :  ", 1);
	my_putstr_fd((game->option->hide == 0) ? ("Yes") : ("No"), 1);
	my_putstr_fd("\nLevel :  ", 1);
	my_put_nbr(game->option->level);
	my_putstr_fd("\nSize :  ", 1);
	my_put_nbr(game->option->map_row);
	disp_debug2(game);
	my_putstr_fd("Press any key to start Tetris", 1);
}
