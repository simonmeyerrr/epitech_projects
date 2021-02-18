/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** end_game.c
*/

#include "all.h"

static void prepare_end(game_t *game, my_obj_t *obj, char *str, int score)
{
	int fd = open(HIGH_SCORE, O_RDONLY);

	sfText_setString(game->text->end_score, str);
	if (fd > 0) {
		read(fd, &score, 4);
		close(fd);
	}
	if (score < obj->score) {
		fd = open(HIGH_SCORE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd > 0) {
			write(fd, &(obj->score), 4);
			close(fd);
		}
		sfText_setString(game->text->high_score, str);
	} else {
		my_free(str);
		str = int_to_str(score);
		sfText_setString(game->text->high_score, str);
	}
	my_free(str);
}

static void event_end(game_t *game, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
		game->var->menu = 0;
	if (event.type == sfEvtMouseButtonPressed)
		sfMusic_play(game->music->click);
	else
		return;
	if (event.mouseButton.x >= 525 && event.mouseButton.x <= 1075 &&
	event.mouseButton.y >= 700 && event.mouseButton.y <= 850)
		game->var->menu = 0;
}

static void display_end(game_t *game, sfRenderWindow *win,
my_sprite_t *sprite, my_text_t *text)
{
	sfVector2f pos = get_mouse_pos(win);

	sfRenderWindow_drawSprite(win, sprite->end, NULL);
	sfRenderWindow_drawText(win, text->end_score, NULL);
	sfRenderWindow_drawText(win, text->high_score, NULL);
	set_pos_draw((pos.x >= 525 && pos.x <= 1075 && pos.y >= 700 && pos.y <=
	850) ? (sprite->button_on) : (sprite->button_off), win,
	create_vector(525, 700));
	sfRenderWindow_drawText(win, text->exit_end, NULL);
	set_pos_draw(sprite->mouse, win, pos);
}

void end_game(game_t *game, my_obj_t *obj)
{
	sfTime time;
	game->var->menu = 1;

	prepare_end(game, obj, int_to_str(obj->score), 0);
	while (sfRenderWindow_isOpen(game->win) && game->var->menu) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_end(game, game->event, game->win);
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_end(game, game->win, game->sprite,
			game->text);
			sfRenderWindow_display(game->win);
		}
	}
}
