/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** init_csfml.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>
#include <stdlib.h>

static sfRenderWindow *create_window(void)
{
	sfVideoMode mode = {1600, 900, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, "Hangman",
	sfClose | sfResize, NULL);

	if (!win)
		return (NULL);
	sfRenderWindow_setMouseCursorVisible(win, sfTrue);
	return (win);
}

csfml_t *init_csfml(void)
{
	csfml_t *csfml = malloc(sizeof(csfml_t));
	sfVector2f vec = {50, 600};

	if (!csfml)
		return (NULL);
	csfml->win = create_window();
	csfml->clock = sfClock_create();
	csfml->font = sfFont_createFromFile("asset/manga.ttf");
	csfml->text = sfText_create();
	if (!csfml->win || !csfml->clock || !csfml->font || !csfml->text)
		return (NULL);
	sfText_setFont(csfml->text, csfml->font);
	sfText_setColor(csfml->text, sfBlack);
	sfText_setCharacterSize(csfml->text, 200);
	sfText_setPosition(csfml->text, vec);
	return (csfml);
}
