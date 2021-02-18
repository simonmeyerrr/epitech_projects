/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** utils_move_player.c
*/

#include "all.h"

static int search_pos_map(game_t *game, char c, int *pos, int i)
{
	for (int j = 0 ; game->map[i][j] != '\0' ; j++) {
		if (game->map[i][j] == c && (i != game->pos[1] ||
		j != game->pos[0])) {
			return (j);
		}
	}
	return (-1);
}

void check_position(game_t *game, char **map)
{
	char c = map[game->pos[1]][game->pos[0]];
	int pos[2] = {-1, -1};

	if (c < 'a' || c > 'z')
		return;
	for (int i = 0 ; i < 120 ; i++) {
		pos[0] = search_pos_map(game, c, pos, i);
		if (pos[0] != -1) {
			pos[1] = i;
			break;
		}
	}
	game->pos[0] = pos[0];
	game->pos[1] = pos[1];
	game->pos[1] += (game->dir == DIR_DOWN) ? (1) : (0);
	game->pos[1] -= (game->dir == DIR_UP) ? (1) : (0);
	game->pos[0] -= (game->dir == DIR_LEFT) ? (1) : (0);
	game->pos[0] += (game->dir == DIR_RIGHT) ? (1) : (0);
}
