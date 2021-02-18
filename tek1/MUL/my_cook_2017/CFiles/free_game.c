/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** free_game.c
*/

#include "all.h"

static void free_texture(my_texture_t *text)
{
	sfTexture **tab[30] = {&text->main_menu, &text->button_off,
	&text->button_on, &text->black, &text->white, &text->mouse,
	&text->easter_egg, &text->easter_egg2, &text->game, &text->bread1,
	&text->bread2, &text->steak, &text->chicken, &text->cheddar,
	&text->emmental, &text->lettuce, &text->bacon, &text->tomatoes,
	&text->ketchup, &text->onions, &text->mayonnaise, &text->pickles,
	&text->bbq, &text->tuto, &text->fail, &text->validation,
	&text->setting, &text->button2, &text->end, &text->pause};

	for (int i = 0 ; i < 30 ; i++) {
		if (*tab[i])
			sfTexture_destroy(*tab[i]);
	}
	my_free(text);
}

static void free_sprite(my_sprite_t *sprite)
{
	sfSprite **tab[30] = {&sprite->main_menu, &sprite->button_off,
	&sprite->button_on, &sprite->black, &sprite->white, &sprite->mouse,
	&sprite->easter_egg, &sprite->easter_egg2, &sprite->game,
	&sprite->bread1, &sprite->bread2, &sprite->steak, &sprite->chicken,
	&sprite->cheddar, &sprite->emmental, &sprite->lettuce, &sprite->bacon,
	&sprite->tomatoes, &sprite->ketchup, &sprite->onions,
	&sprite->mayonnaise, &sprite->pickles, &sprite->bbq, &sprite->tuto,
	&sprite->fail, &sprite->validation, &sprite->setting, &sprite->button2,
	&sprite->end, &sprite->pause};

	for (int i = 0 ; i < 30 ; i++) {
		if (*tab[i])
			sfSprite_destroy(*tab[i]);
	}
	my_free(sprite);
}

static void free_text(my_text_t *text)
{
	sfText **tab[18] = {&text->play, &text->settings_menu, &text->exit_menu,
	&text->tutorial, &text->plus_minus, &text->return_set, &text->exit_end,
	&text->resume, &text->score, &text->time, &text->cook,
	&text->recipe, &text->music, &text->sound, &text->end_score,
	&text->high_score, &text->set_pause, &text->exit_pause};

	for (int i = 0 ; i < 18 ; i++) {
		if (*tab[i])
			sfText_destroy(*tab[i]);
	}
	sfFont_destroy(text->font1);
	sfFont_destroy(text->font2);
	my_free(text);
}

void free_game(game_t *game)
{
	if (!game)
		return;
	if (game->win)
		sfRenderWindow_destroy(game->win);
	free_texture(game->texture);
	free_sprite(game->sprite);
	free_text(game->text);
	sfMusic_destroy(game->music->click);
	sfMusic_destroy(game->music->music_menu);
	sfMusic_destroy(game->music->music_game);
	my_free(game->music);
	sfClock_destroy(game->clock->update);
	sfClock_destroy(game->clock->frame_rate);
	my_free(game->clock);
	my_free(game->var);
	my_free(game);
}
