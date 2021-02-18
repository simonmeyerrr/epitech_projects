/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** game.c
*/

#include "all.h"

static char get_ingredient(sfEvent event)
{
	sfKeyCode tab1[12] = {sfKeyS, sfKeyC, sfKeyD, sfKeyE, sfKeyL, sfKeyB,
	sfKeyT, sfKeyK, sfKeyO, sfKeyM, sfKeyP, sfKeyQ};
	char tab2[12] = "SCDELBTKOMPQ";

	if (event.type != sfEvtKeyPressed)
		return ('\0');
	for (int i = 0 ; i < 12 ; i++) {
		if (event.key.code == tab1[i])
			return (tab2[i]);
	}
	return ('\0');
}

static void event_game(game_t *game, my_obj_t *obj, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
		game->clock->time +=
		sfClock_getElapsedTime(game->clock->update).microseconds;
		game->var->menu = 2;
		pause_game(game);
		sfClock_restart(game->clock->update);
	}
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn)
		obj->status = 2;
	if (obj->status == 1)
		obj->have[my_strlen(obj->have)] = get_ingredient(event);
}

static void display_burger(my_sprite_t *sprite, char *have, int status,
sfRenderWindow *win)
{
	sfVector2f pos = {190, 460};
	char tab1[12] = "SCDELBTKOMPQ";
	sfSprite *tab2[12] = {sprite->steak, sprite->chicken, sprite->cheddar,
	sprite->emmental, sprite->lettuce, sprite->bacon, sprite->tomatoes,
	sprite->ketchup, sprite->onions, sprite->mayonnaise, sprite->pickles,
	sprite->bbq};
	int j = 0;

	for (int i = 0 ; have[i] != '\0' ; i) {
		if (tab1[j] == have[i])
			set_pos_draw(tab2[j], win, pos);
		if (j == 11) {
			pos.y -= 40;
			i++;
			j = 0;
		} else
			j++;
	}
	if (status == 4)
		set_pos_draw(sprite->bread2, win, pos);
}

static void display_game(game_t *game, my_obj_t *obj, sfRenderWindow *win)
{
	char *score = int_to_str(obj->score);
	char *time = time_to_str(obj->time);

	sfRenderWindow_drawSprite(win, game->sprite->game, NULL);
	sfText_setString(game->text->score, score);
	sfText_setString(game->text->time, time);
	sfRenderWindow_drawText(win, game->text->score, NULL);
	sfRenderWindow_drawText(win, game->text->time, NULL);
	sfRenderWindow_drawText(win, game->text->cook, NULL);
	sfRenderWindow_drawText(win, game->text->recipe, NULL);
	my_free(score);
	my_free(time);
	if (obj->status != 0 && obj->animation < 15) {
		set_pos_draw(game->sprite->bread1, win,
		create_vector(190, 520));
		display_burger(game->sprite, obj->have, obj->status, win);
	}
	if (obj->status == 3 || obj->status == 4)
		set_pos_draw((obj->status == 3) ? (game->sprite->fail) :
		(game->sprite->validation), win, create_vector(329, 100));
}

void play_game(game_t *game, my_obj_t *obj, sfClock *up)
{
	sfMusic_play(game->music->music_game);
	while (sfRenderWindow_isOpen(game->win) && game->var->menu == 1) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_game(game, obj, game->event, game->win);
		game->clock->time += sfClock_getElapsedTime(up).microseconds;
		sfClock_restart(up);
		while (game->clock->time / 1000000.0 > 1.0 / 30.0) {
			game->clock->time -= 1000000.0 / 30.0;
			update_game(game, obj);
		}
		if (sfClock_getElapsedTime(game->clock->frame_rate).microseconds
		/ 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_game(game, obj, game->win);
			sfRenderWindow_display(game->win);
		}
	}
	sfMusic_stop(game->music->music_game);
}
