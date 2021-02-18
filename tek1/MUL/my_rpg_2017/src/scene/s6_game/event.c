/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

static void search_env(global_t *global, game_t *game)
{
	int a = (game->dir == DIR_UP) ? (-1) : (0);
	int b = (game->dir == DIR_LEFT) ? (-1) : (0);

	a = (game->dir == DIR_DOWN) ? (1) : (a);
	b = (game->dir == DIR_RIGHT) ? (1) : (b);
	for (env_t *tmp = game->first_env ; tmp ; tmp = tmp->next)
		if (game->progression <= tmp->prog_max && tmp->pos[0] ==
		game->pos[0] + b && tmp->pos[1] == game->pos[1] + a) {
			tmp->fonc(global, game);
			return;
		}
}

static void manage_return(global_t *global, sfEvent event, game_t *game)
{
	if (!game->text) {
		search_env(global, game);
		return;
	}
	if (game->text) {
		game->text->chars = 0;
		game->text->elem += 1;
	}
	if (game->text && game->text->elem ==
	my_tab_len(game->text->text)) {
		game->text->fonc(global, game);
		free_text(game);
	}
}

static void event_move(game_t *game, sfKeyCode key, sfEvent event)
{
	if (game->move_status == 0 && event.type == sfEvtKeyPressed) {
		game->dir = (key == sfKeyUp) ? (DIR_UP) : (game->dir);
		game->dir = (key == sfKeyDown) ? (DIR_DOWN) : (game->dir);
		game->dir = (key == sfKeyRight) ? (DIR_RIGHT) : (game->dir);
		game->dir = (key == sfKeyLeft) ? (DIR_LEFT) : (game->dir);
		game->move_on = ((key == sfKeyUp) || (key == sfKeyDown) ||
		(key == sfKeyLeft) || (key == sfKeyRight)) ? (1) : (0);
	}
	if (event.type == sfEvtKeyReleased) {
		if (key == sfKeyUp && game->dir == DIR_UP)
			game->move_on = 0;
		if (key == sfKeyDown && game->dir == DIR_DOWN)
			game->move_on = 0;
		if (key == sfKeyLeft && game->dir == DIR_LEFT)
			game->move_on = 0;
		if (key == sfKeyRight && game->dir == DIR_RIGHT)
			game->move_on = 0;
	}
}

void event_game(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeySpace)) {
		global->scene = SCENE_INVENTORY;
		return;
	}
	if (!global->game->text)
		event_move(global->game, event.key.code, event);
	if (event.type != sfEvtKeyPressed)
		return;
	if (event.key.code == sfKeyReturn)
		manage_return(global, event, global->game);
	if (global->game->text && event.key.code == sfKeyEscape) {
		global->game->text->fonc(global, global->game);
		free_text(global->game);
	} else if (event.key.code == sfKeyEscape)
		global->scene = SCENE_GAME_MENU;
}
