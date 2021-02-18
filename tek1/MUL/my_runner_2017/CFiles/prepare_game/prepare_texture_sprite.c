/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** prepare_texture_sprite.c
*/

#include "all.h"

sfSprite *create_sprite(sfTexture *texture, int *error)
{
	sfSprite *sprite = sfSprite_create();

	if (!sprite) {
		*error = 1;
		return (NULL);
	}
	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}

void prepare_sprite(my_sprite_t *sprite, my_texture_t *texture, int *error)
{
	sfTexture **tab1[13] = {&texture->player, &texture->full_block,
	&texture->semi_block, &texture->jump_block, &texture->jump_infinite,
	&texture->end_block, &texture->background1, &texture->background2,
	&texture->background3, &texture->pause_menu, &texture->end_menu,
	&texture->mouse, &texture->pick};
	sfSprite **tab2[13] = {&sprite->player, &sprite->full_block,
	&sprite->semi_block, &sprite->jump_block, &sprite->jump_infinite,
	&sprite->end_block, &sprite->background1, &sprite->background2,
	&sprite->background3, &sprite->pause_menu, &sprite->end_menu,
	&sprite->mouse, &sprite->pick};

	for (int i = 0 ; i < 13 && *error == 0 ; i++)
		*tab2[i] = create_sprite(*tab1[i], error);
}

void prepare_texture(my_texture_t *texture, int *error, int *settings)
{
	sfTexture **tab1[12] = {&texture->full_block, &texture->semi_block,
	&texture->jump_block, &texture->jump_infinite, &texture->end_block,
	&texture->background1, &texture->background2, &texture->background3,
	&texture->pause_menu, &texture->end_menu, &texture->mouse,
	&texture->pick};
	char *tab2[12] = {FULL_BLOCK, SEMI_BLOCK, JUMP_BLOCK, JUMP_INFINITE,
	END_BLOCK, BACKGROUND1, BACKGROUND2, BACKGROUND3, PAUSE_MENU, END_MENU,
	MOUSE, PICK};
	char *tab3[2] = {PLAYER1, PLAYER2};

	for (int i = 0 ; i < 12 && *error == 0 ; i++) {
		*tab1[i] = sfTexture_createFromFile(tab2[i], NULL);
		if (!*tab1[i])
			*error = 1;
	}
	texture->player = sfTexture_createFromFile(tab3[settings[1]], NULL);
	if (!texture->player)
		*error = 1;
}
