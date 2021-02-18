/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** update.c
*/

#include "all.h"

void update_animation(global_t *global, int *error)
{
	char **tab;

	global->var->animation += 1;
	if (update_button(global) || global->var->animation > 4400) {
		global->var->animation = 0;
		sfMusic_stop(global->music->music[MUSIC_ANIMATION]);
		sfMusic_play(global->music->music[MUSIC_FLAMINGO]);
		global->var->button[BUT_STATUS] = 0;
		global->scene = SCENE_GAME;
		tab = malloc(sizeof(char*) * 2);
		tab[0] = my_strdup("C'est bizarre, j\'ai vraiment l\'impression"
		" que je devrais\nattraper ce baton isole et excessivement att"
		"irant\nqui va probablement declancher un evenement\ncle de cet"
		"te histoire.");
		tab[1] = NULL;
		global->game->text = create_text_box(tab, nothing);
	}
}
