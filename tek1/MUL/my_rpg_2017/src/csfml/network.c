/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** network.c
*/

#include "all.h"

char *create_body(my_var_t *var)
{
	char *tab[13] = {"login", var->con_field[CON_USERNAME], "passwd",
	var->con_field[CON_PASSWORD1], "pos", "107:111", "inventory", "",
	"prog", "0", "stats", "50:5:5", NULL};
	char *body = json_creator(tab);

	return (body);
}

int are_logs_ok(char const *body)
{
	char **parsed_body = json_parser((char*)body);

	if (parsed_body && parsed_body[0] && parsed_body[1] &&
	my_strcmp(parsed_body[1], "KO") == 0) {
		my_free_tab(parsed_body);
		return (1);
	}
	if (parsed_body && parsed_body[0] && parsed_body[1] &&
	my_strcmp(parsed_body[1], "OK") == 0) {
		my_free_tab(parsed_body);
		return (0);
	}
	my_free_tab(parsed_body);
	return (2);
}

sfHttpRequest *create_request(int method, char *uri, char *body)
{
	sfHttpRequest *req = sfHttpRequest_create();
	sfHttpMethod met[4] = {sfHttpGet, sfHttpPost, sfHttpPut, sfHttpDelete};

	if (!req)
		return (NULL);
	if (method < 0 || method > 3)
		return (NULL);
	sfHttpRequest_setMethod(req, met[method]);
	sfHttpRequest_setField(req, "Content-Type", "application/json");
	if (uri)
		sfHttpRequest_setUri(req, uri);
	if (body)
		sfHttpRequest_setBody(req, body);
	return (req);
}

void send_http_request(global_t *global, int method, char *uri, char *body)
{
	if (global->net) {
		global->net->req = create_request(method, uri, body);
		if (global->net->req)
			global->net->rep = sfHttp_sendRequest(global->net->http,
			global->net->req, global->net->time);
	}
}
