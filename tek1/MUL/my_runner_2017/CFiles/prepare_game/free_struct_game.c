/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** free_struct_game.c
*/

#include "all.h"

static void free_texture(my_texture_t *texture)
{
	sfTexture_destroy(texture->player);
	sfTexture_destroy(texture->full_block);
	sfTexture_destroy(texture->semi_block);
	sfTexture_destroy(texture->jump_block);
	sfTexture_destroy(texture->jump_infinite);
	sfTexture_destroy(texture->end_block);
	sfTexture_destroy(texture->pick);
	sfTexture_destroy(texture->background1);
	sfTexture_destroy(texture->background2);
	sfTexture_destroy(texture->background3);
	sfTexture_destroy(texture->pause_menu);
	sfTexture_destroy(texture->end_menu);
	sfTexture_destroy(texture->mouse);
	free(texture);
}

static void free_sprite(my_sprite_t *sprite)
{
	sfSprite_destroy(sprite->player);
	sfSprite_destroy(sprite->full_block);
	sfSprite_destroy(sprite->semi_block);
	sfSprite_destroy(sprite->jump_block);
	sfSprite_destroy(sprite->jump_infinite);
	sfSprite_destroy(sprite->end_block);
	sfSprite_destroy(sprite->pick);
	sfSprite_destroy(sprite->background1);
	sfSprite_destroy(sprite->background2);
	sfSprite_destroy(sprite->background3);
	sfSprite_destroy(sprite->pause_menu);
	sfSprite_destroy(sprite->end_menu);
	sfSprite_destroy(sprite->mouse);
	free(sprite);
}

static void free_music_clock_text(my_music_t *music, my_clock_t *clock,
my_text_t *text)
{
	sfMusic_destroy(music->game);
	sfMusic_destroy(music->death);
	sfMusic_destroy(music->jump);
	sfMusic_destroy(music->win);
	free(music);
	sfClock_destroy(clock->frame_rate);
	sfClock_destroy(clock->update);
	free(clock);
	sfFont_destroy(text->font);
	sfText_destroy(text->score);
	sfText_destroy(text->end_score);
	sfText_destroy(text->win);
	sfText_destroy(text->lose);
	free(text);
}

static void free_obj(my_object_t *obj)
{
	my_block_t *tab[10] = {obj->line0, obj->line1, obj->line2, obj->line3,
	obj->line4, obj->line5, obj->line6, obj->line7, obj->line8, obj->line9};

	for (int i = 0 ; i < 10 ; i++) {
		while ((tab[i])->prev != NULL)
			tab[i] = (tab[i])->prev;
		while ((tab[i])->next != NULL) {
			tab[i] = (tab[i])->next;
			free((tab[i])->prev);
		}
		free(tab[i]);
	}
	free(obj->player);
	free(obj);
}

int free_struct_game(game_t *game, int *settings)
{
	if (game->var->win == 1)
		settings[2] = 1;
	free(game->var);
	free_texture(game->texture);
	free_sprite(game->sprite);
	free_music_clock_text(game->music, game->clock, game->text);
	free_obj(game->obj);
	free(game);
	return (settings[2]);
}
