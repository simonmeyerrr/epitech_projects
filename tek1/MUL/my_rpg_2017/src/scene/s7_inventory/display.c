/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_items(my_sprite_t *sprite, sfRenderWindow *win,
inventory_t *first_inv)
{
	int x = 0;
	int y = 0;

	for (inventory_t *inv = first_inv ; inv ; inv = inv->next) {
		if (inv->status == SI_IN_INV) {
			my_draw_sprite(win,
			sprite->image[item_tab[inv->item].image],
			VEC(x * 170 + 925, y * 150 + 25));
			x++;
		} else
			my_draw_sprite(win,
			sprite->image[item_tab[inv->item].image],
			VEC(440, inv->status * 125 - 95));
		if (x == 4) {
			x = 0;
			y++;
		}
	}
}

static int display_cursor(my_sprite_t *sprite, sfRenderWindow *win,
global_t *global, inventory_t *first_inv)
{
	sfVector2f pos = get_mouse_pos(global);
	inventory_t *inv = first_inv;
	int x = 0;
	int y = 0;

	for (; inv ; inv = inv->next) {
		if (inv->status && mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(440, inv->status * 125 - 95, 100, 100)))
			return (1);
		if (!inv->status && mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(x * 170 + 925, y * 150 + 25, 100, 100)))
			return (1);
		if (!inv->status)
			x++;
		if (x == 4) {
			x = 0;
			y++;
		}
	}
	return (0);
}

static void draw_stats_item(sfRenderWindow *win, inventory_t *inv,
my_font_t *font)
{
	my_draw_text(win, TEXT(VEC(880, 550), 40, sfBlack,
	font->font2), item_tab[inv->item].name, 0);
	my_draw_text(win, TEXT(VEC(880, 700), 40, sfBlack,
	font->font2), "ATK = ", 0);
	my_draw_text(win, TEXT(VEC(1050, 700), 40, sfBlack,
	font->font2), int_to_str(item_tab[inv->item].attack), 1);
	my_draw_text(win, TEXT(VEC(880, 800), 40, sfBlack,
	font->font2), "DEF = ", 0);
	my_draw_text(win, TEXT(VEC(1050, 800), 40, sfBlack,
	font->font2), int_to_str(item_tab[inv->item].defense), 1);
}

static void display_item_stats(my_sprite_t *sprite, sfRenderWindow *win,
global_t *global, inventory_t *first_inv)
{
	sfVector2f pos = get_mouse_pos(global);
	int x = 0;
	int y = 0;

	for (inventory_t *inv = first_inv ; inv ; inv = inv->next) {
		if (inv->status && mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(440, inv->status * 125 - 95, 100, 100)))
			draw_stats_item(win, inv, global->font);
		if (!inv->status && mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(x * 170 + 925, y * 150 + 25, 100, 100)))
			draw_stats_item(win, inv, global->font);
		if (!inv->status)
			x++;
		if (x == 4) {
			x = 0;
			y++;
		}
	}
}

void display_inventory(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	my_draw_sprite(win, sprite->background[BG_INVENTORY], VEC(0, 0));
	display_items(sprite, win, global->game->first_inv);
	display_item_stats(sprite, win, global, global->game->first_inv);
	my_draw_text(win, TEXT(VEC(50, 750), 50, sfWhite,
	font->font2), int_to_str(global->game->stat_player[STAT_PV]), 1);
	my_draw_text(win, TEXT(VEC(110, 750), 50, sfWhite,
	font->font2), "/ 50", 0);
	my_draw_text(win, TEXT(VEC(330, 750), 50, sfWhite,
	font->font2), int_to_str(global->game->stat_player[STAT_ATTACK]), 1);
	my_draw_text(win, TEXT(VEC(610, 750), 50, sfWhite,
	font->font2), int_to_str(global->game->stat_player[STAT_DEF]), 1);
	if (display_cursor(sprite, win, global, global->game->first_inv))
		my_draw_mouse(global, 1);
	else
		my_draw_mouse(global, 0);
}
