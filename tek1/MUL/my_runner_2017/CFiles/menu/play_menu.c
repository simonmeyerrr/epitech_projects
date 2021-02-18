/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** play_menu.c
*/

#include "all.h"

static void play_game(int level, menu_t *menu, sfRenderWindow *win)
{
	int ret;
	int error = 0;
	char **map;
	char *tab[11] = TAB_MAP;
	int settings[4] = {menu->var->sound, menu->var->theme, 0,
	menu->var->font};

	if (level > menu->var->level_max)
		return;
	map = open_map(tab[level - 1], &error);
	if (error != 0)
		return;
	ret = my_runner(win, map, &error, settings);
	free_map(map);
	if (ret == 1 && level == menu->var->level_max &&
	menu->var->level_max < 11)
		menu->var->level_max += 1;
	if (ret == 1 && level == 11)
		write(1, "You are a god.\n", 15);
}

static void analyze_event_play_menu(menu_t *menu, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (IF_RETURN(event))
		menu->var->menu = 1;
	if (event.type == sfEvtMouseButtonPressed)
		sfMusic_play(menu->music->click);
	else
		return;
	for (int i = 0 ; i < 5 ; i++) {
		if (event.mouseButton.x >= 260 + (i * 300) &&
		event.mouseButton.x <= 460 + (i * 300) && event.mouseButton.y
		>= 100 && event.mouseButton.y <= 300)
			play_game(i + 1, menu, win);
		if (event.mouseButton.x >= 260 + (i * 300) &&
		event.mouseButton.x <= 460 + (i * 300) && event.mouseButton.y
		>= 400 && event.mouseButton.y <= 600)
			play_game(i + 6, menu, win);
	}
	if (IF_LAST_LEVEL(event))
		play_game(11, menu, win);
}

static void display_lock_level(menu_t *menu, sfRenderWindow *win)
{
	for (int i = menu->var->level_max ; i < 5 ; i++) {
		sfSprite_setPosition(menu->sprite->lock,
		create_vector(260 + (i * 300), 100));
		sfRenderWindow_drawSprite(win, menu->sprite->lock, NULL);
	}
	for (int i = menu->var->level_max - 5 ; i < 5 ; i++) {
		(i < 0) ? (i = 0) : (0);
		sfSprite_setPosition(menu->sprite->lock,
		create_vector(260 + (i * 300), 400));
		sfRenderWindow_drawSprite(win, menu->sprite->lock, NULL);
	}
	if (menu->var->level_max < 11) {
		sfSprite_setPosition(menu->sprite->lock,
		create_vector(860, 700));
		sfRenderWindow_drawSprite(win, menu->sprite->lock, NULL);
	}
}

void play_menu(menu_t *menu, sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(win);
	sfTime time = sfClock_getElapsedTime(menu->frame_rate);

	if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
		sfClock_restart(menu->frame_rate);
		sfRenderWindow_clear(win, sfBlack);
		sfRenderWindow_drawSprite(win, menu->sprite->play_menu, NULL);
		sfRenderWindow_drawText(win, menu->text->level1, NULL);
		sfRenderWindow_drawText(win, menu->text->level2, NULL);
		sfRenderWindow_drawText(win, menu->text->level3, NULL);
		sfRenderWindow_drawText(win, menu->text->level4, NULL);
		display_lock_level(menu, win);
		sfSprite_setPosition(menu->sprite->mouse, pos);
		sfRenderWindow_drawSprite(win, menu->sprite->mouse, NULL);
		sfRenderWindow_display(win);
	}
	while (sfRenderWindow_pollEvent(win, &(menu->event)))
		analyze_event_play_menu(menu, menu->event, win);
}
