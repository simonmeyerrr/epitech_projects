/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** init_tunnel.c
*/

#include "../include/all.h"

static int verif_tunnel(char *str, global_t *global)
{
	for (int i = 0 ; i < global->nb_room && global->room[i] ; i++) {
		if (my_strcmp(str, global->room[i]->name) == 0) {
			global->room[i]->nb_next = global->room[i]->nb_next + 1;
			return (0);
		}
	}
	return (1);
}

static void put_word(char *s1, char *s2, char *str)
{
	int i = 0;
	int ret = 0;

	for (i ; str && str[i] && str[i] != '-' ; i++)
		s1[i] = str[i];
	s1[i] = '\0';
	i++;
	ret = i;
	for (i = 0 ; str && str[i + ret] ; i++)
		s2[i] = str[i + ret];
	s2[i] = '\0';
}

static char **get_tunnel_tab(global_t *global, char *str, int *error)
{
	char **tab = malloc(sizeof(char*) * 3);
	int len1 = 0;
	int len2 = 0;

	if (!tab)
		return (NULL);
	tab[2] = NULL;
	for (len1 = 0 ; str && str[len1] && str[len1] != '-' ; len1++);
	for (len2 = 0; str && str[len2 + len1] ; len2++);
	tab[0] = malloc(sizeof(char) * (len1 + 1));
	tab[1] = malloc(sizeof(char) * (len2 + 1));
	if (!tab[0] || !tab[1] || len1 < 1 || len2 < 2) {
		*error = 1;
		return (NULL);
	}
	put_word(tab[0], tab[1], str);
	*error = verif_tunnel(tab[0], global);
	if (error == 0)
		*error = verif_tunnel(tab[0], global);
	return (tab);
}

void init_tunnel(global_t *global)
{
	input_t *tmp = global->input_first;
	int error = 0;
	char **tab = NULL;

	for (int i = 0 ; i < global->nb_tunnel && global->room[i] && error == 0
	; i++) {
		while (tmp && tmp->info != INFO_TUNNEL)
			tmp = tmp->next;
		tab = get_tunnel_tab(global, tmp->tab[0], &error);
		my_free_tab(tmp->tab);
		if (error == 0)
			tmp->tab = tab;
		tmp = tmp->next;
	}
}
