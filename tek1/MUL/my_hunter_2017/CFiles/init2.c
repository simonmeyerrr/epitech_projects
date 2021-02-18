/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** init part 2
*/

#include "all.h"

static sfText* init_text(sfFont* font, int size, sfVector2f pos, char* str)
{
	sfText* text = sfText_create();

	if (text == NULL) {
		my_putstr("Error while loading texts.");
		return (NULL);
	}
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, pos);
	if (str[0] != '\0')
		sfText_setString(text, str);
	return (text);
}

void my_init_text4(myText_t* text, sfFont* font)
{
	text->int_bird_Y_shot = init_text(font, 30, create_vector(1275, 511),
	"");
	text->int_bird_B_fail = init_text(font, 30, create_vector(1275, 589),
	"");
	text->int_bird_Y_fail = init_text(font, 30, create_vector(1275, 628),
	"");
	sfText_setColor(text->shot_failed, sfRed);
	sfText_setColor(text->int_shot_failed, sfRed);
	sfText_setColor(text->bird_B_fail, sfRed);
	sfText_setColor(text->int_bird_B_fail, sfRed);
	sfText_setColor(text->bird_Y_fail, sfRed);
	sfText_setColor(text->int_bird_Y_fail, sfRed);
	sfText_setColor(text->shot_success, sfGreen);
	sfText_setColor(text->int_shot_success, sfGreen);
	sfText_setColor(text->shot_double, sfGreen);
	sfText_setColor(text->int_shot_double, sfGreen);
	sfText_setColor(text->bird_B_shot, sfGreen);
	sfText_setColor(text->int_bird_B_shot, sfGreen);
	sfText_setColor(text->bird_Y_shot, sfGreen);
	sfText_setColor(text->int_bird_Y_shot, sfGreen);
}

void my_init_text3(myText_t* text, sfFont* font)
{
	text->shot_failed = init_text(font, 30, create_vector(615, 550),
	"Shot failed");
	text->bird_B_shot = init_text(font, 30, create_vector(615, 472),
	"Shot blue bird");
	text->bird_Y_shot = init_text(font, 30, create_vector(615, 511),
	"Shot yellow bird");
	text->bird_B_fail = init_text(font, 30, create_vector(615, 589),
	"Blue bird failed");
	text->bird_Y_fail = init_text(font, 30, create_vector(615, 628),
	"Yellow bird failed");
	text->int_shot_success = init_text(font, 30, create_vector(1275, 394),
	"");
	text->int_shot_double = init_text(font, 30, create_vector(1275, 433),
	"");
	text->int_shot_failed = init_text(font, 30, create_vector(1275, 550),
	"");
	text->int_bird_B_shot = init_text(font, 30, create_vector(1275, 472),
	"");
	my_init_text4(text, font);
}

void my_init_text2(myText_t* text, sfFont* font)
{
	text->new_high_score = init_text(font, 30, create_vector(630, 260),
	"You made a new highscore:");
	text->int_new_high_score = init_text(font, 30, create_vector(925, 298),
	"");
	text->end_score = init_text(font, 30, create_vector(650, 260),
	"Your score:   Highscore:");
	text->end_int_score = init_text(font, 30, create_vector(742, 298), "");
	text->int_high_score = init_text(font, 30, create_vector(1123, 298),
	"");
	text->end_stage = init_text(font, 30, create_vector(1135, 355),
	"Stage:");
	text->end_int_stage = init_text(font, 30, create_vector(1305, 355), "");
	text->precision = init_text(font, 30, create_vector(615, 355),
	"Precision:");
	text->int_precision = init_text(font, 30, create_vector(905, 355), "");
	text->shot_success = init_text(font, 30, create_vector(615, 394),
	"Shot successfull");
	text->shot_double = init_text(font, 30, create_vector(615, 433),
	"Double shot");
	my_init_text3(text, font);
}

void my_init_text(myText_t* text, sfFont* font, int* error)
{
	font = sfFont_createFromFile(FONT);
	if (font == NULL) {
		*error = 1;
		return;
	}
	text->title = init_text(font, 90, create_vector(600, 260), "My Hunter");
	text->start = init_text(font, 80, create_vector(810, 495), "START");
	text->exit = init_text(font, 80, create_vector(845, 690), "EXIT");
	text->pause = init_text(font, 150, create_vector(600, 400), "PAUSE");
	text->score = init_text(font, 50, create_vector(20, 900), "SCORE:");
	text->int_score = init_text(font, 50, create_vector(325, 900), "");
	text->life = init_text(font, 50, create_vector(850, 900), "LIFE:");
	text->int_life = init_text(font, 50, create_vector(1100, 900), "");
	text->stage = init_text(font, 50, create_vector(1500, 900), "STAGE:");
	text->int_stage = init_text(font, 50, create_vector(1800, 900), "");
	text->restart = init_text(font, 52, create_vector(621, 752), "RESTART");
	text->end_exit = init_text(font, 55, create_vector(1100, 750), "EXIT");
	text->game_over = init_text(font, 90, create_vector(600, 60),
	"Game Over");
	my_init_text2(text, font);
}
