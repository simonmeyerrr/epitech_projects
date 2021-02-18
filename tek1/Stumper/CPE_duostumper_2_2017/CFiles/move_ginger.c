/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** move_ginger.c
*/

#include "../include/all.h"

static void remove_pos_list(ginger_t *ginger, position_t *pos)
{
	if (!pos)
		return;
	if (pos->next)
		pos->next->prev = pos->prev;
	if (pos->prev)
		pos->prev->next = pos->next;

	if (!pos->prev && pos->type == TOKEN)
		ginger->list_token = pos->next;
	else if (!pos->prev && pos->type == FOOD)
		ginger->list_food = pos->next;
	free(pos);
}

static position_t *get_nearest_token(ginger_t *ginger)
{
	position_t *best = ginger->list_token;

	if (!best)
		return (NULL);
	for (position_t *tmp = ginger->list_token->next ; tmp ;
	tmp = tmp->next) {
		if (get_total_distance(ginger, tmp) <
		get_total_distance(ginger, best))
			best = tmp;
	}
	return (best);
}

static position_t *get_nearest_food(ginger_t *ginger)
{
	position_t *best = ginger->list_food;

	if (!best)
		return (NULL);
	for (position_t *tmp = ginger->list_food->next ; tmp ;
	tmp = tmp->next) {
		if (get_total_distance(ginger, tmp) <
		get_total_distance(ginger, best))
			best = tmp;
	}
	return (best);
}

static position_t *get_the_best_choice(ginger_t *ginger)
{
	position_t *token = get_nearest_token(ginger);
	position_t *food = get_nearest_food(ginger);

	if (ginger->eaten_token == ginger->total_token - 1 &&
	get_total_distance(ginger, token) <= ginger->move_points)
		return (token);
	if (food &&
	get_total_distance(ginger, token) >= get_total_distance(ginger, food))
		return (food);
	return (token);
}

void move_ginger(ginger_t *ginger)
{
	position_t *pos = get_the_best_choice(ginger);

	move_on_map(ginger, pos->pos[0], pos->pos[1]);
	if (pos->pos[0] == ginger->pos[0] && pos->pos[1] == ginger->pos[1]) {
		if (pos->type == FOOD)
			ginger->move_points += ginger->move_init;
		if (pos->type == TOKEN)
			ginger->eaten_token += 1;
		remove_pos_list(ginger, pos);
	}
	ginger->move_points -= 1;
	if (ginger->total_token == ginger->eaten_token ||
	ginger->move_points <= 0)
		ginger->end = 1;
}
