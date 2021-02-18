/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** display_game.c
*/

#include "all.h"

static void display_block2(int type, sfVector2f pos, my_sprite_t *sprite,
sfRenderWindow *win)
{
	if (type == TYPE_PICK) {
		sfSprite_setPosition(sprite->pick, pos);
		sfRenderWindow_drawSprite(win, sprite->pick, NULL);
	} else if (type == TYPE_JUMP_INFINITE) {
		sfSprite_setPosition(sprite->jump_infinite, pos);
		sfRenderWindow_drawSprite(win, sprite->jump_infinite, NULL);
	}
}

static void display_block(int type, sfVector2f pos, my_sprite_t *sprite,
sfRenderWindow *win)
{
	if (type == TYPE_FULL_BLOCK) {
		sfSprite_setPosition(sprite->full_block, pos);
		sfRenderWindow_drawSprite(win, sprite->full_block, NULL);
	}
	if (type == TYPE_SEMI_BLOCK) {
		sfSprite_setPosition(sprite->semi_block, pos);
		sfRenderWindow_drawSprite(win, sprite->semi_block, NULL);
	}
	if (type == TYPE_JUMP_BLOCK) {
		sfSprite_setPosition(sprite->jump_block, pos);
		sfRenderWindow_drawSprite(win, sprite->jump_block, NULL);
	} else if (type == TYPE_END_BLOCK) {
		sfSprite_setPosition(sprite->end_block, pos);
		sfRenderWindow_drawSprite(win, sprite->end_block, NULL);
	}
	display_block2(type, pos, sprite, win);
}

void display_map(my_object_t *obj, my_sprite_t *sprite, sfRenderWindow *win)
{
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};
	int j = 0;

	for (int i = 0 ; i < 10 ; i++) {
		j = 0;
		while (tab[i] != NULL && j < 21) {
			display_block((tab[i])->type, (tab[i])->pos, sprite,
			win);
			tab[i] = (tab[i])->next;
			j++;
		}
	}
}

static void display_pause(sfRenderWindow *win, game_t *game)
{
	sfVector2f pos = get_mouse_pos(win);

	sfRenderWindow_drawSprite(win, game->sprite->pause_menu, NULL);
	sfSprite_setPosition(game->sprite->mouse, pos);
	sfRenderWindow_drawSprite(win, game->sprite->mouse, NULL);
}

void display_game(game_t *game, sfRenderWindow *win)
{
	char *str = pourcent_to_str(game->var->pourcent);

	sfText_setString(game->text->score, str);
	free(str);
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawSprite(win, game->sprite->background1, NULL);
	sfRenderWindow_drawSprite(win, game->sprite->background3, NULL);
	sfRenderWindow_drawSprite(win, game->sprite->background2, NULL);
	display_map(game->obj, game->sprite, win);
	sfSprite_setPosition(game->sprite->player, game->obj->player->pos);
	sfRenderWindow_drawSprite(win, game->sprite->player, NULL);
	sfRenderWindow_drawText(win, game->text->score, NULL);
	(game->var->pause == 1) ? (display_pause(win, game)) : (0);
	sfRenderWindow_display(win);
}
