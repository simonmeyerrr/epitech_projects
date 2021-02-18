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
	way->next = maze->way;
	maze->way = way;
}

static void go_to_last_way(maze_t *maze)
{
	way_t *tmp = maze->way;

	maze->pos_i = maze->way->pos_i;
	maze->pos_j = maze->way->pos_j;
	maze->way = maze->way->next;
	my_free(tmp);
}

void generate_maze(maze_t *maze)
{
	int *tab = malloc(sizeof(int) * 5);
	int end = 0;

	while (end == 0) {
		get_possibility(maze, tab);
		if (tab[4] == 0 && !maze->way)
			end = 1;
		if (tab[4] == 0 && maze->way)
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
