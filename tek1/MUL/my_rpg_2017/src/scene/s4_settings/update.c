/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

static void change_volume(global_t *global, int *vol_diff)
{
	if (global->var->button[BUT_PRESSED] == 2)
		global->var->setting[SET_VOL_GENERAL] = vol_diff[0];
	if (global->var->button[BUT_PRESSED] == 3)
		global->var->setting[SET_VOL_MUSIC] = vol_diff[1];
	if (global->var->button[BUT_PRESSED] == 4)
		global->var->setting[SET_VOL_SOUND] = vol_diff[2];
	global->var->button[BUT_STATUS] = 5;
}

static void move_cursor(global_t *global)
{
	sfVector2f mouse_pos = get_mouse_pos(global);
	static float *pos_diff = NULL;
	int *vol_diff;

	if (!global->var->button[BUT_RELEASED]) {
		if (pos_diff)
			my_free(pos_diff);
		return;
	}
	if (global->var->button[BUT_RELEASED] == 1) {
		global->var->button[BUT_RELEASED] = 2;
		pos_diff = get_diff(global, mouse_pos);
	}
	vol_diff = get_vol(mouse_pos, pos_diff);
	change_volume(global, vol_diff);
	my_free(vol_diff);
}

static void use_button_setting(global_t *global)
{
	switch (global->var->button[BUT_PRESSED]) {
	case 0:
		set_defaut(global);
		break;
	case 2:
	case 3:
	case 4:
		move_cursor(global);
		break;
	case 5:
		global->var->setting[SET_VSYNC] =
		(!global->var->setting[SET_VSYNC] ? 1 : 0);
		break;
	case 6:
		global->var->fps =
		(global->var->fps == 30.0 ? 60.0 : 30.0);
		break;
	}
}

void update_settings(global_t *global, int *error)
{
	if (update_button(global)) {
		if (global->var->button[BUT_PRESSED] == 1)
			global->scene = (global->game) ? (SCENE_GAME_MENU) :
			(SCENE_MAIN_MENU);
		else {
			use_button_setting(global);
			apply_settings(global);
		}
	}
}
