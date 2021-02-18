/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

void update_connected(global_t *global, int *error)
{
	global->game = init_game(global, error);
	sfMusic_stop(global->music->music[MUSIC_THEME]);
	if (*error != 0 || !global->game)
		return;
	sfSprite_setScale(global->sprite->world[WD_MAP], VEC(2, 2));
	if (global->game->progression == 0) {
		global->scene = SCENE_ANIMATION;
		sfMusic_play(global->music->music[MUSIC_ANIMATION]);
	} else {
		sfMusic_play(global->music->music[MUSIC_FLAMINGO]);
		global->scene = SCENE_GAME;
	}
}
