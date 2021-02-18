/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

void update_game_menu(global_t *global, int *error)
{
	if (update_button(global)) {
		switch (global->var->button[BUT_PRESSED]) {
		case 0:
			global->scene = (global->game->fight) ?
			(SCENE_FIGHT) : (SCENE_GAME);
			break;
		case 1:
			global->scene = SCENE_HELP;
			break;
		case 2:
			global->scene = SCENE_SETTINGS;
			break;
		case 3:
			free_game(global);
			sfMusic_stop(global->music->music[MUSIC_FLAMINGO]);
			sfMusic_play(global->music->music[MUSIC_THEME]);
			global->scene = SCENE_MAIN_MENU;
			break;
		}
	}
}
