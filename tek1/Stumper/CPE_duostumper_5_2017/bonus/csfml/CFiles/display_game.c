/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** display_game.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>

static void put_letter(hangman_t *hangman, char ret, int selec)
{
	int valid = 0 ;

	for (int i = 0 ; hangman->tab_words[selec][i] != '\0' ; i++) {
		if (hangman->tab_words[selec][i] == ret) {
			hangman->hidden_word[i] = hangman->tab_words[selec][i];
			valid = 1;
		}
	}
	if (valid == 0)
		hangman->tries--;
}

static void manage_event(hangman_t *hangman, csfml_t *csfml, sfEvent event)
{
	sfKeyCode tab[26] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
	sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO,
	sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX,
	sfKeyY, sfKeyZ};

	if (event.type == sfEvtClosed ||
	(event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
		sfRenderWindow_close(csfml->win);
	for (int i = 0 ; hangman->tries > 0 &&
	event.type == sfEvtKeyPressed && i < 26 ; i++) {
		if (event.key.code == tab[i]) {
			put_letter(hangman, i + 'a', hangman->word_selected);
			return;
		}
	}
}

static void display_window(hangman_t *hangman, csfml_t *csfml)
{
	sfText_setString(csfml->text, hangman->hidden_word);
	sfRenderWindow_drawText(csfml->win, csfml->text, NULL);
	display_hangman(hangman->tries, csfml->win);
}

static int check_word(hangman_t *hangman)
{
	for (int i = 0 ; hangman->hidden_word[i] != '\0' ; i++) {
		if (hangman->hidden_word[i] == '_') {
			return (0);
		}
	}
	return (1);
}

void display_game(hangman_t *hangman, csfml_t *csfml)
{
	int end = 0;

	while (hangman->error == 0 && end == 0 &&
	sfRenderWindow_isOpen(csfml->win)) {
		while (sfRenderWindow_pollEvent(csfml->win, &(csfml->event)))
			manage_event(hangman, csfml, csfml->event);
		end = check_word(hangman);
		if (sfClock_getElapsedTime(csfml->clock).microseconds /
		1000000.0 > 1.0 / 30.0) {
			sfClock_restart(csfml->clock);
			sfRenderWindow_clear(csfml->win, sfWhite);
			display_window(hangman, csfml);
			sfRenderWindow_display(csfml->win);
		}
	}
	if (hangman->error == 0 && end == 1)
		write(1, "Congratulations!\n", 17);
	else if (hangman->error == 0)
		write(1, "You lost!\n", 10);
}
