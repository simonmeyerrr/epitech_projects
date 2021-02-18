/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** global_draw.c
*/

#include "all.h"

void my_draw_sprite(sfRenderWindow *win, sfSprite *sprite, sfVector2f pos)
{
	if (!win || !sprite)
		return;
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(win, sprite, NULL);
}

sfText *create_text(sfVector2f pos, int size, sfColor color, sfFont *font)
{
	sfText *text = sfText_create();

	if (!text)
		return (NULL);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setColor(text, color);
	sfText_setFont(text, font);
	return (text);
}

void my_draw_text(sfRenderWindow *win, sfText *text, char *str, int free_str)
{
	if (!win || !text)
		return;
	sfText_setString(text, str);
	sfRenderWindow_drawText(win, text, NULL);
	sfText_destroy(text);
	if (free_str == 1)
		my_free(str);
}

void my_draw_mouse(global_t *global, int on)
{
	sfVector2f pos = get_mouse_pos(global);

	if (on)
		my_draw_sprite(global->win,
		global->sprite->button[BT_MOUSE_ON], pos);
	else
		my_draw_sprite(global->win,
		global->sprite->button[BT_MOUSE_OFF], pos);
}
