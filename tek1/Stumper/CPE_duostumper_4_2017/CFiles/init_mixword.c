/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** init_mixword.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static void init_tab_result(my_mixword_t *mixword)
{
	if (mixword->total_word <= 0)
		my_exit("A file with words is expected.\n");
	mixword->result = malloc(sizeof(char*) * (mixword->size + 1));
	verif_malloc(mixword->result);
	for (int i = 0 ; i < mixword->size ; i++) {
		mixword->result[i] = malloc(sizeof(char) * (mixword->size + 1));
		verif_malloc(mixword->result[i]);
		memset(mixword->result[i], ' ', mixword->size);
		mixword->result[i][mixword->size] = '\0';
	}
	mixword->result[mixword->size] = NULL;
}

static void are_char_valid(char *str)
{
	for (int i = 0 ; str && str[i] ; i++)
		if (str[i] < 'a' || str[i] > 'z')
			my_exit("Invalid char in a word.\n");
	if (my_strlen(str) <= 0)
		my_exit("Invalid word.\n");
}

static void are_words_valid(my_mixword_t *mixword)
{
	for (my_word_t *tmp = mixword->first_word ; tmp ; tmp = tmp->next) {
		if (tmp->word[my_strlen(tmp->word) - 1] == '\n')
			tmp->word[my_strlen(tmp->word) - 1] = '\0';
		are_char_valid(tmp->word);
	}
}

my_mixword_t *init_mixword(int ac, char **av)
{
	my_mixword_t *mixword = malloc(sizeof(my_mixword_t));

	verif_malloc(mixword);
	mixword->result = NULL;
	mixword->size = 8;
	mixword->used_word = 0;
	mixword->total_word = 0;
	mixword->first_word = NULL;
	mixword->last_word = NULL;
	parse_argument(mixword, ac, av);
	are_words_valid(mixword);
	init_tab_result(mixword);
	return (mixword);
}
