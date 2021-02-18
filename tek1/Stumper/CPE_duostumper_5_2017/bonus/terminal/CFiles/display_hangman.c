/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** main.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <unistd.h>

static void change_map(hangman_t *hangman, int dif)
{
	char *str = "|_/|O|\\//\\";

	for (int j = 0 ; hangman->disp[j] != '\0' ; j++) {
		if ((dif == 10 && hangman->disp[j] == 'A') ||
		hangman->disp[j] == dif + 48)
			hangman->disp[j] = str[dif - 1];
	}
	for (int i = 0 ; hangman->disp[i] != '\0' ; i++) {
		if (hangman->disp[i] == '1' || hangman->disp[i] == '2' ||
		hangman->disp[i] == '3' || hangman->disp[i] == '4' ||
		hangman->disp[i] == '5' || hangman->disp[i] == '6' ||
		hangman->disp[i] == '7' || hangman->disp[i] == '8' ||
		hangman->disp[i] == '9' || hangman->disp[i] == 'A')
			write(1, " ", 1);
		else
			write(1, &hangman->disp[i], 1);
	}
}
void display_hangman(hangman_t *hangman)
{
	int dif = 10 - hangman->tries;

	change_map(hangman, dif);
}
