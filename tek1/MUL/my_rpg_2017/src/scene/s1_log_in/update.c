/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

void update_log_in(global_t *global, int *error)
{
	if (update_button(global)) {
		global->var->con_var[CON_ERROR_STAT] = 0;
		switch (global->var->button[BUT_PRESSED]) {
			case 1:
				global->scene = SCENE_MAIN_MENU;
				break;
			case 0:
				user_connection(global, error, global->var);
				break;
		}
	}
	update_con_error(global);
}
