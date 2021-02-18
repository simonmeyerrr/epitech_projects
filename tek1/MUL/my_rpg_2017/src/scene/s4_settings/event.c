/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

static void event_sound_settings(global_t *global, sfEvent event)
{
	sfVector2f *pos_vol = get_vol_pos(global);

	for (int i = 0 ; i < 3 && global->var->button[BUT_STATUS] == 0 ; i++)
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(pos_vol[i].x, pos_vol[i].y,
		66, 68))) {
			global->var->button[BUT_STATUS] = 5;
			global->var->button[BUT_PRESSED] = i + 2;
			global->var->button[BUT_RELEASED] = 1;
		}
	my_free(pos_vol);
}

static void event_display_settings(global_t *global, sfEvent event)
{
	for (int i = 0 ; i < 2 ; i++)
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(750, i * 100 + 445, 133, 30))) {
			global->var->button[BUT_STATUS] = 1;
			global->var->button[BUT_PRESSED] = i + 5;
		}
}

void event_settings(global_t *global, sfEvent event)
{
	event_close(global);
	if (event_key(global, sfKeyEscape)) {
		global->var->button[BUT_PRESSED] = 1;
		global->var->button[BUT_RELEASED] = 0;
		global->var->button[BUT_STATUS] = 5;
	}
	if (event.type == sfEvtMouseButtonReleased)
		global->var->button[BUT_RELEASED] = 0;
	if (!event_click(global))
		return;
	if (global->var->button[BUT_RELEASED])
		return;
	for (int i = 0 ; i < 2 && global->var->button[BUT_STATUS] == 0 ; i++)
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(i * 450 + 400, 700, 350, 100))) {
			global->var->button[BUT_STATUS] = 1;
			global->var->button[BUT_PRESSED] = i;
		}
	event_sound_settings(global, event);
	event_display_settings(global, event);
}
