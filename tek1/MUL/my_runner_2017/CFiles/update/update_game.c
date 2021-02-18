/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** update_game.c
*/

#include "all.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
	if ((*rect).left == max_value - offset)
		(*rect).left = 0;
	else
		(*rect).left += offset;
}

static void update_game3(game_t *game)
{
	sfVector2f pos1 = sfSprite_getPosition(game->sprite->background1);
	sfVector2f pos2 = sfSprite_getPosition(game->sprite->background2);
	sfVector2f pos3 = sfSprite_getPosition(game->sprite->background3);

	if (pos1.x <= -3000)
		sfSprite_setPosition(game->sprite->background1,
		create_vector(0, 0));
	if (pos2.x <= -2500)
		sfSprite_setPosition(game->sprite->background2,
		create_vector(pos2.x + 2500, pos2.y));
	if (pos3.x <= -2500)
		sfSprite_setPosition(game->sprite->background3,
		create_vector(pos3.x + 2500, pos3.y));
	sfSprite_move(game->sprite->background1, create_vector(-2, 0));
	sfSprite_move(game->sprite->background2, create_vector(-10, 0));
	sfSprite_move(game->sprite->background3, create_vector(-5, 0));
}

static void update_game2(game_t *game)
{
	detect_colision(game);
	if (game->obj->player->move_rect > 1) {
		move_rect(&(game->obj->player->rect), 75, 450);
		sfSprite_setTextureRect(game->sprite->player,
		game->obj->player->rect);
		game->obj->player->move_rect = 0;
	}
	game->obj->player->move_rect = game->obj->player->move_rect + 1;
	if (on_ground(game->obj, game->var) == 1)
		game->var->reserve_jump = 0;
	jump(game);
	game->var->pourcent = game->var->position * 100 /
	game->var->end_distance;
	if (game->var->pourcent > 99)
		game->var->pourcent = 99;
	update_game3(game);
}

static void decal_block(my_object_t *obj)
{
	obj->line0 = obj->line0->next;
	obj->line1 = obj->line1->next;
	obj->line2 = obj->line2->next;
	obj->line3 = obj->line3->next;
	obj->line4 = obj->line4->next;
	obj->line5 = obj->line5->next;
	obj->line6 = obj->line6->next;
	obj->line7 = obj->line7->next;
	obj->line8 = obj->line8->next;
	obj->line9 = obj->line9->next;
}

void update_game(game_t *game)
{
	my_object_t *obj = game->obj;
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};
	int j;

	if (tab[0] != NULL && tab[0]->pos.x <= -95) {
		decal_block(game->obj);
		game->var->position += 1;
	}
	for (int i = 0 ; i < 10  && tab[i] != NULL; i++) {
		j = 0;
		tab[i]->pos.x = tab[i]->pos.x - 20;
		tab[i] = (tab[i])->next;
		while (tab[i] != NULL && j < 21) {
			tab[i]->pos.x = tab[i]->prev->pos.x + 100;
			tab[i] = (tab[i])->next;
			j++;
		}
	}
	update_game2(game);
}
