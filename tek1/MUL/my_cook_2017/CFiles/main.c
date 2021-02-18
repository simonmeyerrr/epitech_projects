/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** main.c
*/

#include "all.h"

static void my_cook(int *error)
{
	game_t *game = init_game(error);

	if (!game || *error != 0)
		return;
	start_animation(game);
	main_menu(game);
	free_game(game);
}

static void usage(void)
{
	my_putstr_fd("My cook is a game created by Simon Meyer & Arnaud Sc", 1);
	my_putstr_fd("heid with de CSFML library.\n\nUSAGE:\n\t./my_cook\n", 1);
	my_putstr_fd("\nHOW TO PLAY:\n\tLook at the \"How to play menu\"\n", 1);
	my_putstr_fd("\tMove the mouse on the main menu to see some easter", 1);
	my_putstr_fd(" eggs.\n\nINTERACTION:\n\tCLICK\tSelect a button.\n", 1);
	my_putstr_fd("\tESCAPE\tPause the game or go on the last menu.\n\t", 1);
	my_putstr_fd("OTHER KEY\tCompose the recipe for the game.\n", 1);
}

int main(int ac, char **av)
{
	int error = 0;

	if (ac == 1)
		my_cook(&error);
	else if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		usage();
	else {
		my_putstr_fd("Invalid argument.\n", 2);
		return (EXIT_ERROR);
	}
	if (error != 0)
		my_putstr_fd("\nAn error occured during the execution.\n\n", 2);
	return ((error == 0) ? (EXIT_SUCCESS) : (EXIT_ERROR));
}
