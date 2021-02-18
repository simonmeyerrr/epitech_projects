/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** main.c
*/

#include "all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

int main(int ac, char **av)
{
	int ret;

	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		write(1, USAGE1, USAGE1_LEN);
		write(1, USAGE2, USAGE2_LEN);
		write(1, USAGE3, USAGE3_LEN);
		write(1, USAGE4, USAGE4_LEN);
		return (0);
	}
	initscr();
	curs_set(0);
	ret = sokoban(av[1]);
	endwin();
	if (ret == 0)
		write(1, "You win!\n", 9);
	else
		write(1, "Game over, try again\n", 21);
	return (ret);
}
