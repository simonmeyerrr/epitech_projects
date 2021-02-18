/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** hit_box
*/

#include "all.h"

static int hit_box_left(myObjects_t* obj, int x, int y)
{
	sfVector2f p = sfSprite_getPosition(obj->sprite->bird_LB);

	if (obj->var->birdgoleft == 0)
		return (0);
	if (x >= p.x && x <= p.x + 120 && y >= p.y && y <= p.y + 80) {
		if (obj->var->birdgoleft == 1) {
			sfMusic_play(obj->music->shot_blue);
			obj->stat->score += 10;
			obj->stat->shot_blue++;
		} else {
			sfMusic_play(obj->music->shot_yellow);
			obj->stat->score += 30;
			obj->stat->shot_yellow++;
			obj->stat->life++;
		}
		obj->var->birdgoleft = 0;
		return (1);
	}
	return (0);
}

static int hit_box_right(myObjects_t* obj, int x, int y)
{
	sfVector2f p = sfSprite_getPosition(obj->sprite->bird_RB);

	if (obj->var->birdgoright == 0)
		return (0);
	if (x >= p.x && x <= p.x + 120 && y >= p.y && y <= p.y + 80) {
		if (obj->var->birdgoright == 1) {
			sfMusic_play(obj->music->shot_blue);
			obj->stat->score += 10;
			obj->stat->shot_blue++;
		} else {
			sfMusic_play(obj->music->shot_yellow);
			obj->stat->score += 30;
			obj->stat->shot_yellow++;
			obj->stat->life++;
		}
		obj->var->birdgoright = 0;
		return (1);
	}
	return (0);
}

void manage_hit_box(myObjects_t* obj, sfMouseButtonEvent event)
{
	int success = hit_box_right(obj, event.x, event.y);

	sfClock_restart(obj->clock->shot);
	sfMusic_play(obj->music->shotgun);
	obj->stat->shot = obj->stat->shot + 1;
	success += hit_box_left(obj, event.x, event.y);
	if (success == 2) {
		sfMusic_play(obj->music->double_shot);
		obj->stat->double_shot++;
		obj->stat->score += 50;
		obj->stat->shot_succes = obj->stat->shot_succes + 1;
	} else if (success == 1) {
		obj->stat->shot_succes = obj->stat->shot_succes + 1;
	} else
		obj->stat->shot_failed++;
}
