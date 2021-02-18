/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** bird
*/

#include "all.h"

static void create_bird(myObjects_t* obj)
{
	int color1 = rand() % 5;
	int color2 = rand() % 5;
	sfVector2f pos1 = {-120, (rand() % 650 + 50)};
	sfVector2f pos2 = {2040, (rand() % 650 + 50)};

	if (obj->var->birdgoright == 0) {
		obj->var->birdgoright = 1;
		if (color1 == 1 && obj->stat->stage >= 3)
			obj->var->birdgoright = 2;
		sfSprite_setPosition(obj->sprite->bird_RB, pos1);
		sfSprite_setPosition(obj->sprite->bird_RY, pos1);
	}
	if (obj->var->birdgoleft == 0) {
		obj->var->birdgoleft = 1;
		if (color2 == 1 && obj->stat->stage >= 3)
			obj->var->birdgoleft = 2;
		sfSprite_setPosition(obj->sprite->bird_LB, pos2);
		sfSprite_setPosition(obj->sprite->bird_LY, pos2);
	}
}

static void out_of_map(myObjects_t* obj)
{
	if (sfSprite_getPosition(obj->sprite->bird_RB).x > 2040) {
		if (obj->var->birdgoright == 1) {
			obj->stat->life--;
			obj->stat->fail_blue++;
			sfMusic_play(obj->music->lose_life);
		} else if (obj->var->birdgoright == 2)
			obj->stat->fail_yellow++;
		obj->var->birdgoright = 0;
	}
	if (sfSprite_getPosition(obj->sprite->bird_LB).x < -120) {
		if (obj->var->birdgoleft == 1) {
			obj->stat->life--;
			obj->stat->fail_blue++;
			sfMusic_play(obj->music->lose_life);
		} else if (obj->var->birdgoleft == 2)
			obj->stat->fail_yellow++;
		obj->var->birdgoleft = 0;
	}
}

static void random_move_right(myObjects_t* obj)
{
	sfVector2f move = {0, 0};
	sfVector2f pos = sfSprite_getPosition(obj->sprite->bird_RB);
	float spe = 1;

	if (obj->var->image_move_rect % 3 == 0) {
		obj->var->randomRX = rand() % 10;
		obj->var->randomRY = rand() % 10;
	}
	if (obj->var->birdgoright == 2)
		spe = 1.3;
	move.x = (obj->var->randomRX + 5) * obj->var->difficulty * spe;
	if ((pos.y > 50 || obj->var->randomRY > 5) && (pos.y < 700 ||
	obj->var->randomRY < 5))
		move.y = (obj->var->randomRY - 5) * obj->var->difficulty * spe;
	sfSprite_move(obj->sprite->bird_RB, move);
	sfSprite_move(obj->sprite->bird_RY, move);
}

static void random_move_left(myObjects_t* obj)
{
	sfVector2f move = {0, 0};
	sfVector2f pos = sfSprite_getPosition(obj->sprite->bird_LB);
	float spe = 1;

	if (obj->var->image_move_rect % 3 == 0) {
		obj->var->randomLX = rand() % 10;
		obj->var->randomLY = rand() % 10;
	}
	if (obj->var->birdgoleft == 2)
		spe = 1.3;
	move.x = -(obj->var->randomLX + 5) * obj->var->difficulty * spe;
	if ((pos.y > 50 || obj->var->randomLY > 5) && (pos.y < 700 ||
	obj->var->randomLY < 5))
		move.y = (obj->var->randomLY - 5) * obj->var->difficulty * spe;
	sfSprite_move(obj->sprite->bird_LB, move);
	sfSprite_move(obj->sprite->bird_LY, move);
}

void disp_birds(myObjects_t* obj)
{
	out_of_map(obj);
	create_bird(obj);
	random_move_right(obj);
	random_move_left(obj);
	bird_rect(obj);
	obj->var->image_move_rect++;
	if (obj->var->birdgoright == 1)
		sfRenderWindow_drawSprite(obj->window, obj->sprite->bird_RB,
			NULL);
	else if (obj->var->birdgoright == 2)
		sfRenderWindow_drawSprite(obj->window, obj->sprite->bird_RY,
			NULL);
	if (obj->var->birdgoleft == 1)
		sfRenderWindow_drawSprite(obj->window, obj->sprite->bird_LB,
			NULL);
	else if (obj->var->birdgoleft == 2)
		sfRenderWindow_drawSprite(obj->window, obj->sprite->bird_LY,
			NULL);
}
