/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** free_game.c
*/

#include "all.h"

void free_fight(game_t *game)
{
	if (!game->fight)
		return;
	my_free(game->fight->string);
	free_part(game->fight->part);
	free(game->fight);
	game->fight = NULL;
}

void free_text(game_t *game)
{
	if (!game->text)
		return;
	my_free_tab(game->text->text);
	free(game->text);
	game->text = NULL;
}

static void delete_last_env(game_t *game)
{
	env_t *tmp = game->last_env;

	if (tmp->prev) {
		game->last_env = tmp->prev;
		game->last_env->next = NULL;
		my_free(tmp->pos);
		my_free(tmp);
	} else {
		my_free(tmp->pos);
		my_free(tmp);
		game->first_env = NULL;
		game->first_env = NULL;
	}
}

static void delete_last_inv(game_t *game)
{
	inventory_t *tmp = game->last_inv;

	if (tmp->prev) {
		game->last_inv = tmp->prev;
		game->last_inv->next = NULL;
		my_free(tmp);
	} else {
		my_free(tmp);
		game->first_inv = NULL;
		game->first_inv = NULL;
	}
}

void free_game(global_t *global)
{
	if (!global || !global->game)
		return;
	if (global->net)
		update_user(global);
	my_free_tab(global->game->map);
	free_fight(global->game);
	free_text(global->game);
	while (global->game->first_env)
		delete_last_env(global->game);
	while (global->game->first_inv)
		delete_last_inv(global->game);
	free_snow(global->game->snow);
	my_free(global->game);
	global->game = NULL;
}
