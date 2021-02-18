/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** free_struct_menu.c
*/

#include "all.h"

static void free_music_menu(menu_music_t *music)
{
	sfMusic_destroy(music->click);
	free(music);
}

static void free_text_menu(menu_text_t *text)
{
	sfFont_destroy(text->font1);
	sfFont_destroy(text->font2);
	sfText_destroy(text->main_menu);
	sfText_destroy(text->my_runner);
	sfText_destroy(text->int_volume);
	sfText_destroy(text->ten);
	sfText_destroy(text->volume);
	sfText_destroy(text->a_font1);
	sfText_destroy(text->a_font2);
	sfText_destroy(text->level1);
	sfText_destroy(text->level2);
	sfText_destroy(text->level3);
	sfText_destroy(text->level4);
	free(text);
}

static void free_sprite_menu(menu_sprite_t *sprite)
{
	sfSprite_destroy(sprite->mouse);
	sfSprite_destroy(sprite->main_menu);
	sfSprite_destroy(sprite->set_menu);
	sfSprite_destroy(sprite->border);
	sfSprite_destroy(sprite->little_border);
	sfSprite_destroy(sprite->play_menu);
	sfSprite_destroy(sprite->lock);
	free(sprite);
}

static void free_texture_menu(menu_texture_t *texture)
{
	sfTexture_destroy(texture->mouse);
	sfTexture_destroy(texture->main_menu);
	sfTexture_destroy(texture->set_menu);
	sfTexture_destroy(texture->border);
	sfTexture_destroy(texture->little_border);
	sfTexture_destroy(texture->play_menu);
	sfTexture_destroy(texture->lock);
	free(texture);
}

void free_struct_menu(menu_t *menu)
{
	sfClock_destroy(menu->frame_rate);
	free(menu->var);
	free_texture_menu(menu->texture);
	free_sprite_menu(menu->sprite);
	free_text_menu(menu->text);
	free_music_menu(menu->music);
	free(menu);
}
