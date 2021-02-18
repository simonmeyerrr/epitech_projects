/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** prepare_game.c
*/

#include "all.h"

sfText *init_text(sfFont *font, int size, sfVector2f pos, char *str)
{
	sfText* text = sfText_create();

	if (!text) {
		return (NULL);
	}
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, pos);
	sfText_setString(text, str);
	return (text);
}

static void prepare_text(my_text_t *text, int *error, int *settings)
{
	sfFont *font = sfFont_createFromFile((settings[3] == 0) ? (FONT1) :
	(FONT2));

	text->font = font;
	if (!text->font) {
		*error = 1;
		return;
	}
	text->score = init_text(font, 60, create_vector(10, 10), "00%");
	text->end_score = init_text(font, 100, create_vector(750, 10), "100%");
	text->win = init_text(font, 100, create_vector(550, 130), "You win!");
	text->lose = init_text(font, 100, create_vector(550, 130), "You lose!");
	if (!text->score || !text->end_score || !text->win || !text->lose)
		*error = 1;
}

static void prepare_music(my_music_t *music, int *error, int *settings)
{
	music->game = sfMusic_createFromFile(MUSIC_GAME);
	music->death = sfMusic_createFromFile(MUSIC_DEATH);
	music->jump = sfMusic_createFromFile(MUSIC_JUMP);
	music->win = sfMusic_createFromFile(MUSIC_WIN);
	if (!music->game || !music->death || !music->jump || !music->win) {
		*error = 1;
		return;
	}
	sfMusic_setLoop(music->game, sfTrue);
	sfMusic_setVolume(music->game, settings[0] * 10);
	sfMusic_setVolume(music->jump, settings[0] * 8);
	sfMusic_setVolume(music->death, settings[0] * 10);
	sfMusic_setVolume(music->win, settings[0] * 10);
	sfMusic_play(music->game);
}

static void prepare_var_clock(my_var_t *var, my_clock_t *clock, char **map)
{
	var->pourcent = 0;
	var->pause = 0;
	var->menu = 1;
	var->restart = 0;
	var->win = 0;
	var->jump = 0;
	var->move_vec = 0;
	var->reserve_jump = 0;
	var->cheat = 0;
	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int j = 0 ; map[i][j] != '\0' ; j++) {
			var->end_distance = (map[i][j] == 'E') ? (j - 3) :
			(var->end_distance);
		}
	}
	var->position = 0;
	clock->frame_rate = sfClock_create();
	clock->update = sfClock_create();
}

game_t *prepare_game(char **map, int *error, int *settings)
{
	game_t *game = malloc(sizeof(*game));

	game->texture = malloc(sizeof(*(game->texture)));
	game->sprite = malloc(sizeof(*(game->sprite)));
	game->obj = malloc(sizeof(*(game->obj)));
	game->text = malloc(sizeof(*(game->text)));
	game->var = malloc(sizeof(*(game->var)));
	game->clock = malloc(sizeof(*(game->clock)));
	game->music = malloc(sizeof(*(game->music)));
	prepare_texture(game->texture, error, settings);
	prepare_sprite(game->sprite, game->texture, error);
	prepare_obj(game->obj, map, error);
	prepare_text(game->text, error, settings);
	prepare_music(game->music, error, settings);
	prepare_var_clock(game->var, game->clock, map);
	if (*error == 0) {
		sfSprite_setTextureRect(game->sprite->player,
		game->obj->player->rect);
	}
	return (game);
}
