/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** display_ginger.c
*/

#include "../include/all.h"

static int calcul_distance(int begin, int end, int limit)
{
	int x = begin;
	int i = 0;
	int j = 0;

	for (i ; x != end ; i++) {
		x++;
		if (x > limit)
			x = 0;
	}
	x = begin;
	for (j ; x != end ; j++) {
		x--;
		if (x < 0)
			x = limit;
	}
	if (i < j)
		return (i);
	else
		return (j);
}

int get_total_distance(ginger_t *ginger, position_t *pos)
{
	int dist = 0;

	dist += calcul_distance(ginger->pos[0], pos->pos[0], ginger->width);
	dist += calcul_distance(ginger->pos[1], pos->pos[1], ginger->height);
	return (dist);
}

static void in_the_map(ginger_t *ginger)
{
	if (ginger->pos[0] < 0)
		ginger->pos[0] = ginger->width;
	if (ginger->pos[0] > ginger->width)
		ginger->pos[0] = 0;
	if (ginger->pos[1] < 0)
		ginger->pos[1] = ginger->height - 1;
	if (ginger->pos[1] > ginger->height)
		ginger->pos[1] = 0;
}

void move_on_map(ginger_t *ginger, int x, int y)
{
	int x_dist = calcul_distance(ginger->pos[0], x, ginger->width);
	int y_dist = calcul_distance(ginger->pos[1], y, ginger->height);

	if (x_dist != 0) {
		if (calcul_distance(ginger->pos[0] + 1, x, ginger->width) <
		x_dist)
			ginger->pos[0] += 1;
		else
			ginger->pos[0] -= 1;
	} else if (y_dist != 0) {
		if (calcul_distance(ginger->pos[1] + 1, y, ginger->height) <
		y_dist)
			ginger->pos[1] += 1;
		else
			ginger->pos[1] -= 1;
	}
	in_the_map(ginger);
}
