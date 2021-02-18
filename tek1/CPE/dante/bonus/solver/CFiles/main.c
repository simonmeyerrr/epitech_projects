/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** main.c
*/

#include <string.h>
#include "../include/all.h"

void display_curse(maze_t *maze)
{
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	clear();
	for (int i = 0 ; i < maze->height ; i++) {
		for (int j = 0 ; j < maze->width ; j++) {
			attron(COLOR_PAIR(1));
			(maze->map[i][j] == 'X') ? attron(COLOR_PAIR(2)) : (0);
			(maze->map[i][j] == '*') ? attron(COLOR_PAIR(4)) : (0);
			(maze->map[i][j] == 'p') ? attron(COLOR_PAIR(3)) : (0);
			(i == maze->pos_i && j == maze->pos_j) ?
			(attron(COLOR_PAIR(5))) : (0);
			printw("  ");
		}
		printw("\n");
	}
	refresh();
	usleep(50000);
}

int main(int ac, char **av)
{
	create_maze(av[1]);
	return (MY_SUCCESS);
}
