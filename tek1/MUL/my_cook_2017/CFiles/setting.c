/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** setting.c
*/

#include "all.h"

static void change_volume(int i, my_var_t *var, my_music_t *music,
my_text_t *text)
{
	char *tab[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

	if (i < 2) {
		if (i == 0 && var->music > 0)
			var->music = var->music - 1;
		if (i == 1 && var->music < 10)
			var->music = var->music + 1;
		sfMusic_setVolume(music->music_menu, var->music * 10);
		sfMusic_setVolume(music->music_game, var->music * 10);
		sfText_setString(text->music, tab[var->music]);
	}
	if (i >= 2) {
		if (i == 2 && var->sound > 0)
			var->sound = var->sound - 1;
		if (i == 3 && var->sound < 10)
			var->sound = var->sound + 1;
		sfMusic_setVolume(music->click, var->sound * 10);
		sfText_setString(text->sound, tab[var->sound]);
	}
}

static void event_setting(game_t *game, sfEvent event,
sfRenderWindow *win)
{
	int tab[] = {109, 455, 970, 1316};

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
	for (int i = 0 ; i < 4 ; i++) {
		if (event.mouseButton.x >= tab[i] && event.mouseButton.x <=
		tab[i] + 173 && event.mouseButton.y >= 282 &&
		event.mouseButton.y <= 455)
			change_volume(i, game->var, game->music, game->text);
	}
}

static void display_setting(game_t *game, sfRenderWindow *win,
my_sprite_t *sprite, my_text_t *text)
{
	sfVector2f pos = get_mouse_pos(win);
	int tab[] = {109, 455, 970, 1316};

	sfRenderWindow_drawSprite(win, sprite->setting, NULL);
	set_pos_draw((pos.x >= 525 && pos.x <= 1075 && pos.y >= 700 && pos.y <=
	850) ? (sprite->button_on) : (sprite->button_off), win,
	create_vector(525, 700));
	for (int i = 0 ; i < 4 ; i++) {
		if (pos.x >= tab[i] && pos.x <= tab[i] + 173 && pos.y >= 282 &&
		pos.y <= 455)
			set_pos_draw(sprite->button2, win,
			create_vector(tab[i], 282));
	}
	sfRenderWindow_drawText(win, text->plus_minus, NULL);
	sfRenderWindow_drawText(win, text->sound, NULL);
	sfRenderWindow_drawText(win, text->music, NULL);
	sfRenderWindow_drawText(win, text->return_set, NULL);
	set_pos_draw(sprite->mouse, win, pos);
}

void settings(game_t *game)
{
	sfTime time;
	game->var->menu = 1;

	while (sfRenderWindow_isOpen(game->win) && game->var->menu) {
		while (sfRenderWindow_pollEvent(game->win, &(game->event)))
			event_setting(game, game->event, game->win);
		time = sfClock_getElapsedTime(game->clock->frame_rate);
		if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
			sfClock_restart(game->clock->frame_rate);
			sfRenderWindow_clear(game->win, sfBlack);
			display_setting(game, game->win, game->sprite,
			game->text);
			sfRenderWindow_display(game->win);
		}
	}
}
