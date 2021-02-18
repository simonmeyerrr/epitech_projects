/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** parse_argument.c
*/

#include "../include/all.h"

static int get_int(char *str, int a)
{
	int i = 0;
	int nb = 0;

	for (i ; (str[i] < '0' || str[i] > '9') && str[i] != '\0' ; i++);
	for (i ; str[i] >= '0' && str[i] <= '9' ; i++) {
		nb = nb * 10 + str[i] - '0';
	}
	if (a == 2) {
		nb = 0;
		for (i ; (str[i] < '0' || str[i] > '9') &&
		str[i] != '\0' ; i++);
		for (i ; str[i] >= '0' && str[i] <= '9' ; i++) {
			nb = nb * 10 + str[i] - '0';
		}
	}
	return (nb);
}

static char get_key(char *str)
{
	int len = my_strlen(str);

	if (len == 1)
		return (str[0]);
	if (len == 3)
		return (str[1]);
	return (-1);
}

static void manage_arg(int optch, my_options_t *option, char *str)
{
	char *tab1[] = {"hDw", "lrtdqp"};
	char *tab2[] = {&option->help, &option->debug, &option->hide};
	char *tab3[] = TAB3;
	static int a = 0;

	if (optch == 'L')
		option->level = get_int(str, 1);
	if (optch == 'm') {
		if (a % 2 == 0)
			option->map_row = get_int(str, 1);
		else
			option->map_col = get_int(str, 1);
		a++;
	}
	for (int i = 0 ; i < 3 ; i++)
		if (optch == tab1[0][i])
			*tab2[i] = 1;
	for (int i = 0 ; i < 6 ; i++)
		if (optch == tab1[1][i])
			*tab3[i] = get_key(str);
}

static void get_argument(int ac, char **av, my_options_t *option)
{
	char optstring[] = ":L:l:r:t:d:q:p:wD";
	int optch;
	struct option longopts[18] = {{"help", 0, NULL, 'h'},
	{"level", 1, NULL, 'L'}, {"key-left", 1, NULL, 'l'},
	{"key-right", 1, NULL, 'r'}, {"key-turn", 1, NULL, 't'},
	{"key-drop", 1, NULL, 'D'}, {"key-quit", 1, NULL, 'q'},
	{"key-pause", 1, NULL, 'p'}, {"map-size", 1, NULL, 'm'},
	{"without-next", 0, NULL, 'w'}, {"debug", 0, NULL, 'D'},
	{0, 0, 0, 0 }};

	while ((optch = getopt_long(ac, av, optstring, longopts, NULL)) != -1) {
		if (optch != ':' && optch != '?')
			manage_arg(optch, option, optarg);
		else {
			my_putstr_fd("Invalid flag.\n", 2);
			exit(EXIT_ERROR);
		}
	}
}

void parse_argument(int ac, char **av, my_game_t *game)
{
	game->option = malloc(sizeof(my_options_t));
	verif_malloc(game->option);
	game->option->help = 0;
	game->option->debug = 0;
	game->option->hide = 0;
	game->option->level = 1;
	game->option->map_col = 10;
	game->option->map_row = 20;
	game->option->left = -1;
	game->option->right = -2;
	game->option->turn = -3;
	game->option->drop = -4;
	game->option->quit = 'q';
	game->option->pause = ' ';
	if (ac > 1)
		get_argument(ac, av, game->option);
}
