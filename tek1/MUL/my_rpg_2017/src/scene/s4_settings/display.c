/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_text_settings2(my_sprite_t *sprite, my_font_t *font,
global_t *global, sfRenderWindow *win)
{
	my_draw_text(win, TEXT(VEC(100, 430), 50, sfBlack,
	font->font2), "Synchro vert.", 0);
	my_draw_text(win, TEXT(VEC(600, 430), 50, sfBlack,
	font->font2), "Des.          Act.", 0);
	my_draw_text(win, TEXT(VEC(100, 530), 50, sfBlack,
	font->font2), "FPS limit", 0);
	my_draw_text(win, TEXT(VEC(600, 530), 50, sfBlack,
	font->font2), " 30            60", 0);
}

static void display_text_settings(my_sprite_t *sprite, my_font_t *font,
global_t *global, sfRenderWindow *win)
{
	my_draw_text(win, TEXT(VEC(445, 730), 35, sfBlack,
	font->font2), "Reinitialiser", 0);
	my_draw_text(win, TEXT(VEC(950, 725), 40, sfBlack,
	font->font2), "Retour", 0);
	my_draw_text(win, TEXT(VEC(100, 130), 50, sfBlack,
	font->font2), "Volume General", 0);
	my_draw_text(win, TEXT(VEC(600, 130), 50, sfBlack,
	font->font2), int_to_str(global->var->setting[SET_VOL_GENERAL]), 1);
	my_draw_text(win, TEXT(VEC(100, 230), 50, sfBlack,
	font->font2), "Volume Musique", 0);
	my_draw_text(win, TEXT(VEC(600, 230), 50, sfBlack,
	font->font2), int_to_str(global->var->setting[SET_VOL_MUSIC]), 1);
	my_draw_text(win, TEXT(VEC(100, 330), 50, sfBlack,
	font->font2), "Volume Bruits", 0);
	my_draw_text(win, TEXT(VEC(600, 330), 50, sfBlack,
	font->font2), int_to_str(global->var->setting[SET_VOL_SOUND]), 1);
	display_text_settings2(sprite, font, global, win);
}

static void display_sprite_settings(my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win, global_t *global)
{
	my_draw_sprite(win, sprite->button[BT_CURSOR_BUT], VEC(767 +
	(global->var->setting[SET_VOL_GENERAL] * 5), 115));
	my_draw_sprite(win, sprite->button[BT_CURSOR_BUT], VEC(767 +
	(global->var->setting[SET_VOL_MUSIC] * 5), 215));
	my_draw_sprite(win, sprite->button[BT_CURSOR_BUT], VEC(767 +
	(global->var->setting[SET_VOL_SOUND] * 5), 315));
	if (!global->var->setting[SET_VSYNC])
		my_draw_sprite(win, sprite->button[BT_SWITCH_L], VEC(750, 445));
	else
		my_draw_sprite(win, sprite->button[BT_SWITCH_R], VEC(803, 445));
	if (global->var->fps == 30.0)
		my_draw_sprite(win, sprite->button[BT_SWITCH_L], VEC(750, 545));
	else
		my_draw_sprite(win, sprite->button[BT_SWITCH_R], VEC(803, 545));
}

static int display_cursor(my_sprite_t *sprite, sfRenderWindow *win,
sfVector2f pos, sfVector2f *pos_vol)
{
	for (int i = 0 ; i < 3 ; i++)
		if (mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(pos_vol[i].x, pos_vol[i].y, 66, 68)))
			return (1);
	for (int i = 0 ; i < 2 ; i++)
		if (mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(i * 450 + 400, 700, 350, 100)))
			return (1);
	for (int i = 0 ; i < 2 ; i++)
		if (mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(750, i * 100 + 445, 133, 30)))
			return (1);
	return (0);
}

void display_settings(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(global);
	sfVector2f *pos_vol = get_vol_pos(global);

	sfRenderWindow_drawSprite(win, sprite->background[BG_SETTING], NULL);
	for (int i = 0 ; i < 2 ; i++) {
		if (global->var->button[BUT_PRESSED] == i &&
		global->var->button[BUT_STATUS] > 0)
			my_draw_sprite(win, sprite->button[BT_LITTLE_ON],
			VEC(i * 450 + 400, 700));
		else
			my_draw_sprite(win, sprite->button[BT_LITTLE_OFF],
			VEC(i * 450 + 400, 700));
	}
	display_sprite_settings(sprite, font, win, global);
	display_text_settings(sprite, font, global, win);
	if (display_cursor(sprite, win, pos, pos_vol))
		my_draw_mouse(global, 1);
	else
		my_draw_mouse(global, 0);
	my_free(pos_vol);
}
