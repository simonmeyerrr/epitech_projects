/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** generate_maze.c
*/

#include "../include/all.h"

static void move2(maze_t *maze, int a)
{
	if (a == 0)
		maze->pos_i--;
	if (a == 1)
		maze->pos_j++;
	if (a == 2)
		maze->pos_i++;
	if (a == 3)
		maze->pos_j--;
}

static void add_last_way(maze_t *maze)
{
	way_t *new = malloc(sizeof(way_t));

	new->pos_i = maze->pos_i;
	new->pos_j = maze->pos_j;
	new->next = maze->last_pos;
	maze->last_pos = new;
}

static void move_in_maze(maze_t *maze, int *tab)
{
	int a;

	add_last_way(maze);
	if (tab[0] == 1)
		a = 0;
	if (tab[3] == 1)
		a = 3;
	if (tab[2] == 1)
		a = 2;
	if (tab[1] == 1)
		a = 1;
	move2(maze, a);
	maze->map[maze->pos_i][maze->pos_j] = 'o';
}
static void go_to_last_way(maze_t *maze, int *tab)
{
	way_t *tmp = maze->last_pos->next;

	maze->map[maze->pos_i][maze->pos_j] = 'p';
	maze->pos_i = maze->last_pos->pos_i;
	maze->pos_j = maze->last_pos->pos_j;
	my_free(maze->last_pos);
	maze->last_pos = tmp;
}

void solve_maze(maze_t *maze)
{
	int *tab = malloc(sizeof(int) * 5);
	int end = 0;

	maze->map[0][0] = 'o';
	while (end == 0) {
		get_possibility(maze, tab);
		display_curse(maze);
		if (tab[4] == 0 && !maze->last_pos)
			end = 1;
		else if (tab[4] == 0)
			go_to_last_way(maze, tab);
		else
			move_in_maze(maze, tab);
		if (maze->pos_i == maze->height - 1 &&
		maze->pos_j == maze->width - 1) {
			end = 1;
			maze->end_found = 1;
		}
	}
	my_free(tab);
}
