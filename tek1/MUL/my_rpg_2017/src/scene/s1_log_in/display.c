/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_log_in3(my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win, global_t *global)
{
	sfVector2f pos = get_mouse_pos(global);

	my_draw_text(win, TEXT(VEC(435, 730), 35, sfBlack, font->font2),
	"Se connecter", 0);
	my_draw_text(win, TEXT(VEC(950, 725), 40, sfBlack, font->font2),
	"Retour", 0);
	my_draw_text(win, TEXT(VEC(530, 230), 50, sfBlack, font->font2),
	"Nom d'utilisateur:", 0);
	my_draw_text(win, TEXT(VEC(590, 430), 50, sfBlack, font->font2),
	"Mot de passe:", 0);
	for (int i = 0 ; i < 2 ; i++)
		if ((mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(i * 450 + 400, 700, 350, 100))) ||
		(mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(400, i * 200 + 300, 800, 100)))) {
			my_draw_mouse(global, 1);
			return;
		}
	my_draw_mouse(global, 0);
}

static void display_log_in2(my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win, global_t *global)
{
	my_draw_sprite(win, sprite->button[BT_INPUT_FIELD], VEC(400, 300));
	my_draw_sprite(win, sprite->button[BT_INPUT_FIELD], VEC(400, 500));
	my_draw_sprite(win, sprite->button[BT_INPUT_SEL],
	VEC(400, global->var->con_var[CON_FIELD] * 200 + 300));
	my_draw_text(win, TEXT(VEC(415, 320), 50, sfWhite, font->font2),
	global->var->con_field[CON_USERNAME], 0);
	my_draw_text(win, TEXT(VEC(430, 530), 75, sfWhite, font->font2),
	hiden_pass(global->var->con_field[CON_PASSWORD1]), 1);
	if (global->var->con_var[CON_ERROR_STAT] > 5)
		my_draw_text(win, TEXT(VEC(410, 630), 30, sfRed, font->font2),
		"Mauvais nom d'utilisateur ou mot de passe.", 0);
}

void display_log_in(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_MAIN_MENU], VEC(0, 0));
	for (int i = 0 ; i < 2 ; i++) {
		if (global->var->button[BUT_PRESSED] == i &&
		global->var->button[BUT_STATUS] > 0)
			my_draw_sprite(win, sprite->button[BT_LITTLE_ON],
			VEC(i * 450 + 400, 700));
		else
			my_draw_sprite(win, sprite->button[BT_LITTLE_OFF],
			VEC(i * 450 + 400, 700));
	}
	display_log_in2(sprite, font, win, global);
	display_log_in3(sprite, font, win, global);
}
