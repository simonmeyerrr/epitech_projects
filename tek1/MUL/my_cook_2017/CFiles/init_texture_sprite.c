/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** init_texture_game.c
*/

#include "all.h"

static sfSprite *create_sprite(sfTexture *texture, int *error)
{
	sfSprite *sprite = sfSprite_create();

	if (verif_malloc(sprite, error) != 0)
		return (NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}

static my_sprite_t *init_sprite2(my_sprite_t *sprite, sfTexture ***tab1,
sfSprite ***tab2, int *error)
{
	if (verif_malloc(sprite, error) != 0)
		return (NULL);
	for (int i = 0 ; i < 30 && *error == 0 ; i++)
		*tab2[i] = create_sprite(*tab1[i], error);
	return (sprite);
}

my_sprite_t *init_sprite(my_texture_t *text, int *error)
{
	my_sprite_t *sprite = malloc(sizeof(*sprite));
	sfTexture **tab1[30] = {&text->main_menu, &text->button_off,
	&text->button_on, &text->black, &text->white, &text->mouse,
	&text->easter_egg, &text->easter_egg2, &text->game, &text->bread1,
	&text->bread2, &text->steak, &text->chicken, &text->cheddar,
	&text->emmental, &text->lettuce, &text->bacon, &text->tomatoes,
	&text->ketchup, &text->onions, &text->mayonnaise, &text->pickles,
	&text->bbq, &text->tuto, &text->fail, &text->validation,
	&text->setting, &text->button2, &text->end, &text->pause};
	sfSprite **tab2[30] = {&sprite->main_menu, &sprite->button_off,
	&sprite->button_on, &sprite->black, &sprite->white, &sprite->mouse,
	&sprite->easter_egg, &sprite->easter_egg2, &sprite->game,
	&sprite->bread1, &sprite->bread2, &sprite->steak, &sprite->chicken,
	&sprite->cheddar, &sprite->emmental, &sprite->lettuce, &sprite->bacon,
	&sprite->tomatoes, &sprite->ketchup, &sprite->onions,
	&sprite->mayonnaise, &sprite->pickles, &sprite->bbq, &sprite->tuto,
	&sprite->fail, &sprite->validation, &sprite->setting, &sprite->button2,
	&sprite->end, &sprite->pause};

	return (init_sprite2(sprite, tab1, tab2, error));
}

static my_texture_t *init_texture2(my_texture_t *text, sfTexture ***tab1,
char **tab2, int *error)
{
	if (verif_malloc(text, error) != 0)
		return (NULL);
	for (int i = 0 ; i < 30 && *error == 0; i++) {
		*tab1[i] = sfTexture_createFromFile(tab2[i], NULL);
		verif_malloc(*tab1[i], error);
	}
	return (text);
}

my_texture_t *init_texture(int *error)
{
	my_texture_t *text = malloc(sizeof(*text));
	sfTexture **tab1[30] = {&text->main_menu, &text->button_off,
	&text->button_on, &text->black, &text->white, &text->mouse,
	&text->easter_egg, &text->easter_egg2, &text->game, &text->bread1,
	&text->bread2, &text->steak, &text->chicken, &text->cheddar,
	&text->emmental, &text->lettuce, &text->bacon, &text->tomatoes,
	&text->ketchup, &text->onions, &text->mayonnaise, &text->pickles,
	&text->bbq, &text->tuto, &text->fail, &text->validation,
	&text->setting, &text->button2, &text->end, &text->pause};
	char *tab2[30] = {MAIN_MENU, BUTTON_OFF, BUTTON_ON, BLACK, WHITE, MOUSE,
	EASTER_EGG, EASTER_EGG2, GAME, BREAD1, BREAD2, STEAK, CHICKEN, CHEDDAR,
	EMMENTAL, LETTUCE, BACON, TOMATOES, KETCHUP, ONIONS, MAYONNAISE,
	PICKLES, BBQ, TUTO, FAIL, VALIDATION, SETTING, BUTTON2, END, PAUSE};

	return (init_texture2(text, tab1, tab2, error));
}
