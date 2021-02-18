/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** main.c
*/

#include "../include/all.h"

static void verif_key(my_options_t *option)
{
	char *tab[] = TAB3;
	int i = 0;
	int j = i + 1;
	char c = *tab[i];

	while (i < 5) {
		if (*tab[j] == c) {
			my_putstr_fd("A key is used for multiple command.\n",
			2);
			exit(EXIT_ERROR);
		}
		if (j >= 5) {
			i++;
			j = i + 1;
			c = *tab[i];
		} else
			j++;
	}
}

void write_usage(char *exec)
{
	my_putstr_fd(USAGE1, 1);
	my_putstr_fd(exec, 1);
	my_putstr_fd(USAGE2, 1);
}

int main(int ac, char **av)
{
	my_game_t *game = malloc(sizeof(*game));
	char c;

	verif_malloc(game);
	parse_argument(ac, av, game);
	verif_key(game->option);
	get_tetrimino(game);
	if (game->option->help == 1) {
		write_usage(av[0]);
	} else {
		if (game->option->debug == 1) {
			disp_debug(game);
			read(0, &c, 1);
		}
		play_game(game);
	}
	free_game(game);
	return (EXIT_SUCCESS);
}
