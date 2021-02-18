/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** start menu
*/

#include "all.h"

static void manage_mouse_click(myObjects_t* obj, sfMouseButtonEvent event)
{
	if (event.x > 590 && event.x < 1390 && event.y < 808 && event.y > 658)
		sfRenderWindow_close(obj->window);
	if (event.x > 590 && event.x < 1390 && event.y < 615 && event.y > 464)
		prepare_game(obj);
}

static void analyze_events(myObjects_t* obj, sfEvent event)
{
	if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
	(event.key).code == sfKeyEscape))
		sfRenderWindow_close(obj->window);
	if (event.type == sfEvtMouseButtonPressed)
		manage_mouse_click(obj, event.mouseButton);
}

void start_menu(myObjects_t* obj)
{
	if ((sfClock_getElapsedTime(obj->clock->frame_rate)).microseconds /
	1000000.0 > 1.0 / 30.0) {
		sfClock_restart(obj->clock->frame_rate);
		while (sfRenderWindow_pollEvent(obj->window, &(obj->event)))
			analyze_events(obj, obj->event);
		sfRenderWindow_clear(obj->window, sfBlack);
		pos_mouse(obj->window);
		sfRenderWindow_drawSprite(obj->window, obj->sprite->background,
			NULL);
		sfRenderWindow_drawSprite(obj->window, obj->sprite->begin_menu,
			NULL);
		sfRenderWindow_drawText(obj->window, obj->text->title, NULL);
		sfRenderWindow_drawText(obj->window, obj->text->start, NULL);
		sfRenderWindow_drawText(obj->window, obj->text->exit, NULL);
		sfSprite_setPosition(obj->sprite->mouse,
			pos_mouse(obj->window));
		sfRenderWindow_drawSprite(obj->window, obj->sprite->mouse,
			NULL);
		sfRenderWindow_display(obj->window);
	}
}
