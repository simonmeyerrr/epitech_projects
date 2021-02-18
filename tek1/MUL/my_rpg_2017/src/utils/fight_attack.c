/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** fight_attack.c
*/

#include "all.h"

struct enemy_info ene_tab[4] = {
	{IM_LOGAN_FIGHT, "Logan paul attaque vlog de merde"},
	{IM_KNUCKLE_FIGHT, "Le roi knuckle attaque knock knock"},
	{IM_LAMA_FIGHT, "Le lamasticot utilise coup de tete"},
	{IM_JAHAR_FIGHT, "Jahar attaque puissance divine"}
};

void attack_coro1(global_t *global, game_t *game)
{
	game->fight->damage = game->stat_player[STAT_ATTACK] /
	(game->fight->stat_enemy[STAT_DEF] / 5);
	game->fight->fight_anim = 1;
	game->fight->string = my_strcat(global->var->con_field[CON_USERNAME],
	" utilise Lasagnakadrabogne");
	sfMusic_play(global->music->sound[SOUND_ATTACK1]);
	free_part(game->fight->part);
	game->fight->part = new_part_buffer(50, 1);
	set_part(game->fight->part, VEC(1300, 300));
}

void attack_coro2(global_t *global, game_t *game)
{
	game->fight->damage = game->stat_player[STAT_ATTACK];
	if (rand() % 4 < 3)
		game->fight->damage = 0;
	game->fight->fight_anim = 1;
	game->fight->string = my_strcat(global->var->con_field[CON_USERNAME],
	" envoie son yeeeeeeeeeee");
	sfMusic_play(global->music->sound[SOUND_ATTACK2]);
	game->fight->part = new_part_buffer(50, 1);
	set_part(game->fight->part, VEC(1300, 300));
}

void attack_enemy(global_t *global, game_t *game)
{
	if (game->fight->fight_status > 1 && game->fight->fight_anim == 0)
		game->fight->fight_status -= 1;
	if (game->fight->fight_status == 1 && game->fight->fight_anim == 0) {
		game->fight->damage = game->fight->stat_enemy[STAT_ATTACK] /
		(game->stat_player[STAT_DEF] / 5);
		game->fight->fight_anim = 1;
		game->fight->string =
		my_strdup(ene_tab[game->fight->enemy].attack);
		game->fight->part = new_part_buffer(50, 2);
		set_part(game->fight->part, VEC(200, 300));
	}
}
