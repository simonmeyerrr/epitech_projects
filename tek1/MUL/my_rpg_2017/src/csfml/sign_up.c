/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** sign_up.c
*/

#include "all.h"

static int is_acc_existing(global_t *global)
{
	char *uri = my_append("/accounts/",
	global->var->con_field[CON_USERNAME], 0);
	char **tab = NULL;

	global->net->req = create_request(0, uri, NULL);
	global->net->rep = sfHttp_sendRequest(global->net->http,
	global->net->req, global->net->time);
	tab = json_parser((char*)sfHttpResponse_getBody(global->net->rep));
	my_free(uri);
	if (tab && tab[0] && !tab[1]) {
		free_req_rep(global->net);
		my_free_tab(tab);
		return (0);
	} else {
		my_free_tab(tab);
		free_req_rep(global->net);
		return (1);
	}
}

static void create_user(global_t *global, int *error, my_var_t *var)
{
	char *body = create_body(var);

	global->net->req = create_request(1 , "/accounts/", body);
	global->net->rep = sfHttp_sendRequest(global->net->http,
	global->net->req, global->net->time);
	if (sfHttpResponse_getStatus(global->net->rep) == 200) {
		var->con_var[CON_ERROR] = 2;
		var->con_var[CON_ERROR_STAT] = 1;
	}
	my_free(body);
	free_req_rep(global->net);
}

void user_creation(global_t *global, int *error, my_var_t *var)
{
	if (!global->net) {
		var->con_var[CON_ERROR] = 2;
		var->con_var[CON_ERROR_STAT] = 1;
		return;
	}
	if (my_strlen(var->con_field[CON_PASSWORD1]) == 0 ||
	my_strcmp(var->con_field[CON_PASSWORD1], var->con_field[CON_PASSWORD2])
	!= 0) {
		var->con_var[CON_ERROR] = 0;
		var->con_var[CON_ERROR_STAT] = 1;
		return;
	} else if (my_strlen(global->var->con_field[CON_USERNAME]) == 0 ||
	is_acc_existing(global) == 1) {
		var->con_var[CON_ERROR] = 1;
		var->con_var[CON_ERROR_STAT] = 1;
		return;
	}
	create_user(global, error, var);
}
