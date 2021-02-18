/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

struct item_info item_tab[7] =
{
	{"Baton magique", IM_BATON, 15, 15, 3},
	{"Courone de knuckle", IM_COURNNE, 10, 10, 1},
	{"Sac de Logan Paul", IM_SACADO, 5, 5, 2},
	{"Crocs", IM_CROCS, 0, 5, 4},
	{"Tongue", IM_TONGUE, 5, 0, 4},
	{"Biere\nPV + 10", IM_BIERE, 0, 0, 5},
	{"Dildo", IM_DILDO, 20, 0, 3}
};

void update_inventory(global_t *global, int *error)
{
	global->game->stat_player[STAT_ATTACK] = 5;
	global->game->stat_player[STAT_DEF] = 5;
	for (inventory_t *inv = global->game->first_inv ; inv ; inv = inv->next)
		if (inv->status != SI_IN_INV) {
			global->game->stat_player[STAT_ATTACK] +=
			item_tab[inv->item].attack;
			global->game->stat_player[STAT_DEF] +=
			item_tab[inv->item].defense;
		}
}
