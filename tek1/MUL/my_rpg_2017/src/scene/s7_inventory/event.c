/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

static void item_selected(global_t *global, inventory_t *inv, game_t *game)
{
	if (item_tab[inv->item].equipement >= 1 &&
	item_tab[inv->item].equipement < 5) {
		for (inventory_t *tmp = game->first_inv ; tmp ;
		tmp = tmp->next)
			tmp->status = (tmp->status ==
			item_tab[inv->item].equipement) ? (0) : (tmp->status);
		inv->status = item_tab[inv->item].equipement;
	} else {
		game->stat_player[STAT_PV] += 10;
		inv->prev->next = inv->next;
		if (inv->next)
			inv->next->prev = inv->prev;
		game->last_inv = (inv->next) ? (inv->next) : (inv->prev);
		free(inv);
	}
}

static void click_on_item(global_t *global, sfEvent event, int x, int y)
{
	for (inventory_t *inv = global->game->first_inv ; inv ;
	inv = inv->next) {
		if (inv->status != SI_IN_INV &&
		mouse_on_button(VEC(event.mouseButton.x, event.mouseButton.y),
		create_tab4(440, inv->status * 125 - 95, 100, 100)))
			inv->status = SI_IN_INV;
		if (inv->status == SI_IN_INV &&
		mouse_on_button(VEC(event.mouseButton.x, event.mouseButton.y),
		create_tab4(x * 170 + 925, y * 150 + 25, 100, 100))) {
			item_selected(global, inv, global->game);
			return;
		}
		if (!inv->status)
			x++;
		if (x == 4) {
			x = 0;
			y++;
		}
	}
}

void event_inventory(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape) || event_key(global, sfKeySpace))
		global->scene = SCENE_GAME;
	if (event_click(global) != 1)
		return;
	if (!global->game->fight)
		click_on_item(global, event, 0, 0);
}
