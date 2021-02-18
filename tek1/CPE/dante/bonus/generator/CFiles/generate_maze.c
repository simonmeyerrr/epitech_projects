/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** generate_maze.c
*/

#include "../include/all.h"

static void move_in_maze(maze_t *maze, int *tab)
{
	int choice = rand() % 4;

	while (tab[choice] == 0)
		choice = rand() % 4;
	if (choice == 0)
		maze->pos_i -= 1;
	if (choice == 1)
		maze->pos_j += 1;
	if (choice == 2)
		maze->pos_i += 1;
	if (choice == 3)
		maze->pos_j -= 1;
	maze->map[maze->pos_i][maze->pos_j] = '*';
}

static void add_way(maze_t *maze)
{
	way_t *way = malloc(sizeof(*way));

	verif_malloc(way);
	way->pos_i = maze->pos_i;
	way->pos_j = maze->pos_j;
	way->next = NULL;
	way->prev = maze->way_last;
	if (maze->way_last)
		maze->way_last->next = way;
	if (!maze->way_first)
		maze->way_first = way;
	maze->way_last = way;
}

static void go_to_last_way(maze_t *maze)
{
	maze->pos_i = maze->way_last->pos_i;
	maze->pos_j = maze->way_last->pos_j;
	if (maze->way_last->prev) {
		maze->way_last = maze->way_last->prev;
		my_free(maze->way_last->next);
		maze->way_last->next = NULL;
	} else {
		my_free(maze->way_last);
		maze->way_last = NULL;
		maze->way_first = NULL;
	}
}

void generate_maze(maze_t *maze)
{
	int *tab = malloc(sizeof(int) * 5);
	int end = 0;

	while (end == 0) {
		get_possibility(maze, tab);
		display_curse_maze(maze, tab);
		if (tab[4] == 0 && !maze->way_first)
			end = 1;
		if (tab[4] == 0 && maze->way_first)
			go_to_last_way(maze);
		if (tab[4] == 1)
			move_in_maze(maze, tab);
		if (tab[4] > 1) {
			add_way(maze);
			move_in_maze(maze, tab);
		}
	}
	my_free(tab);
}
