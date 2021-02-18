/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** utils_setting.c
*/

#include "all.h"

sfVector2f *get_vol_pos(global_t *global)
{
	sfVector2f *pos_vol = malloc(sizeof(sfVector2f) * 3);

	pos_vol[0].x = 767 + (global->var->setting[SET_VOL_GENERAL] * 5);
	pos_vol[1].x = 767 + (global->var->setting[SET_VOL_MUSIC] * 5);
	pos_vol[2].x = 767 + (global->var->setting[SET_VOL_SOUND] * 5);
	pos_vol[0].y = 115;
	pos_vol[1].y = 215;
	pos_vol[2].y = 315;
	return (pos_vol);
}

float *get_diff(global_t *global, sfVector2f mouse_pos)
{
	float *pos_diff = malloc(sizeof(int) * 3);

	pos_diff[0] = mouse_pos.x -
	(global->var->setting[SET_VOL_GENERAL] * 5 + 767);
	pos_diff[1] = mouse_pos.x -
	(global->var->setting[SET_VOL_MUSIC] * 5 + 767);
	pos_diff[2] = mouse_pos.x -
	(global->var->setting[SET_VOL_SOUND] * 5 + 767);
	return (pos_diff);
}

int *get_vol(sfVector2f mouse_pos, float *pos_diff)
{
	int *vol_diff = malloc(sizeof(int) * 3);

	for (int i = 0 ; i < 3 ; i++) {
		vol_diff[i] = (mouse_pos.x - pos_diff[i] - 767) / 5;
		if (vol_diff[i] > 100)
			vol_diff[i] = 100;
		if (vol_diff[i] < 0)
			vol_diff[i] = 0;
	}
	return (vol_diff);
}

void set_defaut(global_t *global)
{
	global->var->setting[SET_VOL_GENERAL] = 100;
	global->var->setting[SET_VOL_MUSIC] = 100;
	global->var->setting[SET_VOL_SOUND] = 100;
	global->var->setting[SET_VSYNC] = 0;
	global->var->fps = 30.0;
}
