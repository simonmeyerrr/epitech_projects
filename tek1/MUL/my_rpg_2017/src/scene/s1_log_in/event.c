/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

static void event_key_log_in(my_var_t *var, sfKeyCode key)
{
	if (key == sfKeyTab)
		var->con_var[CON_FIELD] = (var->con_var[CON_FIELD]) ? (0) : (1);
	if (key == sfKeyEscape || key == sfKeyReturn) {
		var->button[BUT_PRESSED] = (key == sfKeyReturn) ? (0) : (1);
		var->button[BUT_STATUS] = 5;
	}
	input_to_str(key, var->con_var[CON_FIELD] ?
	(var->con_field[CON_PASSWORD1]) : (var->con_field[CON_USERNAME]));
}

void event_log_in(global_t *global, sfEvent event)
{
	event_close(global);
	if (event.type == sfEvtKeyPressed)
		event_key_log_in(global->var, event.key.code);
	if (event_click(global) != 1)
		return;
	for (int i = 0 ; i < 2 && global->var->button[BUT_STATUS] == 0 ; i++) {
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(i * 450 + 400, 700, 350, 100))) {
			global->var->button[BUT_STATUS] = 1;
			global->var->button[BUT_PRESSED] = i;
		}
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(400, i * 200 + 300, 800, 100)))
			global->var->con_var[CON_FIELD] = i;
	}
}
