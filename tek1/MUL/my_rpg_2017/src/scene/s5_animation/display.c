/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_animation2(int animation, my_sprite_t *sprite,
sfRenderWindow *win)
{
	int tab[16][32] = {{0, 10}, {10, 19}, {19, 29}, {29, 38}, {38, 51},
		{51, 56}, {56, 65}, {65, 73}, {73, 78}, {78, 83},
		{83, 98}, {98, 104}, {104, 118}, {118, 122},
		{122, 137}};

	for (int i = 0 ; i < NB_ANIMATION ; i++) {
		if (animation >= tab[i][0] * 30 && animation < tab[i][1] * 30) {
			my_draw_sprite(win, sprite->animation[i], VEC(0, 0));
			return;
		}
		if (i == 15)
			my_draw_sprite(win, sprite->animation[15], VEC(0, 0));
	}
}

void display_animation(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(global);

	display_animation2(global->var->animation, sprite, win);
	if (global->var->button[BUT_STATUS] > 0)
		my_draw_text(win, TEXT(VEC(1400, 800), 30, sfRed,
		font->font2), "Passer >", 0);
	else
		my_draw_text(win, TEXT(VEC(1400, 800), 30, sfWhite,
		font->font2), "Passer >", 0);
	if (pos.x >= 1400 && pos.x <= 1550 && pos.y >= 800 && pos.y <= 830)
		my_draw_sprite(win, sprite->button[BT_MOUSE_ON], pos);
	else
		my_draw_sprite(win, sprite->button[BT_MOUSE_OFF], pos);
}
