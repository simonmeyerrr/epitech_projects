/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

void update_main_menu(global_t *global, int *error)
{
	if (update_button(global)) {
		global->var->con_var[CON_FIELD] = 0;
		memset(global->var->con_field[CON_PASSWORD1], '\0', 19);
		switch (global->var->button[BUT_PRESSED]) {
			case 0:
				global->scene = SCENE_LOG_IN;
				break;
			case 1:
				global->scene = SCENE_SIGN_UP;
				break;
			case 2:
				global->scene = SCENE_SETTINGS;
				break;
			case 3:
				sfRenderWindow_close(global->win);
				break;
		}
	}
}
