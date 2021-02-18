/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

void display_help(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_HELP], VEC(0, 0));
	my_draw_mouse(global, 0);
}
