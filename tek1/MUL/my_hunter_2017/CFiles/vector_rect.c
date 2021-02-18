/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** vector and rect fonc
*/

#include "all.h"

sfVector2f create_vector(float x, float y)
{
	sfVector2f vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

sfVector2f pos_mouse(sfRenderWindow* window)
{
	sfWindow* win = window;
	sfVector2i pos = sfMouse_getPosition(win);
	sfVector2f pos2;

	pos2.x = pos.x;
	pos2.y = pos.y;
	return (pos2);
}

static void move_rect(sfIntRect *rect, int offset, int max_value)
{
	if ((*rect).left == max_value - offset)
		(*rect).left = 0;
	else
		(*rect).left += offset;
}

void bird_rect(myObjects_t* obj)
{
	if (obj->var->image_move_rect % 3 == 0) {
		move_rect(&obj->var->rect, 598, 2392);
	}
	sfSprite_setTextureRect(obj->sprite->bird_LB, obj->var->rect);
	sfSprite_setTextureRect(obj->sprite->bird_LY, obj->var->rect);
	sfSprite_setTextureRect(obj->sprite->bird_RB, obj->var->rect);
	sfSprite_setTextureRect(obj->sprite->bird_RY, obj->var->rect);
}
