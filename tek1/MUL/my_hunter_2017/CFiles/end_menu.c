/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** end menu
*/

#include "all.h"

static void manage_mouse_click(myObjects_t* obj, sfMouseButtonEvent event)
{
	if (event.x > 590 && event.x < 996 && event.y < 840 && event.y > 724)
		prepare_game(obj);
	if (event.x > 1029 && event.x < 1390 && event.y < 840 && event.y > 724)
		sfRenderWindow_close(obj->window);
}

static void analyze_events(myObjects_t* obj, sfEvent event)
{
	if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
	(event.key).code == sfKeyEscape))
		sfRenderWindow_close(obj->window);
	if (event.type == sfEvtMouseButtonPressed)
		manage_mouse_click(obj, event.mouseButton);
}

static void disp_stat2(sfRenderWindow* window, myText_t* text)
{
	sfRenderWindow_drawText(window, text->bird_Y_shot, NULL);
	sfRenderWindow_drawText(window, text->bird_B_fail, NULL);
	sfRenderWindow_drawText(window, text->bird_Y_fail, NULL);
	sfRenderWindow_drawText(window, text->int_shot_success, NULL);
	sfRenderWindow_drawText(window, text->int_shot_double, NULL);
	sfRenderWindow_drawText(window, text->int_shot_failed, NULL);
	sfRenderWindow_drawText(window, text->int_bird_B_shot, NULL);
	sfRenderWindow_drawText(window, text->int_bird_Y_shot, NULL);
	sfRenderWindow_drawText(window, text->int_bird_B_fail, NULL);
	sfRenderWindow_drawText(window, text->int_bird_Y_fail, NULL);
}

static void disp_stat(sfRenderWindow* window, myText_t* text, myObjects_t* obj)
{
	sfRenderWindow_drawText(window, text->restart, NULL);
	sfRenderWindow_drawText(window, text->end_exit, NULL);
	sfRenderWindow_drawText(window, text->game_over, NULL);
	if (obj->var->new_highscore == 1) {
		sfRenderWindow_drawText(window, text->new_high_score, NULL);
		sfRenderWindow_drawText(window, text->int_new_high_score, NULL);
	} else {
		sfRenderWindow_drawText(window, text->end_score, NULL);
		sfRenderWindow_drawText(window, text->end_int_score, NULL);
		sfRenderWindow_drawText(window, text->int_high_score, NULL);
	}
	sfRenderWindow_drawText(window, text->end_stage, NULL);
	sfRenderWindow_drawText(window, text->end_int_stage, NULL);
	sfRenderWindow_drawText(window, text->precision, NULL);
	sfRenderWindow_drawText(window, text->int_precision, NULL);
	sfRenderWindow_drawText(window, text->shot_success, NULL);
	sfRenderWindow_drawText(window, text->shot_double, NULL);
	sfRenderWindow_drawText(window, text->shot_failed, NULL);
	sfRenderWindow_drawText(window, text->bird_B_shot, NULL);
	disp_stat2(window, text);
}

void end_menu(myObjects_t* obj)
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
		sfRenderWindow_drawSprite(obj->window, obj->sprite->end_menu,
			NULL);
		disp_stat(obj->window, obj->text, obj);
		sfSprite_setPosition(obj->sprite->mouse,
			pos_mouse(obj->window));
		sfRenderWindow_drawSprite(obj->window, obj->sprite->mouse,
			NULL);
		sfRenderWindow_display(obj->window);
	}
}
