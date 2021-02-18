/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** memory.c
*/

#include "all.h"

void free_req_rep(my_network_t *net)
{
	if (net->rep)
		sfHttpResponse_destroy(net->rep);
	if (net->req)
		sfHttpRequest_destroy(net->req);
	net->rep = NULL;
	net->req = NULL;
}

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

int my_tab_len(char **tab)
{
	int len = 0;

	while (tab && tab[len])
		len++;
	return (len);
}

void my_free_tab(char **tab)
{
	for (int i = 0 ; tab && tab[i] ; i++)
		free(tab[i]);
	my_free(tab);
	tab = NULL;
}

int verif_malloc(void *ptr, int *error)
{
	if (!ptr) {
		*error = 1;
		my_putstr_fd("Error while using malloc.\n", 2);
		return (1);
	}
	return (0);
}
