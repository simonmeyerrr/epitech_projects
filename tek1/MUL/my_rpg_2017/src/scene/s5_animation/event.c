/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

void event_animation(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape))
		global->var->button[BUT_STATUS] = 4;
	if (event_click(global) == 0)
		return;
	if (event.mouseButton.x >= 1400 && event.mouseButton.x <= 1500 &&
	event.mouseButton.y >= 800 && event.mouseButton.y <= 830)
		global->var->button[BUT_STATUS] = 1;
}
