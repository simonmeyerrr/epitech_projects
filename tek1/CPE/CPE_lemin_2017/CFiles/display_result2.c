/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** display_result2.c
*/

#include "../include/all.h"

int check_end(int length, int *tab_ants)
{
	for (int i = 0 ; i < length ; i++) {
		if (tab_ants[i] != -1)
			return (1);
	}
	return (0);
}

void display_ants(int length, int *tab, room_t **room)
{
	for (int i = 0 ; i < length ; i++) {
		if (tab[i] != -1) {
			my_putstr_fd("P", 1);
			my_put_nbr(i + 1);
			my_putstr_fd("-", 1);
			my_putstr_fd(room[tab[i]]->name, 1);
			my_putstr_fd(" ", 1);
		}
	}
	my_putstr_fd("\n", 1);
}

void loop_display(int *tab_length, int *tab_ants, int *tab_way, room_t **room)
{
	int way = 2;

	while (check_end(tab_length[0], tab_ants)) {
		display_ants(tab_length[0], tab_ants, room);
		for (int i = tab_length[0] - 1 ; i > 0 ; i--)
			tab_ants[i] = tab_ants[i - 1];
		if (way < tab_length[1]) {
			tab_ants[0] = tab_way[way];
			way++;
		} else
			tab_ants[0] = -1;
	}
}
