/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** display_curse_maze.c
*/

#include "../include/all.h"

static void display_possibility(maze_t *maze, int *tab)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	if (tab[0] == 0)
		printw("\n");
	else
		printw(" /\\\n");
	if (tab[3] == 0)
		printw("   ");
	else
		printw("<  ");
	if (tab[1] == 0)
		printw("\n");
	else
		printw(">\n");
	if (tab[2] == 1)
		printw(" \\/");
}

void display_curse_maze(maze_t *maze, int *tab)
{
	usleep(100000);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	clear();
	for (int i = 0 ; i < maze->height ; i++) {
		for (int j = 0 ; j < maze->width ; j++) {
			attron(COLOR_PAIR(4));
			(maze->map[i][j] == 'X') ? attron(COLOR_PAIR(2)) : (0);
			(i == maze->pos_i && j == maze->pos_j) ?
			attron(COLOR_PAIR(3)) : (0);
			printw("  ");
		}
		printw("\n");
	}
	display_possibility(maze, tab);
	refresh();
}
