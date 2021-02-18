/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** start_animation.c
*/

#include "all.h"

static void event_animation(game_t *game, sfEvent event,
sfRenderWindow *win, int *i)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed)
		*i = 120;
}

static void display_start_animation(game_t *game, sfRenderWindow *win, int i)
{
	sfRenderWindow_drawSprite(win, game->sprite->main_menu, NULL);
	for (int j = 0 ; i < 100 && j < 4 ; j++) {
		sfSprite_setPosition(game->sprite->button_off,
		create_vector(1000, 180 * (j + 1) * i / 100 - 80));
		sfRenderWindow_drawSprite(win, game->sprite->button_off, NULL);
	}
	for (int j = 0 ; i >= 100 && j < 4 ; j++) {
		sfSprite_setPosition(game->sprite->button_off,
		create_vector(1000, 180 * (j + 1) - 80));
		sfRenderWindow_drawSprite(win, game->sprite->button_off, NULL);
	}
	for (int j = 20 ; j > i / 2.5 ; j--)
		sfRenderWindow_drawSprite(win, game->sprite->black, NULL);
	for (int j = 0 ; j < (i - 100) && j < 10 ; j++)
		sfRenderWindow_drawSprite(win, game->sprite->white, NULL);
}

void start_animation(game_t *game)
{
	int i = 0;
	sfTime time;

	while (i < 110 && sfRenderWindow_isOpen(game->win)) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_animation(game, game->event, game->win, &i);
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0 && i < 120) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_start_animation(game, game->win, i);
			sfRenderWindow_display(game->win);
			i++;
		}
	}
}
