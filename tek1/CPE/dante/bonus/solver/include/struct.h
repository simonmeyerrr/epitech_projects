/*
** EPITECH PROJECT, 2017
** dante_solver
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct way
{
	int pos_i;
	int pos_j;

	struct way *next;
} way_t;

typedef struct maze
{
	char **map;
	int width;
	int height;

	int pos_i;
	int pos_j;
	way_t *last_pos;

	int end_found;
} maze_t;

#endif	/* STRUCT_H_ */
