/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>

typedef struct hangman
{
	int tries;
	int nb_words;
	char **tab_words;
	int word_selected;
	char *hidden_word;
	char error;
} hangman_t;

typedef struct csfml
{
	sfRenderWindow *win;
	sfEvent event;

	sfFont *font;
	sfText *text;

	sfClock *clock;
} csfml_t;

#endif	/* STRUCT_H_ */
