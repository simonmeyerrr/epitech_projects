/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct my_flag
{
	char *long_flag;
	char short_flag;
	char arg;
} my_flag_t;

typedef struct my_getopt_arg
{
	my_flag_t *flags;
	char **str;
	int ac;
	char **av;
	int *error;
	int *i;
	int *j;
} my_getopt_t;

typedef struct my_word
{
	char *word;

	struct my_word *next;
	struct my_word *prev;
} my_word_t;

typedef struct my_mixword
{
	char **result;
	int size;

	int used_word;
	int total_word;

	my_word_t *first_word;
	my_word_t *last_word;
} my_mixword_t;

#endif	/* STRUCT_H_ */
