/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** jump.c
*/

#include "all.h"

int on_ground(my_object_t *obj, my_var_t *var)
{
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};
	int y = obj->player->pos.y;
	int x = obj->player->pos.x;
	my_block_t *tmp;

	if (y != -20 && y != 80 && y != 180 && y != 280 && y != 380 && y != 480
	&& y != 580 && y != 680 && y != 780) {
		return (0);
	}
	tmp = tab[(y + 120) / 100];
	for (int i = 0 ; i < 6 && tmp != NULL && var->cheat == 0; i++) {
		if ((tmp->type == 1 || tmp->type == 2) && ((tmp->pos.x < x + 5
		&& tmp->pos.x + 100 > x + 5) || (tmp->pos.x < x + 65 &&
		tmp->pos.x + 100 > x + 65)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int on_top(my_object_t *obj, my_var_t *var)
{
	my_block_t *tmp;
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};
	int y = obj->player->pos.y;
	int x = obj->player->pos.x;

	if (y <= -120)
		return (1);
	if (y != 100 && y != 200 && y != 300 && y != 400 && y != 500 &&
	y != 600 && y != 700 && y != 800 && y != 900 && y != 1000)
		return (0);
	tmp = tab[y / 100 - 1];
	for (int i = 0 ; i < 6 && tmp != NULL && var->cheat == 0; i++) {
		if (tmp->type == 1 && ((tmp->pos.x < x + 5
		&& tmp->pos.x + 100 > x + 5) || (tmp->pos.x < x + 65 &&
		tmp->pos.x + 100 > x + 65)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void jump_verif(game_t *game)
{
	for (int i = 0 ; i < game->var->move_vec && game->var->move_vec > 0 ;
	i++) {
		game->obj->player->pos.y += 1;
		if (on_ground(game->obj, game->var) == 1) {
			i = game->var->move_vec;
			game->var->move_vec = 0;
		}
	}
	for (int i = 0 ; i < -game->var->move_vec && game->var->move_vec < 0 ;
	i++) {
		(i != 0) ? (game->obj->player->pos.y -= 1) :(0);
		if (on_top(game->obj, game->var) == 1) {
			i = game->var->move_vec;
			game->var->move_vec = 0;
		}
	}
}

static void jump2(game_t *game)
{
	(game->var->move_vec < 0) ?
	(game->var->move_vec = game->var->move_vec / 1.8) : (0);
	(game->var->move_vec > -5 && game->var->move_vec < 0) ?
	(game->var->move_vec = 0) : (0);
	(on_ground(game->obj, game->var) == 1) ? (game->var->move_vec = 0) :
	(0);
	(game->var->move_vec == 0 && on_ground(game->obj, game->var) == 0) ?
	(game->var->move_vec = 15) :
	(game->var->move_vec = game->var->move_vec * 1.2);
}

void jump(game_t *game)
{
	if (game->var->jump == 1) {
		jump3(game, 0);
	} else if (game->var->jump == 2) {
		jump3(game, 2);
	} else
		jump2(game);
	jump_verif(game);
}
