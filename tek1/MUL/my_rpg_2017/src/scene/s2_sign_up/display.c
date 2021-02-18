/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_sign_up4(my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win, global_t *global)
{
	sfVector2f pos = get_mouse_pos(global);

	my_draw_text(win, TEXT(VEC(435, 780), 35, sfBlack, font->font2),
	"S'enregistrer", 0);
	my_draw_text(win, TEXT(VEC(950, 775), 40, sfBlack, font->font2),
	"Retour", 0);
	my_draw_text(win, TEXT(VEC(550, 200), 40, sfBlack, font->font2),
	"Nom d'utilisateur:", 0);
	my_draw_text(win, TEXT(VEC(620, 350), 40, sfBlack, font->font2),
	"Mot de passe:", 0);
	for (int i = 0 ; i < 3 ; i++)
		if ((i != 2 && mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(i * 450 + 400, 750, 350, 100))) ||
		(mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(400, i * 150 + 250, 800, 100)))) {
			my_draw_mouse(global, 1);
			return;
		}
	my_draw_mouse(global, 0);
}

static void display_sign_up3(my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win, global_t *global)
{
	my_draw_text(win, TEXT(VEC(620, 500), 40, sfBlack, font->font2),
	"Mot de passe:", 0);
	for (int i = 0 ; i < 3 ; i++)
		my_draw_sprite(win, sprite->button[BT_INPUT_FIELD],
		VEC(400, i * 150 + 250));
	my_draw_sprite(win, sprite->button[BT_INPUT_SEL],
	VEC(400, global->var->con_var[CON_FIELD] * 150 + 250));
	my_draw_text(win, TEXT(VEC(415, 270), 50, sfWhite, font->font2),
	global->var->con_field[CON_USERNAME], 0);
	my_draw_text(win, TEXT(VEC(430, 430), 75, sfWhite, font->font2),
	hiden_pass(global->var->con_field[CON_PASSWORD1]), 1);
	my_draw_text(win, TEXT(VEC(430, 580), 75, sfWhite, font->font2),
	hiden_pass(global->var->con_field[CON_PASSWORD2]), 1);
}

static void display_sign_up2(global_t *global, my_font_t *font,
sfRenderWindow *win)
{
	switch (global->var->con_var[CON_ERROR]) {
		case 0:
			my_draw_text(win, TEXT(VEC(500, 670), 40, sfRed,
			font->font2), "Mots de passe incorects", 0);
			break;
		case 1:
			my_draw_text(win, TEXT(VEC(450, 670), 40, sfRed,
			font->font2), "Nom d'utilisateur deja pris", 0);
			break;
		case 2:
			my_draw_text(win, TEXT(VEC(600, 660), 50,
			sfGreen, font->font2), "Compte cree", 0);
			break;
	}
}

void display_sign_up(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_MAIN_MENU], VEC(0, 0));
	for (int i = 0 ; i < 2 ; i++) {
		if (global->var->button[BUT_PRESSED] == i &&
		global->var->button[BUT_STATUS] > 0)
			my_draw_sprite(win, sprite->button[BT_LITTLE_ON],
			VEC(i * 450 + 400, 750));
		else
			my_draw_sprite(win, sprite->button[BT_LITTLE_OFF],
			VEC(i * 450 + 400, 750));
	}
	if (global->var->con_var[CON_ERROR_STAT] > 0)
		display_sign_up2(global, global->font, global->win);
	display_sign_up3(sprite, font, win, global);
	display_sign_up4(sprite, font, win, global);
}
