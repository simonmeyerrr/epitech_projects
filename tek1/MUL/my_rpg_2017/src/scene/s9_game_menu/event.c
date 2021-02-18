/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

void event_game_menu(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape)) {
		global->var->button[BUT_STATUS] = 1;
		global->var->button[BUT_PRESSED] = 0;
	}
	if (event_click(global) != 1)
		return;
	for (int i = 0 ; i < 4 && global->var->button[BUT_STATUS] == 0 ; i++) {
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(550, i * 150 + 250, 500, 100))) {
			global->var->button[BUT_STATUS] = 1;
			global->var->button[BUT_PRESSED] = i;
		}
	}
}
