/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

static void update_anim_fight(game_t *game, my_music_t *music)
{
	update_part(game->fight->part);
	game->fight->fight_anim += 1;
	if (game->fight->fight_anim == 15) {
		game->stat_player[STAT_PV] -=
		(game->fight->fight_status) ? (game->fight->damage) : (0);
		game->fight->stat_enemy[STAT_PV] -=
		(game->fight->fight_status) ? (0) : (game->fight->damage);
		sfMusic_play(music->sound[(game->fight->damage <= 0) ?
		(SOUND_ABANON) : ((game->fight->fight_status) ?
		(SOUND_ARETE) : (SOUND_EUUUH))]);
	}
	if (game->fight->fight_anim > 60) {
		game->fight->fight_anim = 0;
		game->fight->fight_status =
		(game->fight->fight_status) ? (0) : (15);
		my_free(game->fight->string);
		game->fight->string = NULL;
		free_part(game->fight->part);
		game->fight->part = NULL;
	}
}

static void coro_is_dead(global_t *global)
{
	free_fight(global->game);
	global->game->stat_player[STAT_PV] =
	global->game->stat_player[STAT_PV_MAX];
	global->scene = SCENE_GAME;
	global->game->pos[0] = 4;
	global->game->pos[1] = 117;
	sfMusic_play(global->music->sound[SOUND_LOSE]);
	sfMusic_stop(global->music->music[MUSIC_FIGHT]);
	sfMusic_play(global->music->music[MUSIC_FLAMINGO]);
}

static void enemy_is_dead(global_t *global)
{
	global->game->fight->win(global, global->game);
	global->scene = SCENE_GAME;
	free_fight(global->game);
	sfMusic_play(global->music->sound[SOUND_VICTOIRE]);
	sfMusic_stop(global->music->music[MUSIC_FIGHT]);
	sfMusic_play(global->music->music[MUSIC_FLAMINGO]);
}

static void fight_button(global_t *global)
{
	if (update_button(global)) {
		switch (global->var->button[BUT_PRESSED]) {
		case 0:
			global->scene = SCENE_GAME_MENU;
			break;
		case 1:
			attack_coro1(global, global->game);
			break;
		case 2:
			attack_coro2(global, global->game);
			break;
		}
	}
}

void update_fight(global_t *global, int *error)
{
	if (global->game->fight->fight_anim > 0)
		update_anim_fight(global->game, global->music);
	if (global->game->stat_player[STAT_PV] <= 0 &&
	global->game->fight->fight_anim == 0) {
		coro_is_dead(global);
		return;
	} else if (global->game->fight->stat_enemy[STAT_PV] <= 0 &&
	global->game->fight->fight_anim == 0) {
		enemy_is_dead(global);
		return;
	}
	attack_enemy(global, global->game);
	fight_button(global);
}
