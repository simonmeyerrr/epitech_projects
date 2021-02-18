/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** parse_argument.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static void manage_size(my_mixword_t *mixword, char *str)
{
	if (is_nb_valid(str) != 1)
		my_exit("Invalid number for the size.\n");
	if (my_get_nbr(str) <= 0)
		my_exit("Positive number expected.\n");
	mixword->size = my_get_nbr(str);
}

static void add_new_word(my_mixword_t *mixword, char *str)
{
	my_word_t *new = malloc(sizeof(my_word_t));

	verif_malloc(new);
	new->word = my_strdup(str);
	new->next = NULL;
	new->prev = mixword->last_word;
	if (mixword->last_word)
		mixword->last_word->next = new;
	else
		mixword->first_word = new;
	mixword->last_word = new;
	mixword->total_word += 1;
}

static void manage_file(my_mixword_t *mixword, char *str)
{
	static int already = 0;
	int fd;
	char *buffer;

	if (already >= 1)
		my_exit("Only one file expected.\n");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		my_exit("can\'t open the file.\n");
	while ((buffer = get_next_line(fd))) {
		add_new_word(mixword, buffer);
		my_free(buffer);
	}
	already++;
	close(fd);
}

static void manage_flag(my_mixword_t *mixword, char c, char *str)
{
	switch (c) {
	case '!':
		exit(MY_ERROR);
	case ':':
		my_put_err("No simple argument expected.\n");
		exit(MY_ERROR);
	case 'h':
		display_help();
		break;
	case 'f':
		manage_file(mixword, str);
		break;
	case 's':
		manage_size(mixword, str);
		break;
	}
}

void parse_argument(my_mixword_t *mixword, int ac, char **av)
{
	char *str = NULL;
	my_flag_t flags[3] = {{"--help", 'h', 0}, {"--file", 'f', 1},
	{"--size", 's', 1}};
	char c = my_getopt(flags, &str, ac, av);

	while (c != '.') {
		manage_flag(mixword, c, str);
		c = my_getopt(flags, &str, ac, av);
	}
	my_free(str);
}
