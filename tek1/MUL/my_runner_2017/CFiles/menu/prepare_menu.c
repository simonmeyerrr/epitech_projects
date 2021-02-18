/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** prepare_menu.c
*/

#include "all.h"

static menu_music_t *init_music_menu(int *error)
{
	menu_music_t *music = malloc(sizeof(*music));

	music->click = sfMusic_createFromFile(MUSIC_CLICK);
	if (!music->click) {
		*error = 1;
		return (NULL);
	}
	return (music);
}

static menu_text_t *init_text_menu(int *error)
{
	menu_text_t *text = malloc(sizeof(*text));
	sfFont *font = sfFont_createFromFile(FONT1);

	text->font1 = font;
	text->font2 = sfFont_createFromFile(FONT2);
	if (!text->font1 || !text->font2) {
		*error = 1;
		return (NULL);
	}
	text->main_menu = init_text(font, 60, create_vector(730, 415), TXT1);
	text->my_runner = init_text(font, 100, create_vector(520, 150), TXT2);
	text->int_volume = init_text(font, 51, create_vector(190, 170), TXT3);
	text->ten = init_text(font, 51, create_vector(1660, 170), "10");
	text->volume = init_text(font, 80, create_vector(260, 20), TXT4);
	init_text_menu2(text, error, font);
	if (!text->main_menu || !text->my_runner || !text->int_volume ||
	!text->ten || !text->a_font1 || !text->font2 || !text->volume ||
	!text->level1 || !text->level2 || !text->level3 || !text->level4)
		*error = 1;
	return (text);
}

static menu_sprite_t *init_sprite_menu(menu_texture_t *texture, int *error)
{
	menu_sprite_t *sprite = malloc(sizeof(*sprite));
	sfTexture **tab1[7] = {&texture->mouse, &texture->main_menu,
	&texture->set_menu, &texture->border, &texture->little_border,
	&texture->play_menu, &texture->lock};
	sfSprite **tab2[7] = {&sprite->mouse, &sprite->main_menu,
	&sprite->set_menu, &sprite->border, &sprite->little_border,
	&sprite->play_menu, &sprite->lock};

	for (int i = 0 ; i < 7 && *error == 0 ; i++)
		*tab2[i] = create_sprite(*tab1[i], error);
	return (sprite);
}

static menu_texture_t *init_texture_menu(int *error)
{
	menu_texture_t *texture = malloc(sizeof(*texture));
	sfTexture **tab1[7] = {&texture->mouse, &texture->main_menu,
	&texture->set_menu, &texture->border, &texture->little_border,
	&texture->play_menu, &texture->lock};
	char *tab2[7] = {MOUSE, MAIN_MENU, SET_MENU, BORDER, LITTLE_BORDER,
	PLAY_MENU, LOCK};

	for (int i = 0 ; i < 7 && *error == 0 ; i++) {
		*tab1[i] = sfTexture_createFromFile(tab2[i], NULL);
		if (!*tab1[i])
			*error = 1;
	}
	return (texture);
}

menu_t *prepare_menu(int *error)
{
	menu_t *menu = malloc(sizeof(*menu));

	menu->texture = init_texture_menu(error);
	menu->sprite = init_sprite_menu(menu->texture, error);
	menu->text = init_text_menu(error);
	menu->music = init_music_menu(error);
	menu->frame_rate = sfClock_create();
	menu->var = malloc(sizeof(*(menu->var)));
	menu->var->menu = 1;
	menu->var->sound = 10;
	menu->var->theme = 0;
	menu->var->level_choice = 1;
	menu->var->level_max = 1;
	menu->var->font = 0;
	return (menu);
}
