/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct tetrimino
{
	char *name;

	int error;
} tetrimino_t;

typedef struct my_options
{
	/* options */
 	char help;
	char debug;
	char hide;

	/* settings */
	int level;
	int map_col;
	int map_row;

	/* key */
	char left;
	char right;
	char turn;
	char drop;
	char quit;
	char pause;

} my_options_t;

typedef struct my_game
{
	my_options_t *option;

	int nbr_piece;
	tetrimino_t **tab;

	char exit;
} my_game_t;

#endif	/* STRUCT_H_ */
