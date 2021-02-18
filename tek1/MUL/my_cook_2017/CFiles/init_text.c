/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** init_text_music.c
*/

#include "all.h"

static sfText *create_text(sfFont *font, int size, sfVector2f pos, char *str)
{
	sfText* text = sfText_create();

	if (!text)
		return (NULL);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, pos);
	sfText_setString(text, str);
	return (text);
}

static void prepare_text1(my_text_t *text, sfFont *font, int *error)
{
	text->play = create_text(font, 125, create_vector(1050, 80), "Play");
	text->settings_menu = create_text(font, 125, create_vector(1050, 440),
	"Settings");
	text->exit_menu = create_text(font, 125, create_vector(1050, 620),
	"Exit");
	text->tutorial = create_text(font, 120, create_vector(1050, 260),
	"How to play");
	text->plus_minus = create_text(font, 305, create_vector(110, 100),
	"-   +    -   +");
	text->return_set = create_text(font, 120, create_vector(620, 680),
	"Return");
	text->exit_end = create_text(font, 120, create_vector(620, 680),
	"Return");
	text->resume = create_text(font, 120, create_vector(620, 200),
	"Resume");
	if (!text->play || !text->settings_menu || !text->exit_menu ||
	!text->tutorial || !text->plus_minus || !text->return_set ||
	!text->exit_end || !text->resume)
		*error = 1;
}

static void prepare_text2(my_text_t *text, sfFont *font, int *error)
{
	text->score = create_text(font, 40, create_vector(150, -5), "69");
	text->time = create_text(font, 40, create_vector(620, -5), "0");
	text->cook = create_text(font, 60, create_vector(10, 740), "");
	text->recipe = create_text(font, 30, create_vector(0, 820), "");
	text->music = create_text(font, 150, create_vector(300, 280), "10");
	text->sound = create_text(font, 150, create_vector(1170, 280), "10");
	text->end_score = create_text(font, 110, create_vector(850, 0), "0");
	text->high_score = create_text(font, 110, create_vector(850, 150), "?");
	if (!text->score || !text->time || !text->recipe || !text->cook ||
	!text->music || !text->sound || !text->end_score ||
	!text->high_score) {
		*error = 1;
		return;
	}
	sfText_setColor(text->score, sfBlack);
	sfText_setColor(text->time, sfBlack);
	sfText_setColor(text->cook, sfBlack);
	sfText_setColor(text->recipe, sfBlack);
}

static void prepare_text3(my_text_t *text, sfFont *font, int *error)
{
	text->set_pause = create_text(font, 120, create_vector(620, 380),
	"Settings");
	text->exit_pause = create_text(font, 120, create_vector(620, 560),
	"Exit");
	if (!text->set_pause || !text->exit_pause)
		*error = 1;
}

my_text_t *init_text(int *error)
{
	my_text_t *text = malloc(sizeof(*text));

	if (verif_malloc(text, error) != 0)
		return (NULL);
	text->font1 = sfFont_createFromFile(FONT1);
	text->font2 = sfFont_createFromFile(FONT2);
	if (verif_malloc(text->font1, error) != 0 ||
	verif_malloc(text->font2, error) != 0)
		return (text);
	prepare_text1(text, text->font1, error);
	prepare_text2(text, text->font2, error);
	prepare_text3(text, text->font1, error);
	return (text);
}
