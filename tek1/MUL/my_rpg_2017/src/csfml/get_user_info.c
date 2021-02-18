/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** get_user_info.c
*/

#include "all.h"

static void put_user_info(game_t *game, char **tab)
{
	char **inv = my_str_to_wordtab(tab[10], ':');
	char **stat = my_str_to_wordtab(tab[14], ':');

	game->progression = my_get_nbr(tab[12]);
	game->pos[0] = my_get_nbr(tab[8]);
	game->pos[1] = my_get_second_number(tab[8]);
	for (int i = 0 ; i < my_tab_len(inv) ; i += 2)
		add_new_item(game, my_get_nbr(inv[i]), my_get_nbr(inv[i + 1]));
	game->stat_player[STAT_PV] = my_get_nbr(stat[0]);
	game->stat_player[STAT_ATTACK] = my_get_nbr(stat[1]);
	game->stat_player[STAT_DEF] = my_get_nbr(stat[2]);
	my_free_tab(inv);
	my_free_tab(stat);
}

int get_user_info(global_t *global, game_t *game)
{
	char *uri = my_append("/accounts/",
	global->var->con_field[CON_USERNAME], 0);
	char **tab = NULL;

	if (!global->net)
		return (0);
	global->net->req = create_request(0, uri, NULL);
	global->net->rep = sfHttp_sendRequest(global->net->http,
	global->net->req, global->net->time);
	my_free(uri);
	if (sfHttpResponse_getStatus(global->net->rep) != 200)
		return (1);
	tab = json_parser((char *)sfHttpResponse_getBody(global->net->rep));
	if (my_tab_len(tab) == 16)
		put_user_info(game, tab);
	my_free_tab(tab);
	free_req_rep(global->net);
	return (0);
}
