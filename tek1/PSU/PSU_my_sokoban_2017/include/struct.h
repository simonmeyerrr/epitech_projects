/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** struct.h
*/

typedef struct storage
{
	int x;
	int y;
	struct storage* next;
} storage_t;

typedef struct my_var
{
	int height;
	int max_width;

	int player_x;
	int player_y;

	storage_t* storage;
	int box;

	int status;

	char next1;
	char next2;
} var_t;
