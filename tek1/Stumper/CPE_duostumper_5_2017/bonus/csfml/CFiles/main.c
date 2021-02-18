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
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>

static int free_hangman_csfml(hangman_t *hangman, csfml_t *csfml)
{
	int ret = MY_SUCCESS;

	if (!csfml || hangman->error != 0)
		ret = MY_ERROR;
	my_free_tab(hangman->tab_words);
	my_free(hangman->hidden_word);
	free(hangman);
	if (csfml) {
		sfRenderWindow_destroy(csfml->win);
		sfClock_destroy(csfml->clock);
		sfFont_destroy(csfml->font);
		sfText_destroy(csfml->text);
	}
	my_free(csfml);
	return (ret);
}

int main(int ac, char **av)
{
	hangman_t *hangman = init_hangman(ac, av);
	csfml_t *csfml = init_csfml();

	if (!hangman || !csfml)
		return (MY_ERROR);
	if (hangman->error != 0)
		return (free_hangman_csfml(hangman, csfml));
	display_game(hangman, csfml);
	return (free_hangman_csfml(hangman, csfml));
}
