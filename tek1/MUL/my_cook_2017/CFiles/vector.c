/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** vector.c
*/

#include "all.h"

sfVector2f create_vector(float x, float y)
{
	sfVector2f vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

sfVector2f get_mouse_pos(sfRenderWindow *win)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(win);
	sfVector2f pos2 = {pos.x, pos.y};

	return (pos2);
}

void set_pos_draw(sfSprite *sprite, sfRenderWindow *win, sfVector2f pos)
{
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(win, sprite, NULL);
}

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

int verif_malloc(void *ptr, int *error)
{
	if (!ptr)
		*error = 1;
	return (*error);
}
