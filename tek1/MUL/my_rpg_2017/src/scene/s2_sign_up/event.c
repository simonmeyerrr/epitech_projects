/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

static void event_key_sign_up(my_var_t *var, sfKeyCode key)
{
	if (key == sfKeyTab) {
		var->con_var[CON_FIELD] = var->con_var[CON_FIELD] + 1;
		if (var->con_var[CON_FIELD] >= 3)
			var->con_var[CON_FIELD] = 0;
	}
	if (key == sfKeyEscape || key == sfKeyReturn) {
		var->button[BUT_PRESSED] = (key == sfKeyReturn) ? (0) : (1);
		var->button[BUT_STATUS] = 5;
	}
	if (var->con_var[CON_FIELD] == 0)
		input_to_str(key, var->con_field[CON_USERNAME]);
	else if (var->con_var[CON_FIELD] == 1)
		input_to_str(key, var->con_field[CON_PASSWORD1]);
	else
		input_to_str(key, var->con_field[CON_PASSWORD2]);
}

void event_sign_up(global_t *global, sfEvent event)
{
	event_close(global);
	if (event.type == sfEvtKeyPressed)
		event_key_sign_up(global->var, event.key.code);
	if (event_click(global) != 1)
		return;
	for (int i = 0 ; i < 3 && global->var->button[BUT_STATUS] == 0 ; i++) {
		if (i != 2 && mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(i * 450 + 400, 750, 350, 100))) {
			global->var->button[BUT_STATUS] = 1;
			global->var->button[BUT_PRESSED] = i;
		}
		if (mouse_on_button(VEC(event.mouseButton.x,
		event.mouseButton.y), TAB4(400, i * 150 + 250, 800, 100)))
			global->var->con_var[CON_FIELD] = i;
	}
}
