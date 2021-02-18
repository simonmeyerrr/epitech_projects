/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** global_update.c
*/

#include "all.h"

void apply_settings(global_t *global)
{
	int fd = open("asset/.settings", O_CREAT | O_TRUNC | O_WRONLY);

	for (int i = 0 ; i < NB_MUSIC ; i++)
		sfMusic_setVolume(global->music->music[i],
		global->var->setting[SET_VOL_GENERAL] *
		global->var->setting[SET_VOL_MUSIC] / 100);
	for (int i = 0 ; i < NB_SOUND ; i++)
		sfMusic_setVolume(global->music->sound[i],
		global->var->setting[SET_VOL_GENERAL] *
		global->var->setting[SET_VOL_SOUND] / 100);
	sfRenderWindow_setVerticalSyncEnabled(global->win,
	(global->var->setting[SET_VSYNC] == 1) ? (sfTrue) : (sfFalse));
	if (fd >= 0) {
		write(fd, &(global->var->setting[SET_VOL_GENERAL]), 1);
		write(fd, &(global->var->setting[SET_VOL_MUSIC]), 1);
		write(fd, &(global->var->setting[SET_VOL_SOUND]), 1);
		write(fd, &(global->var->setting[SET_VSYNC]), 1);
		write(fd, &(global->var->fps), sizeof(float));
		close(fd);
	}
}

int update_button(global_t *global)
{
	if (global->var->button[BUT_STATUS] > 0)
		global->var->button[BUT_STATUS]++;
	if (global->var->button[BUT_STATUS] >= 5) {
		global->var->button[BUT_STATUS] = 0;
		return (1);
	}
	return (0);
}

void update_con_error(global_t *global)
{
	if (global->var->con_var[CON_ERROR_STAT] > 0)
		global->var->con_var[CON_ERROR_STAT]++;
	if (global->var->con_var[CON_ERROR_STAT] > 150)
		global->var->con_var[CON_ERROR_STAT] = 0;
}
