/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

void display_connected(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_MAIN_MENU], VEC(0, 0));
	my_draw_text(win, TEXT(VEC(500, 400), 100, sfBlack, font->font2),
	"Connected", 0);
}
