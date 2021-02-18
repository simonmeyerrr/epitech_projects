/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** game.c
*/

#include "all.h"

static void display_end(sfRenderWindow *win, game_t *game)
{
	sfVector2f pos = get_mouse_pos(win);
	char *str = pourcent_to_str(game->var->pourcent);

	if (game->var->win == 0) {
		sfText_setString(game->text->end_score, str);
		sfText_setPosition(game->text->end_score,
		create_vector(810, 10));
	}
	free(str);
	sfRenderWindow_drawSprite(win, game->sprite->background1, NULL);
	sfRenderWindow_drawSprite(win, game->sprite->background3, NULL);
	sfRenderWindow_drawSprite(win, game->sprite->background2, NULL);
	display_map(game->obj, game->sprite, win);
	sfRenderWindow_drawSprite(win, game->sprite->player, NULL);
	sfRenderWindow_drawSprite(win, game->sprite->end_menu, NULL);
	sfRenderWindow_drawText(win, game->text->end_score, NULL);
	sfRenderWindow_drawText(win, (game->var->win == 0) ? (game->text->lose)
	: (game->text->win), NULL);
	sfSprite_setPosition(game->sprite->mouse, pos);
	sfRenderWindow_drawSprite(win, game->sprite->mouse, NULL);
}

static void end_menu(sfRenderWindow *win, game_t *game)
{
	sfTime time;

	while (sfRenderWindow_pollEvent(win, &(game->event)))
		analyze_event_end(game, game->event, win);
	time = sfClock_getElapsedTime(game->clock->frame_rate);
	if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
		sfClock_restart(game->clock->frame_rate);
		sfRenderWindow_clear(win, sfBlack);
		display_end(win, game);
		sfRenderWindow_display(win);
	}
}

static void the_game(sfRenderWindow *win, game_t *game)
{
	sfTime time;

	while (sfRenderWindow_pollEvent(win, &(game->event)))
		analyze_event_game(game, game->event, win);
	time = sfClock_getElapsedTime(game->clock->update);
	if (time.microseconds / 1000000.0 > 1.0 / 30.0 &&
	game->var->pause == 0) {
		sfClock_restart(game->clock->update);
		update_game(game);
	}
	time = sfClock_getElapsedTime(game->clock->frame_rate);
	if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
		sfClock_restart(game->clock->frame_rate);
		display_game(game, win);
	}
}

int my_runner(sfRenderWindow *win, char **map, int *error, int *settings)
{
	game_t *game = prepare_game(map, error, settings);

	if (*error != 0)
		return (0);
	while (sfRenderWindow_isOpen(win) && game->var->menu != 0) {
		while (sfRenderWindow_isOpen(win) && game->var->menu == 1)
			the_game(win, game);
		sfMusic_stop(game->music->game);
		(game->var->win == 0) ? (sfMusic_play(game->music->death)) :
		(sfMusic_play(game->music->win));
		while (sfRenderWindow_isOpen(win) && game->var->menu == 2)
			end_menu(win, game);
	}
	if (game->var->menu == 0 && game->var->restart == 1) {
		free_struct_game(game, settings);
		return (my_runner(win, map, error, settings));
	}
	return (free_struct_game(game, settings));
}
