/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** utils_inter.c
*/

#include "all.h"

void nothing(global_t *global, game_t *game)
{
	return;
}

void add_new_item(game_t *game, item_t item, status_item_t status)
{
	inventory_t *new = malloc(sizeof(inventory_t));

	if (!new)
		return;
	new->status = status;
	new->item = item;
	new->next = NULL;
	new->prev = game->last_inv;
	if (game->last_inv)
		game->last_inv->next = new;
	else
		game->first_inv = new;
	game->last_inv = new;
}

my_text_t *create_text_box(char **tab, void (*fonc)(global_t *, game_t *))
{
	my_text_t *text = malloc(sizeof(*text));

	if (!text)
		return (NULL);
	text->chars = 0;
	text->elem = 0;
	text->text = tab;
	text->fonc = fonc;
	return (text);
}

my_fight_t *create_fight(global_t *global, enemy_t enemy, int *tab,
void (*win)(global_t *, game_t *))
{
	global->game->fight = malloc(sizeof(my_fight_t));
	if (!global->game->fight || !tab)
		return (NULL);
	global->scene = SCENE_FIGHT;
	global->game->fight->enemy = enemy;
	global->game->fight->stat_enemy[STAT_PV] = tab[0];
	global->game->fight->stat_enemy[STAT_PV_MAX] = tab[1];
	global->game->fight->stat_enemy[STAT_ATTACK] = tab[2];
	global->game->fight->stat_enemy[STAT_DEF] = tab[3];
	global->game->fight->fight_status = 0;
	global->game->fight->fight_anim = 0;
	global->game->fight->win = win;
	global->game->fight->part = NULL;
	global->game->fight->string = NULL;
	sfMusic_stop(global->music->music[MUSIC_FLAMINGO]);
	sfMusic_play(global->music->music[MUSIC_FIGHT]);
	my_free(tab);
}
