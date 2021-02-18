/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** menu.c
*/

#include "all.h"

static void analyze_event_main_menu(menu_t *menu, sfEvent event,
sfRenderWindow *win)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(win);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
		menu->var->menu = 0;
	if (event.type == sfEvtMouseButtonPressed)
		sfMusic_play(menu->music->click);
	else
		return;
	if (event.mouseButton.x >= 810 && event.mouseButton.x <= 1110 &&
	event.mouseButton.y >= 400 && event.mouseButton.y <= 500)
		menu->var->menu = 2;
	if (event.mouseButton.x >= 710 && event.mouseButton.x <= 1210 &&
	event.mouseButton.y >= 550 && event.mouseButton.y <= 650)
		menu->var->menu = 3;
	if (event.mouseButton.x >= 810 && event.mouseButton.x <= 1110 &&
	event.mouseButton.y >= 700 && event.mouseButton.y <= 800)
		menu->var->menu = 0;
}

void main_menu(menu_t *menu, sfRenderWindow *win)
{
	sfVector2f pos = get_mouse_pos(win);
	sfTime time = sfClock_getElapsedTime(menu->frame_rate);

	if (time.microseconds / 1000000.0 > 1.0 / 30.0) {
		sfClock_restart(menu->frame_rate);
		sfRenderWindow_clear(win, sfBlack);
		sfRenderWindow_drawSprite(win, menu->sprite->main_menu, NULL);
		sfRenderWindow_drawText(win, menu->text->main_menu, NULL);
		sfRenderWindow_drawText(win, menu->text->my_runner, NULL);
		sfSprite_setPosition(menu->sprite->mouse, pos);
		sfRenderWindow_drawSprite(win, menu->sprite->mouse, NULL);
		sfRenderWindow_display(win);
	}
	while (sfRenderWindow_pollEvent(win, &(menu->event)))
		analyze_event_main_menu(menu, menu->event, win);
}

void init_text_menu2(menu_text_t *text, int *error, sfFont *font)
{
	text->a_font1  = init_text(font, 200, create_vector(1125, 530), "A");
	text->a_font2  = init_text(text->font2, 200, create_vector(1525, 530),
	"A");
	text->level1  = init_text(font, 102, create_vector(315, 143), TXT5);
	text->level2  = init_text(font, 102, create_vector(315, 443), TXT6);
	text->level3  = init_text(font, 102, create_vector(1460, 443), "10");
	text->level4  = init_text(font, 102, create_vector(860, 743), "11");
}
