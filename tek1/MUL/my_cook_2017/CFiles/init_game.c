/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** init_game.c
*/

#include "all.h"

static sfRenderWindow *create_window(int *error)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, WINDOW_NAME,
	WINDOW_OPTION, NULL);

	if (verif_malloc(win, error) != 0)
		return (NULL);
	sfRenderWindow_setMouseCursorVisible(win, sfFalse);
	return (win);
}

static my_music_t *init_music(int *error)
{
	my_music_t *music = malloc(sizeof(*music));

	if (verif_malloc(music, error) != 0)
		return (NULL);
	music->click = sfMusic_createFromFile(CLICK);
	music->music_menu = sfMusic_createFromFile(MUSIC_MENU);
	music->music_game = sfMusic_createFromFile(MUSIC_GAME);
	if (!music->click || !music->music_menu || !music->music_game) {
		*error = 1;
		return (music);
	}
	sfMusic_setLoop(music->music_menu, sfTrue);
	sfMusic_setLoop(music->music_game, sfTrue);
	sfMusic_setVolume(music->click, 100);
	sfMusic_setVolume(music->music_menu, 100);
	sfMusic_setVolume(music->music_game, 100);
	sfMusic_play(music->music_menu);
	return (music);
}

static my_clock_t *init_clock(int *error)
{
	my_clock_t *clock = malloc(sizeof(*clock));

	if (verif_malloc(clock, error) != 0)
		return (NULL);
	clock->update = sfClock_create();
	clock->frame_rate = sfClock_create();
	if (!clock->update || !clock->frame_rate)
		*error = 1;
	return (clock);
}

static my_var_t *init_var(int *error)
{
	my_var_t *var = malloc(sizeof(*var));

	if (verif_malloc(var, error) != 0)
		return (NULL);
	var->menu = 0;
	var->sound = 10;
	var->music = 10;
	return (var);
}

game_t *init_game(int *error)
{
	game_t *game = malloc(sizeof(*game));

	if (verif_malloc(game, error) != 0)
		return (NULL);
	game->texture = init_texture(error);
	game->sprite = (*error) ? (NULL) : (init_sprite(game->texture, error));
	game->text = (*error) ? (NULL) : (init_text(error));
	game->music = (*error) ? (NULL) : (init_music(error));
	game->clock = (*error) ? (NULL) : (init_clock(error));
	game->var = (*error) ? (NULL) : (init_var(error));
	game->win = (*error) ? (NULL) : (create_window(error));
	return (game);
}
