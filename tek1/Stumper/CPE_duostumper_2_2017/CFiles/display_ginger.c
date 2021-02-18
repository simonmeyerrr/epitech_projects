/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** display_ginger.c
*/

#include "../include/all.h"

int my_strlen(char *str)
{
	int i = 0;

	for (; str && str[i] != '\0' ; i++);
	return (i);
}

static void print_map(ginger_t *ginger)
{
	ginger->map[ginger->pos[1]][ginger->pos[0]] = 'G';
	for (int i = 0 ; ginger->map[i] != NULL ; i++) {
		ginger->map[i][ginger->width + 1] = '\n';
		write(1, ginger->map[i], ginger->width + 2);
		ginger->map[i][ginger->width + 1] = '\0';
	}
	ginger->map[ginger->pos[1]][ginger->pos[0]] = '.';
}

static void print_tokens_and_moves(ginger_t *ginger)
{
	write(1, "Tokens: ", 8);
	printf("%d/%d\n", ginger->eaten_token, ginger->total_token);
	write(1, "Movement points: ", 17);
	printf("%d\n", ginger->move_points);
}

void display_ginger(ginger_t *ginger)
{
	print_tokens_and_moves(ginger);
	print_map(ginger);
	write(1, "\n", 1);
}
