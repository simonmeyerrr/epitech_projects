/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** game
*/

#include "all.h"

static void disp_text(myObjects_t* obj)
{
	char* str1 = five_to_str(obj->stat->score);
	char* str2 = two_to_str(obj->stat->life);
	char* str3 = two_to_str(obj->stat->stage);

	sfText_setString(obj->text->int_score, str1);
	sfText_setString(obj->text->int_life, str2);
	sfText_setString(obj->text->int_stage, str3);
	sfRenderWindow_drawText(obj->window, obj->text->score, NULL);
	sfRenderWindow_drawText(obj->window, obj->text->life, NULL);
	sfRenderWindow_drawText(obj->window, obj->text->stage, NULL);
	sfRenderWindow_drawText(obj->window, obj->text->int_score, NULL);
	sfRenderWindow_drawText(obj->window, obj->text->int_life, NULL);
	sfRenderWindow_drawText(obj->window, obj->text->int_stage, NULL);
	free(str1);
	free(str2);
	free(str3);
}

static void life_difficulty(myObjects_t* obj)
{
	sfTime time = sfClock_getElapsedTime(obj->clock->game);
	char* str;

	if (obj->stat->life <= 0) {
		prepare_end(obj, obj->text, obj->stat);
		return;
	}
	if ((time.microseconds / 1000000.0) - obj->var->pause_time >
	obj->stat->stage * 10 && obj->var->pause == 0) {
		obj->stat->stage++;
		obj->var->difficulty = obj->var->difficulty * 1.3;
	}
}

static void manage_pause(myObjects_t* obj)
{
	if (obj->var->pause == 0) {
		sfClock_restart(obj->clock->pause);
		obj->var->pause = 1;
	} else {
		obj->clock->time = sfClock_getElapsedTime(obj->clock->pause);
		obj->var->pause_time += obj->clock->time.microseconds /
		1000000.0;
		obj->var->pause = 0;
	}
}

static void analyze_events(myObjects_t* obj, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(obj->window);
	if (event.type == sfEvtKeyPressed && (event.key).code == sfKeyEscape)
		prepare_end(obj, obj->text, obj->stat);
	if (event.type == sfEvtKeyPressed && (event.key).code == sfKeySpace)
		manage_pause(obj);
	if (event.type == sfEvtMouseButtonPressed &&
	sfClock_getElapsedTime(obj->clock->shot).microseconds / 1000000.0 > 1.0)
		manage_hit_box(obj, event.mouseButton);
}

void game_screen(myObjects_t* obj, sfRenderWindow* window, mySprite_t* sprite)
{
	if ((sfClock_getElapsedTime(obj->clock->frame_rate)).microseconds /
	1000000.0 > 1.0 / 30.0) {
		sfClock_restart(obj->clock->frame_rate);
		while (sfRenderWindow_pollEvent(window, &(obj->event)))
			analyze_events(obj, obj->event);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite->background, NULL);
		disp_text(obj);
		if (obj->var->pause == 0)
			disp_birds(obj);
		else
			sfRenderWindow_drawText(window, obj->text->pause, NULL);
		sfSprite_setPosition(sprite->crosshair, pos_mouse(window));
		sfRenderWindow_drawSprite(window, sprite->crosshair, NULL);
		sfRenderWindow_display(window);
		life_difficulty(obj);
	}
}
