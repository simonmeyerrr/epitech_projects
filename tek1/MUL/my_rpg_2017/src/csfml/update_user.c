/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update_user.c
*/

#include "all.h"

static char *pos_to_str(int pos_x, int pos_y)
{
	int len = 3;
	int i;
	char *str;

	for (int nb = pos_x / 10 ; nb > 0 ; nb = nb / 10)
		len++;
	for (int nb = pos_y / 10 ; nb > 0 ; nb = nb / 10)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	for (i = len - 1 ; pos_y > 0 ; i--) {
		str[i] = pos_y % 10 + '0';
		pos_y = pos_y / 10;
	}
	str[i] = ':';
	for (i = i - 1 ; pos_x > 0 ; i--) {
		str[i] = pos_x % 10 + '0';
		pos_x = pos_x / 10;
	}
	str[len] = '\0';
	return (str);
}

static char *get_inventory(inventory_t *first)
{
	char *str = malloc(sizeof(char) * 1);

	str[0] = '\0';
	for (inventory_t *tmp = first ; tmp ; tmp = tmp->next) {
		str = my_append(str, int_to_str(tmp->item), 3);
		str = my_append(str, ":", 1);
		str = my_append(str, int_to_str(tmp->status), 3);
		str = my_append(str, ":", 1);
	}
	return (str);
}

static char *get_stat(game_t *game)
{
	char *str = NULL;

	str = my_append(str, int_to_str(game->stat_player[STAT_PV]), 3);
	str = my_append(str, ":", 1);
	str = my_append(str, int_to_str(game->stat_player[STAT_ATTACK]), 3);
	str = my_append(str, ":", 1);
	str = my_append(str, int_to_str(game->stat_player[STAT_DEF]), 3);
	str = my_append(str, ":", 1);
	return (str);
}

void update_user(global_t *global)
{
	char *tab[13] = {"login", global->var->con_field[CON_USERNAME],
	"passwd", global->var->con_field[CON_PASSWORD1], "pos",
	pos_to_str(global->game->pos[0], global->game->pos[1]), "inventory",
	get_inventory(global->game->first_inv), "prog",
	int_to_str(global->game->progression), "stats", get_stat(global->game),
	NULL};
	char *body = json_creator(tab);
	char *uri = my_append("/accounts/",
	global->var->con_field[CON_USERNAME], 0);

	send_http_request(global, 2, uri, body);
	my_free(body);
	my_free(uri);
	my_free(tab[5]);
	my_free(tab[7]);
	my_free(tab[9]);
	my_free(tab[11]);
	free_req_rep(global->net);
}
