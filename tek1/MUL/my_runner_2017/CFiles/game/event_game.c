/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** event_game.c
*/

#include "all.h"

static void manage_mouse_click_game(game_t *game, sfMouseButtonEvent event)
{
	if (event.x >= 440 && event.x <= 740 && event.y >= 390 &&
	event.y <= 690)
		game->var->pause = 0;
	if (event.x >= 1180 && event.x <= 1480 && event.y >= 390 &&
	event.y <= 690) {
		game->var->menu = 2;
		game->var->win = 0;
	}
}

void analyze_event_end(game_t *game, sfEvent event, sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if ((event.mouseButton.x >= 440 && event.mouseButton.x <= 740 &&
	event.mouseButton.y >= 350 && event.mouseButton.y <= 650 &&
	event.type == sfEvtMouseButtonPressed) ||
	(event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn)) {
		game->var->restart = 1;
		game->var->menu = 0;
	}
	if ((event.mouseButton.x >= 1180 && event.mouseButton.x <= 1480 &&
	event.mouseButton.y >= 350 && event.mouseButton.y <= 650 &&
	event.type == sfEvtMouseButtonPressed) || (event.type == sfEvtKeyPressed
	&& event.key.code == sfKeyEscape)) {
		game->var->menu = 0;
	}
}

void analyze_event_game(game_t *game, sfEvent event, sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed && (event.key).code == sfKeyEscape) {
		(game->var->pause == 0) ? (game->var->pause = 1) :
		(game->var->pause = 0);
	}
	if (event.type == sfEvtKeyPressed && (event.key).code == sfKeySpace &&
	game->var->jump == 0 && game->var->pause == 0)
		game->var->jump = 1;
	if (event.type == sfEvtKeyReleased && (event.key).code == sfKeySpace)
		game->var->jump = 0;
	if (event.type == sfEvtMouseButtonPressed && game->var->pause == 1)
		manage_mouse_click_game(game, event.mouseButton);
}
