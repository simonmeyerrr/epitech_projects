/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** main.c
*/

#include "../include/all.h"

static void display_end(ginger_t *ginger)
{
	if (ginger->eaten_token == ginger->total_token)
		write(1, "Ginger never loses!\n", 20);
	else
		write(1, "Ginger is too old for that!\n", 28);
}

static void free_ginger(ginger_t *ginger)
{
	for (int i = 0 ; ginger->map && ginger->map[i] ; i++)
		free(ginger->map[i]);
	free(ginger->map);
	free(ginger);
}

int main(int ac, char **av)
{
	ginger_t *ginger = init_ginger(ac, av);

	while (ginger->end == 0) {
		display_ginger(ginger);
		move_ginger(ginger);
	}
	display_ginger(ginger);
	display_end(ginger);
	free_ginger(ginger);
	return (MY_SUCCESS);
}
