/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** settings.c
*/

#include "all.h"

static void change_volume_theme(int i, menu_t *menu, int a)
{
	if (a == 1) {
		if (i == menu->var->sound)
			return;
		menu->var->sound = i;
		sfMusic_setVolume(menu->music->click, menu->var->sound * 10);
		return;
	}
	if (i == menu->var->theme)
		return;
	menu->var->theme = i;
}

static void change_font(int i, menu_t *menu)
{
	sfFont *font = (i == 0) ? (menu->text->font1) : (menu->text->font2);

	if (i == menu->var->font)
		return;
	menu->var->font = i;
	sfText_setFont(menu->text->main_menu, font);
	sfText_setFont(menu->text->my_runner, font);
	sfText_setFont(menu->text->int_volume, font);
	sfText_setFont(menu->text->ten, font);
	sfText_setFont(menu->text->volume, font);
	sfText_setFont(menu->text->level1, font);
	sfText_setFont(menu->text->level2, font);
	sfText_setFont(menu->text->level3, font);
	sfText_setFont(menu->text->level4, font);
}

static void analyze_event_settings(menu_t *menu, sfEvent event,
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
	for (int i = 0 ; i < 11 ; i++) {
		if (IF_VOLUME(event, i))
			change_volume_theme(i, menu, 1);
	}
	for (int i = 0 ; i < 2 ; i++) {
		if (IF_THEME(event, i))
			change_volume_theme(i, menu, 2);
		if (IF_FONT(event, i))
			change_font(i, menu);
	}
}

static void display_settings_selection(menu_t *menu, sfRenderWindow *win)
{
	sfSprite_setPosition(menu->sprite->border,
	create_vector(160 + (menu->var->theme * 400), 450));
	sfRenderWindow_drawSprite(win, menu->sprite->border, NULL);
	sfSprite_setPosition(menu->sprite->border,
	create_vector(1060 + (menu->var->font * 400), 450));
	sfRenderWindow_drawSprite(win, menu->sprite->border, NULL);
	sfSprite_setPosition(menu->sprite->little_border,
	create_vector(135 + (menu->var->sound * 150), 125));
	sfRenderWindow_drawSprite(win, menu->sprite->little_border, NULL);
}

void settings_menu(menu_t *menu, sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(win);
	sfTime time = sfClock_getElapsedTime(menu->frame_rate);

	if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
		sfClock_restart(menu->frame_rate);
		sfRenderWindow_clear(win, sfBlack);
		sfRenderWindow_drawSprite(win, menu->sprite->set_menu, NULL);
		sfRenderWindow_drawText(win, menu->text->int_volume, NULL);
		sfRenderWindow_drawText(win, menu->text->ten, NULL);
		sfRenderWindow_drawText(win, menu->text->volume, NULL);
		sfRenderWindow_drawText(win, menu->text->a_font1, NULL);
		sfRenderWindow_drawText(win, menu->text->a_font2, NULL);
		display_settings_selection(menu, win);
		sfSprite_setPosition(menu->sprite->mouse, pos);
		sfRenderWindow_drawSprite(win, menu->sprite->mouse, NULL);
		sfRenderWindow_display(win);
	}
	while (sfRenderWindow_pollEvent(win, &(menu->event)))
		analyze_event_settings(menu, menu->event, win);
}
