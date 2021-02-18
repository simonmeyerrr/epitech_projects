/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

static int can_move(game_t *game, int *pos, int a, int b)
{
	char c = game->map[pos[1] + a][pos[0] + b];

	for (env_t *tmp = game->first_env ; tmp ; tmp = tmp->next) {
		if (game->progression <= tmp->prog_max && tmp->pos[0] ==
		pos[0] + b && tmp->pos[1] == pos[1] + a)
			return (0);
	}
	if (c == ' ')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static void move_player(game_t *game, direction_t dir)
{
	int a = (dir == DIR_UP) ? (-1) : (0);
	int b = (dir == DIR_LEFT) ? (-1) : (0);

	a = (dir == DIR_DOWN) ? (1) : (a);
	b = (dir == DIR_RIGHT) ? (1) : (b);
	if (can_move(game, game->pos, a, b) == 1)
		game->move_status = 1;
}

static void move_player_on_map(global_t *global)
{
	global->game->move_status = 0;
	if (global->game->dir == DIR_UP)
		global->game->pos[1]--;
	if (global->game->dir == DIR_DOWN)
		global->game->pos[1]++;
	if (global->game->dir == DIR_RIGHT)
		global->game->pos[0]++;
	if (global->game->dir == DIR_LEFT)
		global->game->pos[0]--;
	check_position(global->game, global->game->map);
}

void update_game(global_t *global, int *error)
{
	if (global->game->pos[0] < 30 && global->game->pos[1] < 82 &&
	global->game->pos[1] > 65)
		update_snow(global->game->snow);
	if (update_button(global))
		global->scene = SCENE_GAME_MENU;
	if (global->game->text && global->game->text->chars <
	my_strlen(global->game->text->text[global->game->text->elem]))
		global->game->text->chars += 1;
	if (global->game->move_status == 0 && global->game->move_on == 1)
		move_player(global->game, global->game->dir);
	if (global->game->move_status == 1)
		sfMusic_play(global->music->sound[SOUND_STEPS]);
	if (global->game->move_status > 0)
		global->game->move_status++;
	if (global->game->move_status >= 4 * 3)
		move_player_on_map(global);
}
