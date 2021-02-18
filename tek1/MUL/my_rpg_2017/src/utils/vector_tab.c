/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** vector_tab.c
*/

#include "all.h"

sfVector2f create_vec(int x, int y)
{
	sfVector2f vec = {x, y};

	return (vec);
}

sfVector2f get_mouse_pos(global_t *global)
{
	sfVector2i vec = sfMouse_getPositionRenderWindow(global->win);

	return (create_vec(vec.x, vec.y));
}

int *create_tab4(int nb1, int nb2, int nb3, int nb4)
{
	int *tab = malloc(sizeof(int) * 5);

	if (!tab)
		return (NULL);
	tab[0] = nb1;
	tab[1] = nb2;
	tab[2] = nb3;
	tab[3] = nb4;
	return (tab);
}

int *create_tab2(int nb1, int nb2)
{
	int *tab = malloc(sizeof(int) * 2);

	if (!tab)
		return (NULL);
	tab[0] = nb1;
	tab[1] = nb2;
	return (tab);
}
