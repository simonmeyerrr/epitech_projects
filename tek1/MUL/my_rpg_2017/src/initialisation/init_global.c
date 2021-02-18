/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** init_global.c
*/

#include "all.h"

static sfRenderWindow *create_window(int *error)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, WINDOW_NAME,
	WINDOW_OPTION, NULL);

	if (!win) {
		*error = 1;
		my_putstr_fd("Error while creating the window.\n", 2);
		return (NULL);
	}
	sfRenderWindow_setMouseCursorVisible(win, CURSOR_VISIBLE);
	return (win);
}

static my_network_t *prepare_network(int *error)
{
	my_network_t *net = malloc(sizeof(my_network_t));

	if (verif_malloc(net, error) != 0)
		return (NULL);
	net->time.microseconds = 500000;
	net->http = sfHttp_create();
	net->req = NULL;
	net->rep = NULL;
	if (!net->http) {
		*error = 1;
		my_putstr_fd("Error while creating http.\n", 2);
		return (net);
	}
	sfHttp_setHost(net->http, "my-rpg.alwaysdata.net", 80);
	return (net);
}

static my_clock_t *prepare_clock(int *error)
{
	my_clock_t *clock = malloc(sizeof(my_clock_t));

	if (verif_malloc(clock, error))
		return (NULL);
	clock->time = 0;
	clock->update = sfClock_create();
	clock->frame_rate = sfClock_create();
	if (!clock->update || !clock->frame_rate) {
		*error = 1;
		my_putstr_fd("Error while creating clocks.\n", 2);
	}
	return (clock);
}

static void prepare_scene(global_t *global)
{
	void (*tab1[NB_SCENE])(global_t *, sfEvent) = TAB_EVENT;
	void (*tab2[NB_SCENE])(global_t *, int *) = TAB_UPDATE;
	void (*tab3[NB_SCENE])(global_t *, my_sprite_t *, my_font_t *,
	sfRenderWindow *) = TAB_DISPLAY;

	for (int i = 0 ; i < NB_SCENE ; i++) {
		global->scene_tab[i].event = tab1[i];
		global->scene_tab[i].update = tab2[i];
		global->scene_tab[i].display = tab3[i];
	}
	global->scene = SCENE_MAIN_MENU;
}

void prepare_global(global_t *global, int *error, int online)
{
	prepare_scene(global);
	global->texture = prepare_texture(error);
	global->sprite = (global->texture && *error == 0) ?
	(prepare_sprite(global->texture, error)) : (NULL);
	global->music = prepare_music(error);
	global->font = prepare_font(error);
	global->clock = prepare_clock(error);
	global->var = prepare_var(error);
	global->net = (online) ? (prepare_network(error)) : (NULL);
	global->win = (*error == 0) ? (create_window(error)) : (NULL);
	global->game = NULL;
}
