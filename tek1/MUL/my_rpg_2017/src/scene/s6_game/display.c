/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static sfVector2f get_map_pos(global_t *global)
{
	sfVector2f pos = {0, 0};

	pos.x = 760 - (global->game->pos[0] * 80);
	pos.y = 410 - (global->game->pos[1] * 80);
	if (global->game->dir == DIR_DOWN)
		pos.y -= global->game->move_status * 6.6;
	if (global->game->dir == DIR_UP)
		pos.y += global->game->move_status * 6.6;
	if (global->game->dir == DIR_LEFT)
		pos.x += global->game->move_status * 6.6;
	if (global->game->dir == DIR_RIGHT)
		pos.x -= global->game->move_status * 6.6;
	return (pos);
}

static void disp_env(sfRenderWindow *win, my_sprite_t *sprite, game_t *game)
{
	sfIntRect rect = {0, 0, 70, 100};
	sfVector2f pos = VEC(765 - (game->pos[0] * 80),
	380 - (game->pos[1] * 80));

	if (game->dir == DIR_DOWN)
		pos.y -= game->move_status * 6.6;
	if (game->dir == DIR_UP)
		pos.y += game->move_status * 6.6;
	if (game->dir == DIR_LEFT)
		pos.x += game->move_status * 6.6;
	if (game->dir == DIR_RIGHT)
		pos.x -= game->move_status * 6.6;
	for (env_t *tmp = game->first_env ; tmp ; tmp = tmp->next)
		if (game->progression <= tmp->prog_max) {
			sfSprite_setTextureRect(sprite->world[tmp->image],
			rect);
			my_draw_sprite(win, sprite->world[tmp->image], VEC(pos.x
			+ tmp->pos[0] * 80, pos.y + tmp->pos[1] * 80));
		}
}

static void display_text(global_t *global, my_text_t *text, my_font_t *font,
sfRenderWindow *win)
{
	char *str = my_strdup(text->text[text->elem]);

	str[text->chars] = '\0';
	my_draw_sprite(global->win, global->sprite->image[IM_CHAT],
	VEC(0, 650));
	my_draw_text(win, TEXT(VEC(20, 660), 50, sfBlack, font->font3),
	str, 1);
}

void display_game(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	sfIntRect rect = {0, 0, 70, 100};

	rect.top = global->game->dir * 100;
	rect.left = (global->game->move_status / 3) * 70;
	my_draw_sprite(global->win, sprite->world[WD_MAP], get_map_pos(global));
	disp_env(global->win, global->sprite, global->game);
	sfSprite_setTextureRect(sprite->world[WD_CORO1], rect);
	sfSprite_setTextureRect(sprite->world[WD_CORO2], rect);
	if (global->game->progression <= 1)
		my_draw_sprite(global->win, sprite->world[WD_CORO1],
		VEC(765, 380));
	else
		my_draw_sprite(global->win, sprite->world[WD_CORO2],
		VEC(765, 380));
	if (global->game->pos[0] < 30 && global->game->pos[1] < 82 &&
	global->game->pos[1] > 65)
		sfRenderWindow_drawPrimitives(win, global->game->snow->vertex,
			global->game->snow->size * 4, sfQuads, NULL);
	if (global->game->text)
		display_text(global, global->game->text, font, win);
}
