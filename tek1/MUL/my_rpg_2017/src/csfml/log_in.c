/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** log_in.c
*/

#include "all.h"

static void connection_user(global_t *global, int *error, my_var_t *var)
{
	char *uri = my_append("/connection/", var->con_field[CON_USERNAME], 0);
	char *body = create_body(var);

	global->net->req = create_request(2, uri, body);
	global->net->rep = sfHttp_sendRequest(global->net->http,
	global->net->req, global->net->time);
	my_free(body);
	if (are_logs_ok(sfHttpResponse_getBody(global->net->rep)) != 0) {
		global->var->con_var[CON_ERROR_STAT] = 1;
		free_req_rep(global->net);
		my_free(uri);
		return;
	}
	my_free(uri);
	free_req_rep(global->net);
	global->scene = SCENE_CONNECTED;
}

void user_connection(global_t *global, int *error, my_var_t *var)
{
	if (!global->net) {
		global->scene = SCENE_CONNECTED;
		return;
	}
	if (my_strlen(var->con_field[CON_USERNAME]) == 0 ||
	my_strlen(var->con_field[CON_PASSWORD1]) == 0) {
		var->con_var[CON_ERROR_STAT] = 1;
		return;
	}
	connection_user(global, error, var);
}
