/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** init part 1
*/

#include "all.h"

void my_init_sprite2(mySprite_t* sprite, myTexture_t* texture, myVar_t* var)
{
	sfSprite_setTexture(sprite->background, texture->background, sfTrue);
	sfSprite_setTexture(sprite->bird_RB, texture->bird_RB, sfTrue);
	sfSprite_setTexture(sprite->bird_RY, texture->bird_RY, sfTrue);
	sfSprite_setTexture(sprite->bird_LB, texture->bird_LB, sfTrue);
	sfSprite_setTexture(sprite->bird_LY, texture->bird_LY, sfTrue);
	sfSprite_setTexture(sprite->crosshair, texture->crosshair, sfTrue);
	sfSprite_setTexture(sprite->mouse, texture->mouse, sfTrue);
	sfSprite_setTexture(sprite->begin_menu, texture->begin_menu, sfTrue);
	sfSprite_setTexture(sprite->end_menu, texture->end_menu, sfTrue);
	sfSprite_setOrigin(sprite->crosshair, var->pos1);
	sfSprite_setScale(sprite->crosshair, var->scale2);
	sfSprite_setScale(sprite->mouse, var->scale2);
	sfSprite_setScale(sprite->bird_RB, var->scale1);
	sfSprite_setScale(sprite->bird_RY, var->scale1);
	sfSprite_setScale(sprite->bird_LB, var->scale1);
	sfSprite_setScale(sprite->bird_LY, var->scale1);
	sfSprite_setPosition(sprite->begin_menu, var->pos2);
	sfSprite_setPosition(sprite->end_menu, var->pos2);
}

void my_init_sprite1(mySprite_t* sprite, int* error)
{
	sprite->background = sfSprite_create();
	sprite->bird_RB = sfSprite_create();
	sprite->bird_RY = sfSprite_create();
	sprite->bird_LB = sfSprite_create();
	sprite->bird_LY = sfSprite_create();
	sprite->crosshair = sfSprite_create();
	sprite->mouse = sfSprite_create();
	sprite->begin_menu = sfSprite_create();
	sprite->end_menu = sfSprite_create();
	if (sprite->background == NULL || sprite->bird_RB == NULL ||
	sprite->bird_RY == NULL || sprite->bird_LB == NULL ||
	sprite->bird_LY == NULL || sprite->crosshair == NULL || sprite->mouse ==
	NULL || sprite->begin_menu == NULL || sprite->end_menu == NULL) {
		my_putstr("Error while loading sprites.");
		*error = 1;
	}
}

void my_init_texture(myTexture_t* texture, int* error)
{
	texture->background = sfTexture_createFromFile(BACKGROUND, NULL);
	texture->bird_RB = sfTexture_createFromFile(BIRD_RB, NULL);
	texture->bird_RY = sfTexture_createFromFile(BIRD_RY, NULL);
	texture->bird_LB = sfTexture_createFromFile(BIRD_LB, NULL);
	texture->bird_LY = sfTexture_createFromFile(BIRD_LY, NULL);
	texture->crosshair = sfTexture_createFromFile(CROSSHAIR, NULL);
	texture->mouse = sfTexture_createFromFile(MOUSE, NULL);
	texture->begin_menu = sfTexture_createFromFile(BEGIN_MENU, NULL);
	texture->end_menu = sfTexture_createFromFile(END_MENU, NULL);
	if (texture->background == NULL || texture->bird_RB == NULL ||
	texture->bird_RY == NULL || texture->bird_LB == NULL ||
	texture->bird_LY == NULL || texture->crosshair == NULL ||
	texture->mouse == NULL || texture->begin_menu == NULL ||
	texture->end_menu == NULL) {
		my_putstr("Error while loading textures.");
		*error = 1;
	}
}

void my_init_var(myObjects_t* obj)
{
	sfVideoMode mode = {1920, 1080, 32};

	obj->var = malloc(sizeof(*obj->var));
	obj->var->mode = mode;
	obj->var->menu = 1;
	obj->var->birdgoright = 0;
	obj->var->birdgoleft = 0;
	obj->var->image_move_rect = 0;
	obj->var->difficulty = 1;
	obj->var->pos1 = create_vector(112, 112);
	obj->var->pos2 = create_vector(590, 240);
	obj->var->scale1 = create_vector(0.2, 0.2);
	obj->var->scale2 = create_vector(0.5, 0.5);
	obj->var->rect.top = 0;
	obj->var->rect.left = 0;
	obj->var->rect.width = 598;
	obj->var->rect.height = 400;
}

void my_init(myObjects_t* obj, int* error)
{
	obj->texture = malloc(sizeof(*(obj->texture)));
	obj->sprite = malloc(sizeof(*(obj->sprite)));
	obj->text = malloc(sizeof(*(obj->text)));
	obj->music = malloc(sizeof(*(obj->music)));
	obj->stat = malloc(sizeof(*(obj->stat)));
	my_init_var(obj);
	my_init_texture(obj->texture, error);
	if (*error == 1)
		return;
	my_init_sprite1(obj->sprite, error);
	if (*error == 1)
		return;
	my_init_sprite2(obj->sprite, obj->texture, obj->var);
	my_init_text(obj->text, obj->text->font, error);
	my_init_clock(obj);
	my_init_music(obj->music, error);
	obj->window = sfRenderWindow_create(obj->var->mode, "My hunter",
	sfClose, NULL);
	sfRenderWindow_setMouseCursorVisible(obj->window, sfFalse);
}
