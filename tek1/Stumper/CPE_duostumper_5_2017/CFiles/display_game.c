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

static void put_letter(hangman_t *hangman, char ret, int selec)
{
	int valid = 0 ;

	for (int i = 0 ; hangman->tab_words[selec][i] != '\0' ; i++) {
		if (hangman->tab_words[selec][i] == ret) {
			hangman->hidden_word[i] = hangman->tab_words[selec][i];
			valid = 1;
		}
	}
	if (valid == 0) {
		write(1, &ret, 1);
		write(1, ": is not in this word\n", 22);
		hangman->tries--;
	}
}

static void get_letter(hangman_t *hangman)
{
	char *ret;

	write(1, "Your letter: ", 13);
	ret = get_next_line(0);
	if (ret == NULL) {
		hangman->error = 1;
		return;
	}
	if (my_strlen(ret) != 2 || ret[0] == ' ') {
		my_put_err("Invalid input\n");
		get_letter(hangman);
	} else
		put_letter(hangman, ret[0], hangman->word_selected);
	my_free(ret);
}

static int check_word(hangman_t *hangman)
{
	for (int i = 0 ; hangman->hidden_word[i] != '\0' ; i++) {
		if (hangman->hidden_word[i] == '*') {
			return (0);
		}
	}
	return (1);
}

void display_game(hangman_t *hangman)
{
	int end = 0;

	my_putstr(hangman->hidden_word);
	write(1, "\nTries: ", 8);
	my_put_nb(hangman->tries);
	write(1, "\n\n", 2);
	while (hangman->error == 0 && end == 0 && hangman->tries > 0) {
		get_letter(hangman);
		if (hangman->error == 0) {
			my_putstr(hangman->hidden_word);
			write(1, "\nTries: ", 8);
			my_put_nb(hangman->tries);
			write(1, "\n\n", 2);
			end = check_word(hangman);
		}
	}
	if (hangman->error == 0 && end == 1)
		write(1, "Congratulations!\n", 17);
	else if (hangman->error == 0)
		write(1, "You lost!\n", 10);
}
