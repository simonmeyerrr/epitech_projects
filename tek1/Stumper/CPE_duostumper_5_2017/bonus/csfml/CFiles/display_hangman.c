/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** display_hangman.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>

sfVector2f create_vector(int a, int b)
{
	sfVector2f c = {a, b};

	return (c);
}

sfVertex create_vertex(sfVector2f a , sfColor c , sfVector2f b)
{
	sfVertex ver = {a, c, b};

	return (ver);
}

void display_hangman(int tries, sfRenderWindow *win)
{
	sfVertexArray *array = sfVertexArray_create();

	sfVertexArray_setPrimitiveType(array, sfQuads);
	display_hang2(tries, array);
	display_hang6(tries, array);
	display_hang5(tries, array);
	display_hang4(tries, array);
	display_hang3(tries, array);
	sfRenderWindow_drawVertexArray(win, array, NULL);
	sfVertexArray_destroy(array);
}
