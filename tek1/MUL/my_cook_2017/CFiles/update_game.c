/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** update_game.c
*/

#include "all.h"

static void new_recipe(game_t *game, my_obj_t *obj)
{
	char *tab1[14] = {COOK1, COOK2, COOK3, COOK4, COOK5, COOK6, COOK7,
	COOK8, COOK9, COOK10, COOK11, COOK12, COOK13, COOK14};
	char *tab2[14] = {RECIPE1, RECIPE2, RECIPE3, RECIPE4, RECIPE5, RECIPE6,
	RECIPE7, RECIPE8, RECIPE9, RECIPE10, RECIPE11, RECIPE12, RECIPE13,
	RECIPE14};
	char *tab3[14] = {NEED1, NEED2, NEED3, NEED4, NEED5, NEED6, NEED7,
	NEED8, NEED9, NEED10, NEED11, NEED12, NEED13, NEED14};

	memset(obj->have, '\0', 20);
	obj->status = 1;
	obj->cook = rand() % 14;
	sfText_setString(game->text->cook, tab1[obj->cook]);
	sfText_setString(game->text->recipe, tab2[obj->cook]);
	obj->need = tab3[obj->cook];
	obj->begin = obj->time;
}

static void verif_recipe(game_t *game, my_obj_t *obj)
{
	for (int i = 0 ; obj->have[i] != '\0' ; i++) {
		if (obj->have[i] != obj->need[i])
			obj->status = 2;
	}
}

static void move_rect_animation(game_t *game, my_obj_t *obj)
{
	sfIntRect rect;

	rect.top = 0;
	rect.left = obj->animation * 240;
	if (obj->status == 4)
		rect.left = obj->animation * 250;
	rect.width = 240;
	if (obj->status == 4)
		rect.width = 250;
	rect.height = 260;
	if (obj->status == 3)
		sfSprite_setTextureRect(game->sprite->fail, rect);
	if (obj->status == 4)
		sfSprite_setTextureRect(game->sprite->validation, rect);
}

static void animation_end(game_t *game, my_obj_t *obj)
{
	obj->animation += 1;
	if (obj->status == 2) {
		sfText_setString(game->text->cook, "");
		sfText_setString(game->text->recipe, "");
		if (my_strcmp(obj->need, obj->have) != 0) {
			obj->status = 3;
			obj->time -= 5.0;
		} else {
			obj->status = 4;
			obj->score += 150 / (obj->begin - obj->time);
		}
		obj->animation = 0;
	}
	if (obj->animation >= 23) {
		obj->animation = 0;
		obj->status = 0;
	}
	move_rect_animation(game, obj);
}

void update_game(game_t *game, my_obj_t *obj)
{
	obj->time -= 1.0 / 30.0;
	if (obj->time <= 0.0)
		game->var->menu = 2;
	if (obj->status == 0)
		new_recipe(game, obj);
	else if (obj->status == 1)
		verif_recipe(game, obj);
	else
		animation_end(game, obj);
}
