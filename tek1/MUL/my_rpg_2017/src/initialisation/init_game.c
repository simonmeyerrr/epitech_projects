/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** init_game.c
*/

#include "all.h"

static char **get_map(void)
{
	char **map = malloc(sizeof(char*) * (121));
	int fd = open("asset/.map", O_RDONLY);

	if (fd < 0 || !map)
		return (NULL);
	for (int i = 0 ; i < 120 ; i++)
		map[i] = get_next_line(fd);
	map[120] = NULL;
	close(fd);
	return (map);
}

static void init_value_game(game_t *game)
{
	game->pos[0] = 107;
	game->pos[1] = 111;
	game->dir = DIR_LEFT;
	game->move_on = 0;
	game->move_status = 0;
	game->map = get_map();
	game->stat_player[STAT_PV] = 50;
	game->stat_player[STAT_PV_MAX] = 50;
	game->stat_player[STAT_ATTACK] = 5;
	game->stat_player[STAT_DEF] = 5;
	game->progression = 0;
	game->first_env = NULL;
	game->last_env = NULL;
	game->first_inv = NULL;
	game->last_inv = NULL;
	game->text = NULL;
	game->fight = NULL;
	game->snow = new_snow_buffer(10000, 1600, 900);
	set_snow(game->snow);
}

static void add_env(game_t *game, int *tab, void (*fonc)(global_t *, game_t *))
{
	env_t *env = malloc(sizeof(*env));

	if (!env || !tab)
		return;
	env->prog_max = tab[0];
	env->image = tab[1];
	env->pos = TAB2(tab[2], tab[3]);
	env->fonc = fonc;
	env->next = NULL;
	env->prev = game->last_env;
	if (game->last_env)
		game->last_env->next = env;
	else
		game->first_env = env;
	game->last_env = env;
	my_free(tab);
}

static void init_env(game_t *game)
{
	add_env(game, TAB4(20, WD_PANNEAU, 79, 109), inter_panneau);
	add_env(game, TAB4(20, WD_PANNEAU, 65, 86), inter_panneau);
	add_env(game, TAB4(20, WD_NURSE, 4, 115), inter_nurse);
	add_env(game, TAB4(20, WD_PNJ1, 91, 110), inter_npc1);
	add_env(game, TAB4(20, WD_PNJ2, 19, 116), inter_npc2);
	add_env(game, TAB4(20, WD_PNJ3, 36, 117), inter_npc3);
	add_env(game, TAB4(1, WD_STICK, 99, 111), inter_stick);
	add_env(game, TAB4(2, WD_COFFRE, 89, 97), inter_coffre1);
	add_env(game, TAB4(3, WD_LOGAN, 66, 104), inter_logan);
	add_env(game, TAB4(4, WD_COFFRE, 97, 4), inter_coffre2);
	add_env(game, TAB4(5, WD_KNUCKLES, 58, 85), inter_knuckle_block);
	add_env(game, TAB4(5, WD_KNUCKLES, 59, 85), inter_knuckle_block);
	add_env(game, TAB4(5, WD_ROI_KNUCKLE, 18, 3), inter_king_knuckle);
	add_env(game, TAB4(6, WD_COFFRE, 21, 103), inter_coffre3);
	add_env(game, TAB4(7, WD_LAMA, 20, 70), inter_lama);
	add_env(game, TAB4(8, WD_JAHAR, 22, 67), inter_jahar);
	add_env(game, TAB4(8, WD_LORION, 18, 67), inter_jahar);
}

game_t *init_game(global_t *global, int *error)
{
	game_t *game = malloc(sizeof(*game));

	if (verif_malloc(game, error))
		return (NULL);
	init_value_game(game);
	if (!game->map) {
		*error = 1;
		return (game);
	}
	init_env(game);
	if (get_user_info(global, game)) {
		*error = 1;
		return (NULL);
	}
	return (game);
}
