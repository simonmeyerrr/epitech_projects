/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** free_asset.c
*/

#include "all.h"

void free_font(my_font_t *font)
{
	if (!font)
		return;
	if (font->font1)
		sfFont_destroy(font->font1);
	if (font->font2)
		sfFont_destroy(font->font2);
	if (font->font3)
		sfFont_destroy(font->font3);
	free(font);
}

void free_music(my_music_t *music)
{
	if (!music)
		return;
	for (int i = 0 ; i < NB_MUSIC ; i++)
		if (music->music[i])
			sfMusic_destroy(music->music[i]);
	for (int i = 0 ; i < NB_SOUND ; i++)
		if (music->sound[i])
			sfMusic_destroy(music->sound[i]);
	my_free(music);
}

void free_sprite(my_sprite_t *sprite)
{
	if (!sprite)
		return;
	for (int i = 0 ; i < NB_BACKGROUND ; i++)
		if (sprite->background[i])
			sfSprite_destroy(sprite->background[i]);
	for (int i = 0 ; i < NB_BUTTON ; i++)
		if (sprite->button[i])
			sfSprite_destroy(sprite->button[i]);
	for (int i = 0 ; i < NB_IMAGE ; i++)
		if (sprite->image[i])
			sfSprite_destroy(sprite->image[i]);
	for (int i = 0 ; i < NB_WORLD ; i++)
		if (sprite->world[i])
			sfSprite_destroy(sprite->world[i]);
	for (int i = 0 ; i < NB_ANIMATION ; i++)
		if (sprite->animation[i])
			sfSprite_destroy(sprite->animation[i]);
	my_free(sprite);
}

void free_texture(my_texture_t *text)
{
	if (!text)
		return;
	for (int i = 0 ; i < NB_BACKGROUND ; i++)
		if (text->background[i])
			sfTexture_destroy(text->background[i]);
	for (int i = 0 ; i < NB_BUTTON ; i++)
		if (text->button[i])
			sfTexture_destroy(text->button[i]);
	for (int i = 0 ; i < NB_IMAGE ; i++)
		if (text->image[i])
			sfTexture_destroy(text->image[i]);
	for (int i = 0 ; i < NB_WORLD ; i++)
		if (text->world[i])
			sfTexture_destroy(text->world[i]);
	for (int i = 0 ; i < NB_ANIMATION ; i++)
		if (text->animation[i])
			sfTexture_destroy(text->animation[i]);
	my_free(text);
}
