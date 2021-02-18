/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_main_menu2(global_t *global, my_sprite_t *sprite,
my_font_t *font, sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(global);

	my_draw_text(win, TEXT(VEC(600, 270), 50, sfBlack, font->font2),
	"Se connecter", 0);
	my_draw_text(win, TEXT(VEC(660, 420), 50, sfBlack, font->font2),
	"S\'inscrire", 0);
	my_draw_text(win, TEXT(VEC(670, 570), 50, sfBlack, font->font2),
	"Reglages", 0);
	my_draw_text(win, TEXT(VEC(680, 720), 50, sfBlack, font->font2),
	"Quitter", 0);
	for (int i = 0 ; i < 4 ; i++) {
		if (mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(550, i * 150 + 250, 500, 100))) {
			my_draw_mouse(global, 1);
			return;
		}
	}
	my_draw_mouse(global, 0);
}

void display_main_menu(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_MAIN_MENU], VEC(0, 0));
	for (int i = 0 ; i < 4 ; i++) {
		if (global->var->button[BUT_PRESSED] == i &&
		global->var->button[BUT_STATUS] > 0)
			my_draw_sprite(win, sprite->button[BT_BIG_ON],
			VEC(550, i * 150 + 250));
		else
			my_draw_sprite(win, sprite->button[BT_BIG_OFF],
			VEC(550, i * 150 + 250));
	}
	display_main_menu2(global, sprite, font, win);
}
