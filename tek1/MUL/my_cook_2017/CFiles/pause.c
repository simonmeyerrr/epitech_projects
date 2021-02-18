/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** setting.c
*/

#include "all.h"

static void event_pause(game_t *game, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
		game->var->menu = 1;
	if (event.type == sfEvtMouseButtonPressed)
		sfMusic_play(game->music->click);
	else
		return;
	if (event.mouseButton.x >= 525 && event.mouseButton.x <= 1075 &&
	event.mouseButton.y >= 220 && event.mouseButton.y <= 370)
		game->var->menu = 1;
	if (event.mouseButton.x >= 525 && event.mouseButton.x <= 1075 &&
	event.mouseButton.y >= 400 && event.mouseButton.y <= 550) {
		settings(game);
		game->var->menu = 2;
	}
	if (event.mouseButton.x >= 525 && event.mouseButton.x <= 1075 &&
	event.mouseButton.y >= 580 && event.mouseButton.y <= 730)
		game->var->menu = 0;
}

static void display_pause(game_t *game, sfRenderWindow *win,
my_sprite_t *sprite, my_text_t *text)
{
	sfVector2f pos = get_mouse_pos(win);

	sfRenderWindow_drawSprite(win, sprite->pause, NULL);
	for (int i = 0 ; i < 3 ; i++) {
		set_pos_draw((pos.x >= 525 && pos.x <= 1075 && pos.y >= i * 180
		+ 220 && pos.y <= i * 180 + 370) ? (sprite->button_on) :
		(sprite->button_off), win, create_vector(525, i * 180 + 220));
	}
	sfRenderWindow_drawText(win, text->resume, NULL);
	sfRenderWindow_drawText(win, text->set_pause, NULL);
	sfRenderWindow_drawText(win, text->exit_pause, NULL);
	set_pos_draw(sprite->mouse, win, pos);
}

void pause_game(game_t *game)
{
	sfTime time;
	game->var->menu = 2;

	while (sfRenderWindow_isOpen(game->win) && game->var->menu == 2) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_pause(game, game->event, game->win);
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_pause(game, game->win, game->sprite,
			game->text);
			sfRenderWindow_display(game->win);
		}
	}
}
