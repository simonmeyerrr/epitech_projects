/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct my_path
{
	char *path;

	struct my_path *next;
	struct my_path *prev;
} my_path_t;

typedef enum
{
	TYPE_UNDEFINED,
	TYPE_CHAR,
	TYPE_FIELD,
} my_type_t;

typedef struct minicut
{
	my_type_t type;
	char delimiter;

	int *nb_tab;
	int tab_length;

	my_path_t *first_path;
	my_path_t *last_path;

	char error;
} minicut_t;

#endif	/* STRUCT_H_ */
