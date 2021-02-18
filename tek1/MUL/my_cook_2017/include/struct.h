/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct my_obj
{
	double time;
	int score;
	int animation;

	int status;
	int cook;
	char *need;
	char *have;
	double begin;
} my_obj_t;

typedef struct my_var
{
	int menu;
	int music;
	int sound;
} my_var_t;

typedef struct my_clock
{
	long long time;

	sfClock *update;
	sfClock *frame_rate;
} my_clock_t;

typedef struct my_music
{
	sfMusic *click;
	sfMusic *music_menu;
	sfMusic *music_game;
} my_music_t;

typedef struct my_text
{
	sfFont *font1;
	sfFont *font2;

	sfText *play;
	sfText *settings_menu;
	sfText *exit_menu;
	sfText *tutorial;

	sfText *plus_minus;
	sfText *music;
	sfText *sound;
	sfText *return_set;

	sfText *end_score;
	sfText *high_score;
	sfText *exit_end;

	sfText *resume;
	sfText *set_pause;
	sfText *exit_pause;

	sfText *score;
	sfText *time;
	sfText *cook;
	sfText *recipe;
} my_text_t;

typedef struct my_sprite
{
	sfSprite *main_menu;
	sfSprite *button_off;
	sfSprite *button_on;
	sfSprite *black;
	sfSprite *white;
	sfSprite *mouse;
	sfSprite *easter_egg;
	sfSprite *easter_egg2;
	sfSprite *game;
	sfSprite *tuto;
	sfSprite *fail;
	sfSprite *validation;
	sfSprite *setting;
	sfSprite *button2;
	sfSprite *end;
	sfSprite *pause;

	sfSprite *bread1;
	sfSprite *bread2;
	sfSprite *steak;
	sfSprite *chicken;
	sfSprite *cheddar;
	sfSprite *emmental;
	sfSprite *lettuce;
	sfSprite *bacon;
	sfSprite *tomatoes;
	sfSprite *ketchup;
	sfSprite *onions;
	sfSprite *mayonnaise;
	sfSprite *pickles;
	sfSprite *bbq;
} my_sprite_t;

typedef struct my_texture
{
	sfTexture *main_menu;
	sfTexture *button_off;
	sfTexture *button_on;
	sfTexture *black;
	sfTexture *white;
	sfTexture *mouse;
	sfTexture *easter_egg;
	sfTexture *easter_egg2;
	sfTexture *game;
	sfTexture *tuto;
	sfTexture *fail;
	sfTexture *validation;
	sfTexture *setting;
	sfTexture *button2;
	sfTexture *end;
	sfTexture *pause;

	sfTexture *bread1;
	sfTexture *bread2;
	sfTexture *steak;
	sfTexture *chicken;
	sfTexture *cheddar;
	sfTexture *emmental;
	sfTexture *lettuce;
	sfTexture *bacon;
	sfTexture *tomatoes;
	sfTexture *ketchup;
	sfTexture *onions;
	sfTexture *mayonnaise;
	sfTexture *pickles;
	sfTexture *bbq;
} my_texture_t;

typedef struct my_game
{
	sfRenderWindow *win;
	sfEvent event;

	my_texture_t *texture;
	my_sprite_t *sprite;
	my_text_t *text;
	my_music_t *music;
	my_clock_t *clock;
	my_var_t *var;
} game_t;

#endif	/* STRUCT_H_ */
