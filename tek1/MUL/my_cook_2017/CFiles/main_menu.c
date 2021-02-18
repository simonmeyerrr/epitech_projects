/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** main_menu.c
*/

#include "all.h"

void prepare_game(game_t *game)
{
	my_obj_t *obj = malloc(sizeof(*obj));

	obj->time = 180.0;
	obj->score = 0;
	obj->have = malloc(sizeof(char) * 20);
	obj->status = 0;
	obj->animation = 0;
	game->var->menu = 1;
	game->clock->time = 0;
	srand(sfClock_getElapsedTime(game->clock->update).microseconds);
	sfClock_restart(game->clock->update);
	sfMusic_stop(game->music->music_menu);
	play_game(game, obj, game->clock->update);
	sfMusic_play(game->music->music_menu);
	end_game(game, obj);
	my_free(obj->have);
	my_free(obj);
}

void tutorial(game_t *game)
{
	sfTime time;
	int exit = 0;

	while (sfRenderWindow_isOpen(game->win) && exit == 0) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)) &&
		((game->event.type == sfEvtKeyPressed && game->event.key.code ==
		sfKeyEscape) || game->event.type == sfEvtMouseButtonPressed))
			exit = 1;
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			sfRenderWindow_drawSprite(game->win, game->sprite->tuto,
			NULL);
			sfRenderWindow_display(game->win);
		}
	}
}

static void event_main_menu(game_t *game, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyEscape) || (event.type == sfEvtMouseButtonPressed
	&& 180 * 4 - 80 <= event.mouseButton.y && 180 * 4 + 50 >=
	event.mouseButton.y && 1000 <= event.mouseButton.x && 1530 >=
	event.mouseButton.x))
		sfRenderWindow_close(win);
	if (event.type == sfEvtMouseButtonPressed)
		sfMusic_play(game->music->click);
	else
		return;
	if (180 - 80 <= event.mouseButton.y && 180 + 50 >= event.mouseButton.y
	&& 1000 <= event.mouseButton.x && 1530 >= event.mouseButton.x)
		prepare_game(game);
	if (360 - 80 <= event.mouseButton.y && 360 + 50 >= event.mouseButton.y
	&& 1000 <= event.mouseButton.x && 1530 >= event.mouseButton.x)
		tutorial(game);
	if (540 - 80 <= event.mouseButton.y && 540 + 50 >= event.mouseButton.y
	&& 1000 <= event.mouseButton.x && 1530 >= event.mouseButton.x)
		settings(game);
}

static void display_main_menu(game_t *game, sfRenderWindow *win,
my_sprite_t *sprite, my_text_t *text)
{
	sfVector2f pos = get_mouse_pos(win);

	sfRenderWindow_drawSprite(win, sprite->main_menu, NULL);
	for (int j = 1 ; j < 5 ; j++)
		set_pos_draw(sprite->button_off, win,
		create_vector(1000, 180 * j - 80));
	for (int j = 1 ; j < 5 ; j++)
		if (180 * j - 80 <= pos.y && 180 * j + 50 >= pos.y && 1000
		<= pos.x && 1530 >= pos.x)
			set_pos_draw(sprite->button_on, win,
			create_vector(1000, 180 * j - 80));
	sfRenderWindow_drawText(win, text->play, NULL);
	sfRenderWindow_drawText(win, text->settings_menu, NULL);
	sfRenderWindow_drawText(win, text->tutorial, NULL);
	sfRenderWindow_drawText(win, text->exit_menu, NULL);
	if (590 <= pos.y && 800 >= pos.y && 440 <= pos.x && 540 >= pos.x)
		set_pos_draw(sprite->easter_egg, win, create_vector(440, 590));
	if (570 <= pos.y && 750 >= pos.y && 40 <= pos.x && 190 >= pos.x)
		set_pos_draw(sprite->easter_egg2, win, create_vector(40, 570));
	set_pos_draw(sprite->mouse, win, pos);
}

void main_menu(game_t *game)
{
	sfTime time;

	while (sfRenderWindow_isOpen(game->win)) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_main_menu(game, game->event, game->win);
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_main_menu(game, game->win, game->sprite,
			game->text);
			sfRenderWindow_display(game->win);
		}
	}
}
