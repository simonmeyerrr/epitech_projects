/*
** EPITECH PROJECT, 2017
** head
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct list_file
{
	char *name;

	struct list_file *next;
	struct list_file *prev;
} list_file_t;

typedef enum
{
	NAME_QUIET,
	NAME_NORMAL,
	NAME_VERBOSE
} option_name_t;

typedef enum
{
	SIZE_LINE,
	SIZE_BYTES,
} option_size_t;

typedef struct argument
{
	option_name_t option_name;
	option_size_t option_size;
	int option_size_int;

	list_file_t *first_file;
	list_file_t *last_file;
	int nb_file;

	int error;
} argument_t;

#endif	/* STRUCT_H_ */
