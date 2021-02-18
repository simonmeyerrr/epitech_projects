/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** destroy
*/

#include "all.h"

static void destroy_text2(myText_t* text)
{
	sfText_destroy(text->end_int_stage);
	sfText_destroy(text->shot_success);
	sfText_destroy(text->int_shot_success);
	sfText_destroy(text->shot_double);
	sfText_destroy(text->int_shot_double);
	sfText_destroy(text->shot_failed);
	sfText_destroy(text->int_shot_failed);
	sfText_destroy(text->precision);
	sfText_destroy(text->int_precision);
	sfText_destroy(text->bird_B_shot);
	sfText_destroy(text->bird_Y_shot);
	sfText_destroy(text->int_bird_B_shot);
	sfText_destroy(text->int_bird_Y_shot);
	sfText_destroy(text->bird_B_fail);
	sfText_destroy(text->bird_Y_fail);
	sfText_destroy(text->int_bird_B_fail);
	sfText_destroy(text->int_bird_Y_fail);
	free(text);
}

static void destroy_text(myText_t* text)
{
	sfText_destroy(text->title);
	sfText_destroy(text->start);
	sfText_destroy(text->exit);
	sfText_destroy(text->pause);
	sfText_destroy(text->score);
	sfText_destroy(text->int_score);
	sfText_destroy(text->life);
	sfText_destroy(text->int_life);
	sfText_destroy(text->stage);
	sfText_destroy(text->int_stage);
	sfText_destroy(text->game_over);
	sfText_destroy(text->restart);
	sfText_destroy(text->end_exit);
	sfText_destroy(text->new_high_score);
	sfText_destroy(text->int_new_high_score);
	sfText_destroy(text->end_score);
	sfText_destroy(text->end_int_score);
	sfText_destroy(text->int_high_score);
	sfText_destroy(text->end_stage);
	destroy_text2(text);
}

static void destroy_sprite_texture(mySprite_t* sprite, myTexture_t* texture)
{
	sfSprite_destroy(sprite->background);
	sfSprite_destroy(sprite->bird_RB);
	sfSprite_destroy(sprite->bird_RY);
	sfSprite_destroy(sprite->bird_LB);
	sfSprite_destroy(sprite->bird_LY);
	sfSprite_destroy(sprite->crosshair);
	sfSprite_destroy(sprite->mouse);
	sfSprite_destroy(sprite->begin_menu);
	sfSprite_destroy(sprite->end_menu);
	free(sprite);
	sfTexture_destroy(texture->background);
	sfTexture_destroy(texture->bird_RB);
	sfTexture_destroy(texture->bird_RY);
	sfTexture_destroy(texture->bird_LB);
	sfTexture_destroy(texture->bird_LY);
	sfTexture_destroy(texture->crosshair);
	sfTexture_destroy(texture->mouse);
	sfTexture_destroy(texture->begin_menu);
	sfTexture_destroy(texture->end_menu);
	free(texture);
}

static void destroy_music_clock(myMusic_t* music, myClock_t* clock)
{
	sfMusic_destroy(music->menu);
	sfMusic_destroy(music->game);
	sfMusic_destroy(music->shot_blue);
	sfMusic_destroy(music->shot_yellow);
	sfMusic_destroy(music->double_shot);
	sfMusic_destroy(music->shotgun);
	sfMusic_destroy(music->lose_life);
	sfMusic_destroy(music->game_over);
	free(music);
	sfClock_destroy(clock->game);
	sfClock_destroy(clock->pause);
	sfClock_destroy(clock->shot);
	sfClock_destroy(clock->frame_rate);
	free(clock);
}

void my_destroy(myObjects_t* obj)
{
	sfRenderWindow_destroy(obj->window);
	destroy_sprite_texture(obj->sprite, obj->texture);
	destroy_text(obj->text);
	destroy_music_clock(obj->music, obj->clock);
	free(obj);
}
