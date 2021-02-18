/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

void event_fight(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape)) {
		global->var->button[BUT_PRESSED] = 0;
		global->var->button[BUT_STATUS] = 5;
	}
	if (event_click(global) != 1)
		return;
	for (int i = 0 ; global->game->fight->fight_anim == 0 &&
	global->game->fight->fight_status == 0 && i < 2 ; i++)
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), create_tab4(i * 700 + 200, 720, 500,
		100))) {
			global->var->button[BUT_PRESSED] = i + 1;
			global->var->button[BUT_STATUS] = 5;
		}
}
