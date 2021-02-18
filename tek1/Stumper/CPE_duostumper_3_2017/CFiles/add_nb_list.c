/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** add_nb_list.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

static void add_nb_to_list(char *nb, minicut_t *minicut, int higher)
{
	if (nb[0] == '-') {
		for (int i = my_get_second_nbr(nb) - 1 ; i >= 0 ; i--)
			minicut->nb_tab[i] = 1;
		return;
	}
	if (nb[my_strlen(nb) - 1] == '-') {
		for (int i = my_get_nbr(nb) - 1 ; i < higher ; i++)
			minicut->nb_tab[i] = 1;
		minicut->nb_tab[higher] = -1;
	} else if (my_get_second_nbr(nb) <= 0) {
		minicut->nb_tab[my_get_nbr(nb) - 1] = 1;
	} else {
		for (int i = (my_get_nbr(nb) - 1 >= 0) ? (my_get_nbr(nb) - 1) :
		(0) ; i < my_get_second_nbr(nb) ; i++)
			minicut->nb_tab[i] = 1;
	}
}

static int manage_tab_list(minicut_t *minicut, char **tab)
{
	int higher = 0;

	for (int i = 0 ; tab[i] ; i++) {
		if (my_get_nbr(tab[i]) > higher)
			higher = my_get_nbr(tab[i]);
		if (my_get_second_nbr(tab[i]) > higher)
			higher = my_get_second_nbr(tab[i]);
	}
	if (higher == 0)
		return (0);
	minicut->tab_length = higher + 1;
	minicut->nb_tab = malloc(sizeof(int) * (higher + 2));
	for (int i = 0 ; i < higher + 1 ; i++)
		minicut->nb_tab[i] = 0;
	for (int i = 0 ; tab[i] ; i++)
		add_nb_to_list(tab[i], minicut, higher);
	my_free_tab(tab);
	return (1);
}

int manage_numbers_list(minicut_t *minicut, char *arg)
{
	char **tab = str_to_tab(arg, ",");

	for (int i = 0 ; tab && tab[i] ; i++) {
		if (is_duo_nb_valid(tab[i]) == 0)
			return (0);
	}
	if (my_tab_len(tab) < 1)
		return (0);
	return (manage_tab_list(minicut, tab));
}
