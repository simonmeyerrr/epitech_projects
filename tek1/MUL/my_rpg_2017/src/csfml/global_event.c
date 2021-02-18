/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** global_event.c
*/

#include "all.h"

int event_click(global_t *global)
{
	if (global->event.type == sfEvtMouseButtonPressed) {
		sfMusic_play(global->music->sound[SOUND_CLICK]);
		return (1);
	}
	return (0);
}

int event_key(global_t *global, sfKeyCode key)
{
	if (global->event.type == sfEvtKeyPressed &&
	global->event.key.code == key)
		return (1);
	return (0);
}

int mouse_on_button(sfVector2f mouse_pos, int *tab)
{
	if (!tab)
		return (0);
 	if (mouse_pos.x >= tab[0] && mouse_pos.x <= tab[0] + tab[2]
	&& mouse_pos.y >= tab[1] && mouse_pos.y <= tab[1] + tab[3]) {
		my_free(tab);
		return (1);
	}
	my_free(tab);
	return (0);
}

void event_close(global_t *global)
{
	if (global->event.type == sfEvtClosed)
		sfRenderWindow_close(global->win);
}

void input_to_str(sfKeyCode key, char *str)
{
	sfKeyCode tab1[26] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
	sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO,
	sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX,
	sfKeyY, sfKeyZ};
	sfKeyCode tab2[10] = {sfKeyNum0, sfKeyNum1, sfKeyNum2, sfKeyNum3,
	sfKeyNum4, sfKeyNum5, sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9};

	if (key == sfKeyBack && my_strlen(str) > 0)
		str[my_strlen(str) - 1] = '\0';
	if (my_strlen(str) >= 18)
		return;
	for (int i = 0 ; i < 26 ; i++) {
		if (key == tab1[i])
			str[my_strlen(str)] = i + 'a';
	}
	for (int i = 0 ; i < 10 ; i++) {
		if (key == tab2[i])
			str[my_strlen(str)] = i + '0';
	}
}
