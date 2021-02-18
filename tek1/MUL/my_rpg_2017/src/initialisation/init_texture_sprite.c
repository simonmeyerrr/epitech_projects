/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** init_texture_sprite.c
*/

#include "all.h"

static void prepare_sprite3(my_sprite_t *sprite, my_texture_t *text, int *error)
{
	for (int i = 0 ; i < NB_WORLD ; i++) {
		sprite->world[i] = sfSprite_create();
		if (!sprite->world[i])
			*error = 1;
		else if (text->world[i])
			sfSprite_setTexture(sprite->world[i],
			text->world[i], sfTrue);
	}
	for (int i = 0 ; i < NB_ANIMATION ; i++) {
		sprite->animation[i] = sfSprite_create();
		if (!sprite->animation[i])
			*error = 1;
		else if (text->animation[i])
			sfSprite_setTexture(sprite->animation[i],
			text->animation[i], sfTrue);
	}
}

static void prepare_sprite2(my_sprite_t *sprite, my_texture_t *text, int *error)
{
	for (int i = 0 ; i < NB_BUTTON ; i++) {
		sprite->button[i] = sfSprite_create();
		if (!sprite->button[i])
			*error = 1;
		else if (text->button[i])
			sfSprite_setTexture(sprite->button[i],
			text->button[i], sfTrue);
	}
	for (int i = 0 ; i < NB_IMAGE ; i++) {
		sprite->image[i] = sfSprite_create();
		if (!sprite->image[i])
			*error = 1;
		else if (text->image[i])
			sfSprite_setTexture(sprite->image[i],
			text->image[i], sfTrue);
	}
}

my_sprite_t *prepare_sprite(my_texture_t *text, int *error)
{
	my_sprite_t *sprite = malloc(sizeof(my_sprite_t));

	if (verif_malloc(sprite, error) != 0)
		return (NULL);
	for (int i = 0 ; i < NB_BACKGROUND ; i++) {
		sprite->background[i] = sfSprite_create();
		if (!sprite->background[i])
			*error = 1;
		else if (text->background[i])
			sfSprite_setTexture(sprite->background[i],
			text->background[i], sfTrue);
	}
	prepare_sprite2(sprite, text, error);
	prepare_sprite3(sprite, text, error);
	return (sprite);
}

static void prepare_texture2(my_texture_t *text, int *error)
{
	char *tab3[NB_IMAGE] = PATH_IMAGE;
	char *tab4[NB_WORLD] = PATH_WORLD;
	char *tab5[NB_ANIMATION] = PATH_ANIMATION;

	for (int i = 0 ; i < NB_IMAGE ; i++) {
		text->image[i] = sfTexture_createFromFile(tab3[i], NULL);
		if (!text->image[i])
			*error = 1;
	}
	for (int i = 0 ; i < NB_WORLD ; i++) {
		text->world[i] = sfTexture_createFromFile(tab4[i], NULL);
		if (!text->world[i])
			*error = 1;
	}
	for (int i = 0 ; i < NB_ANIMATION ; i++) {
		text->animation[i] = sfTexture_createFromFile(tab5[i], NULL);
		if (!text->animation[i])
			*error = 1;
	}
}

my_texture_t *prepare_texture(int *error)
{
	my_texture_t *text = malloc(sizeof(my_texture_t));
	char *tab1[NB_BACKGROUND] = PATH_BACKGROUND;
	char *tab2[NB_BUTTON] = PATH_BUTTON;

	if (verif_malloc(text, error) != 0)
		return (NULL);
	for (int i = 0 ; i < NB_BACKGROUND ; i++) {
		text->background[i] = sfTexture_createFromFile(tab1[i], NULL);
		if (!text->background[i])
			*error = 1;
	}
	for (int i = 0 ; i < NB_BUTTON ; i++) {
		text->button[i] = sfTexture_createFromFile(tab2[i], NULL);
		if (!text->button[i])
			*error = 1;
	}
	prepare_texture2(text, error);
	return (text);
}
