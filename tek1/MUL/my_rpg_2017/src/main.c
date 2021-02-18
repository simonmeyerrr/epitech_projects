/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** main.c
*/

#include "all.h"

static void main_loop(global_t *global, scene_t *scene_tab, my_clock_t *clock,
int *error)
{
	while (*error == 0 && sfRenderWindow_isOpen(global->win)) {
		while (sfRenderWindow_pollEvent(global->win, &(global->event)))
			scene_tab[global->scene].event(global, global->event);
		clock->time +=
		sfClock_getElapsedTime(clock->update).microseconds;
		sfClock_restart(clock->update);
		while (clock->time / 1000000.0 > 1.0 / 30.0) {
			clock->time -= 1000000.0 / 30.0;
			scene_tab[global->scene].update(global, error);
		}
		if (sfClock_getElapsedTime(clock->frame_rate).microseconds /
		1000000.0 > 1.0 / global->var->fps) {
			sfClock_restart(clock->frame_rate);
			sfRenderWindow_clear(global->win, sfBlack);
			scene_tab[global->scene].display(global,
			global->sprite, global->font, global->win);
			sfRenderWindow_display(global->win);
		}
	}
}

static void play_game(int *error, int online)
{
	global_t *global = malloc(sizeof(global_t));

	if (verif_malloc(global, error) != 0)
		return;
	prepare_global(global, error, online);
	if (*error == 0) {
		apply_settings(global);
		sfMusic_play(global->music->sound[SOUND_LAMA]);
		sfMusic_play(global->music->music[MUSIC_THEME]);
		main_loop(global, global->scene_tab, global->clock, error);
	}
	free_global(global);
}

static void display_usage(char *exec)
{
	my_putstr_fd("USAGE:\n\t", 1);
	my_putstr_fd(exec, 1);
	my_putstr_fd(" [option]\n\nOPTION:\n\t-h --help\tDisplay this message."
	"\n\t-o --offline\tPlay offline, you wont be able to save your game.\n"
	, 1);
}

int main(int ac, char **av, char **env)
{
	int error = 0;

	srand(time(NULL));
	switch (manage_arg(ac, av, env)) {
	case 0:
		play_game(&error, 1);
		break;
	case 1:
		play_game(&error, 0);
		break;
	case 2:
		display_usage(av[0]);
		break;
	default:
		return (MY_ERROR);
		break;
	}
	return ((error == 0) ? (MY_SUCCESS) : (MY_ERROR));
}
