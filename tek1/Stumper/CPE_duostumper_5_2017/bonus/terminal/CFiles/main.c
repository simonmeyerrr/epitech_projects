/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** main.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <stdlib.h>

static int free_hangman(hangman_t *hangman)
{
	int ret = MY_SUCCESS;

	if (!hangman || hangman->error != 0)
		ret = MY_ERROR;
	if (!hangman)
		return (ret);
	my_free_tab(hangman->tab_words);
	my_free(hangman->hidden_word);
	free(hangman);
	return (ret);
}

int main(int ac, char **av)
{
	hangman_t *hangman = init_hangman(ac, av);

	if (!hangman)
		return (MY_ERROR);
	if (hangman->error != 0)
		return (free_hangman(hangman));
	display_game(hangman);
	return (free_hangman(hangman));
}
