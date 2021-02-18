/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** prepare
*/

#include "all.h"

static int determine_hs(myObjects_t* obj, myText_t* text, myStat_t* stat,
	int fd)
{
	char str[6];

	if (fd < 0) {
		sfText_setString(text->end_int_score, five_to_str(stat->score));
		write(2, "Error while reading highest score\n", 34);
		return (2);
	}
	read(fd, str, 5);
	str[5] = '\0';
	close(fd);
	if (my_strcmp(str, five_to_str(stat->score)) >= 0) {
		sfText_setString(text->int_high_score, str);
		sfText_setString(text->end_int_score, five_to_str(stat->score));
	} else {
		fd = open("settings/highscore", O_WRONLY | O_TRUNC);
		write(fd, five_to_str(stat->score), 5);
		close(fd);
		return (1);
	}
	return (2);
}

static void prepare_end2(myObjects_t* obj, myText_t* text, myStat_t* stat)
{
	int fd = open("settings/highscore", O_RDONLY);

	sfText_setString(text->int_bird_B_shot,
		three_to_str(stat->shot_blue));
	sfText_setString(text->int_bird_B_fail, three_to_str(stat->fail_blue));
	sfText_setString(text->int_bird_Y_shot,
		three_to_str(stat->shot_yellow));
	sfText_setString(text->int_bird_Y_fail,
		three_to_str(stat->fail_yellow));
	if (determine_hs(obj, text, stat, fd) == 1) {
		sfText_setString(text->int_new_high_score,
			five_to_str(stat->score));
		obj->var->new_highscore = 1;
	} else
		obj->var->new_highscore = 0;
	sfMusic_play(obj->music->menu);
}

void prepare_end(myObjects_t* obj, myText_t* text, myStat_t* stat)
{
	sfMusic_stop(obj->music->game);
	sfMusic_play(obj->music->game_over);
	if (stat->shot == stat->shot_succes && stat->shot != 0)
		sfText_setString(text->int_precision, "100%");
	else if (stat->shot != 0) {
		stat->precision = stat->shot_succes / stat->shot * 100.0;
		sfText_setString(text->int_precision,
		pc_to_str(stat->precision));
	} else
		sfText_setString(text->int_precision, "--%");
	obj->var->menu = 3;
	sfText_setString(text->end_int_stage, two_to_str(stat->stage));
	sfText_setString(text->int_shot_success,
		three_to_str(stat->shot_succes));
	sfText_setString(text->int_shot_double,
		three_to_str(stat->double_shot));
	sfText_setString(text->int_shot_failed,
		three_to_str(stat->shot_failed));
	prepare_end2(obj, text, stat);
}

static void prepare_game2(myStat_t* stat, myVar_t* var)
{
	stat->shot = 0;
	stat->stage = 1;
	stat->shot_failed = 0;
	stat->shot_succes = 0;
	stat->shot_blue = 0;
	stat->shot_yellow = 0;
	stat->double_shot = 0;
	var->menu = 2;
	var->birdgoright = 0;
	var->birdgoleft = 0;
	var->image_move_rect = 0;
	var->difficulty = 1;
	var->pause = 0;
	var->pause_time = 0;
	var->randomLY = 0;
	var->randomLX = 0;
	var->randomRY = 0;
	var->randomRX = 0;
	stat->fail_blue = 0;
	stat->fail_yellow = 0;
}

void prepare_game(myObjects_t* obj)
{
	obj->stat->score = 0;
	obj->stat->life = 5;
	prepare_game2(obj->stat, obj->var);
	sfClock_restart(obj->clock->game);
	sfMusic_stop(obj->music->menu);
	sfMusic_play(obj->music->game);
}
