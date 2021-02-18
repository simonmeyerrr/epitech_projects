/*
** EPITECH PROJECT, 2017
** dante_generator
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

	way_t *way;
} maze_t;

#endif	/* STRUCT_H_ */
