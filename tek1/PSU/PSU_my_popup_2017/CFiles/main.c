/*
** EPITECH PROJECT, 2017
** ah
** File description:
** main.c
*/

#include "all.h"

int main(int ac, char **av)
{
	int len;

	if (ac != 2)
		return (84);
	len = strlen(av[1]);
	initscr();
	while(1) {
		clear();
		mvprintw(LINES/2, (COLS / 2) - (len / 2), av[1]);
		refresh();
		if(getch() != 410)
			break;
	}
	endwin();
	return (0);
}
