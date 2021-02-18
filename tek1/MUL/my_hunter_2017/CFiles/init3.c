/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** init part 3
*/

#include "all.h"

void my_init_clock(myObjects_t* obj)
{
	obj->clock = malloc(sizeof(*(obj->clock)));
	obj->clock->frame_rate = sfClock_create();
	obj->clock->pause = sfClock_create();
	obj->clock->game = sfClock_create();
	obj->clock->shot = sfClock_create();
}

void my_init_music(myMusic_t* music, int* error)
{
	music->menu = sfMusic_createFromFile(MUSIC_MENU);
	music->game = sfMusic_createFromFile(MUSIC_GAME);
	music->shotgun = sfMusic_createFromFile(SOUND_SHOTGUN);
	music->shot_blue = sfMusic_createFromFile(SOUND_SHOT_BLUE);
	music->shot_yellow = sfMusic_createFromFile(SOUND_SHOT_YELLOW);
	music->double_shot = sfMusic_createFromFile(SOUND_DOUBLE_SHOT);
	music->lose_life = sfMusic_createFromFile(SOUND_LOSE_LIFE);
	music->game_over = sfMusic_createFromFile(SOUND_GAME_OVER);
	if (music->menu == NULL || music->game == NULL || music->shotgun == NULL
	|| music->shot_blue == NULL || music->shot_yellow == NULL ||
	music->double_shot == NULL || music->lose_life == NULL ||
	music->game_over == NULL) {
		my_putstr("Error while loading musics.");
		*error = 1;
		return;
	}
	sfMusic_setLoop(music->menu, sfTrue);
	sfMusic_setLoop(music->game, sfTrue);
	sfMusic_play(music->menu);
}
