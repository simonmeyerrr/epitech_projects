/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

void event_help(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape) || event_key(global, sfKeySpace))
		global->scene = SCENE_GAME_MENU;
	if (event_click(global) != 1)
		return;
	global->scene = SCENE_GAME_MENU;
}
