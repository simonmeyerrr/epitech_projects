/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** main.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static void free_last_word(my_mixword_t *mixword)
{
	if (mixword->last_word == mixword->first_word) {
		my_free(mixword->last_word->word);
		my_free(mixword->last_word);
		mixword->last_word = NULL;
		mixword->first_word = NULL;
	} else {
		mixword->last_word = mixword->last_word->prev;
		my_free(mixword->last_word->next->word);
		my_free(mixword->last_word->next);
		mixword->last_word->next = NULL;
	}
}

static void free_mixword(my_mixword_t *mixword)
{
	while (mixword->first_word)
		free_last_word(mixword);
	my_free_tab(mixword->result);
	my_free(mixword);
}

int main(int ac, char **av)
{
	my_mixword_t *mixword = init_mixword(ac, av);

	algo_to_mixword(mixword);
	display_mixword(mixword);
	free_mixword(mixword);
	return (MY_SUCCESS);
}
