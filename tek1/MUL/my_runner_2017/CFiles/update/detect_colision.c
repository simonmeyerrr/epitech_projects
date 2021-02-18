/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** detect_colision.c
*/

#include "all.h"

void jump3(game_t *game, int i)
{
	if (i == 2) {
		game->var->move_vec = game->var->move_vec / 1.2;
		if (game->var->move_vec > -5) {
			game->var->move_vec = 0;
			game->var->jump = 3;
		}
		return;
	}
	if (on_ground(game->obj, game->var) == 1 ||
	game->var->reserve_jump != 0 || game->var->cheat == 1) {
		sfMusic_play(game->music->jump);
		game->var->jump = 2;
		game->var->move_vec = -80;
		(game->var->reserve_jump != 2) ?
		(game->var->reserve_jump = 0) :(0);
	} else
		game->var->jump = 0;
}

static int **colision_tab(sfVector2f pos)
{
	int **tab = malloc(sizeof(int**) * 5);

	for (int i = 0 ; i < 5 ; i++)
		tab[i] = malloc(sizeof(int*) * 2);
	tab[0][0] = pos.x + 8;
	tab[0][1] = pos.y + 1;
	tab[1][0] = pos.x + 60;
	tab[1][1] = pos.y + 1;
	tab[2][0] = pos.x;
	tab[2][1] = pos.y + 119;
	tab[3][0] = pos.x + 60;
	tab[3][1] = pos.y + 119;
	tab[4][0] = pos.x + 65;
	tab[4][1] = pos.y + 60;
	return (tab);
}

static void applic_colision(game_t *game, my_block_t *block)
{
	if (block->type == TYPE_END_BLOCK) {
		game->var->menu = 2;
		game->var->win = 1;
	}
	if (block->type == TYPE_JUMP_BLOCK) {
		block->type = TYPE_VOID_BLOCK;
		(game->var->reserve_jump == 0) ? (game->var->reserve_jump = 1) :
		(0);
	}
	if ((block->type == TYPE_FULL_BLOCK || block->type == TYPE_PICK) &&
	game->var->cheat == 0) {
		game->var->menu = 2;
		game->var->win = 0;
	}
	if (block->type == TYPE_JUMP_INFINITE) {
		block->type = TYPE_VOID_BLOCK;
		game->var->reserve_jump = 2;
	}
}

static void detect_colision2(game_t *game, my_block_t *block, int **tab)
{
	sfVector2f pos = block->pos;

	for (int i = 0 ; i < 5 ; i++) {
		if (tab[i][0] > pos.x && tab[i][0] < pos.x + 100 &&
		tab[i][1] > pos.y && tab[i][1] < pos.y + 100)
			applic_colision(game, block);
	}
}

void detect_colision(game_t *game)
{
	my_object_t *obj = game->obj;
	int **col = colision_tab(game->obj->player->pos);
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};

	if (game->obj->player->pos.y > 980 && game->var->cheat == 0) {
		game->var->menu = 2;
		game->var->win = 0;
	}
	for (int i = 0 ; i < 10 ; i++) {
		for (int j = 0 ; j < 5 && tab[i] != NULL; j++) {
			detect_colision2(game, tab[i], col);
			tab[i] = (tab[i])->next;
		}
	}
	for (int i = 0 ; i < 5 ; i++)
		free(col[i]);
	free(col);
}
