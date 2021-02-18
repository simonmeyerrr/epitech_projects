/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** event.c
*/

#include "all.h"

void event_connected(global_t *global, sfEvent event)
{
	event_close(global);
}
