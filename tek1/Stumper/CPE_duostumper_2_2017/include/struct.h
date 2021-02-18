/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef enum
{
	TOKEN,
	FOOD,
} type_t;

typedef struct position
{
	type_t type;
	int pos[2];

	struct position *next;
	struct position *prev;
} position_t;

typedef struct ginger
{
	char **map;
	int width;
	int height;

	position_t *list_token;
	position_t *list_food;

	int pos[2];

	int total_token;
	int eaten_token;

	int move_points;
	int move_init;

	int end;
} ginger_t;

#endif	/* STRUCT_H_ */
