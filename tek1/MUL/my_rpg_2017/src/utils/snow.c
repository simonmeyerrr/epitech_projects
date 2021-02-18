/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** snow.c
*/

#include "all.h"

static int malloc_buff(snow_t **buff, int size)
{
	(*buff) = malloc(sizeof(snow_t));
	(*buff)->vertex = malloc(sizeof(sfVertex) * size * 4);
	(*buff)->speed = malloc(sizeof(sfVector2f) * size * 4);
	(*buff)->size = size;
	if (!(*buff) || !(*buff)->vertex || !(*buff)->speed)
		return (1);
	return (0);
}

void free_snow(snow_t *buff)
{
	if (!buff)
		return;
	my_free(buff->speed);
	my_free(buff->vertex);
	free(buff);
}

snow_t *new_snow_buffer(int size, int width, int height)
{
	snow_t *buff;
	int randx;
	int randy;

	if (malloc_buff(&buff, size))
		return (NULL);
	buff->coord.x = width;
	buff->coord.y = height;
	for (int i = 0; i < size; i++) {
		randx = rand() % 3 + 1;
		randy = rand() % 10 + 3;
		for (int j = 0; j < 4; j++) {
			buff->speed[i * 4 + j].x = randx;
			buff->speed[i * 4 + j].y = randy;
		}
	}
	return (buff);
}

void set_snow(snow_t *buff)
{
	int posx;
	int posy;

	for (int i = 0; buff && i < buff->size; i++) {
		posx = rand() % 1900;
		posy = rand() % 1000;
		buff->vertex[i * 4 + 0].position =
		VEC(posx, posy);
		buff->vertex[i * 4 + 1].position =
		VEC(posx + 2, posy);
		buff->vertex[i * 4 + 2].position =
		VEC(posx + 2, posy + 2);
		buff->vertex[i * 4 + 3].position =
		VEC(posx, posy + 2);
		for (int j = 0; j < 4; j++) {
			buff->vertex[i * 4 + j].color = sfWhite;
			buff->vertex[i * 4 + j].color.a = 100;
		}
	}
}

void update_snow(snow_t *buff)
{
	for (int i = 0; buff && i < buff->size; i++) {
		for (int j = 0; j < 4; j++) {
			buff->vertex[i * 4 + j].position.x +=
			buff->speed[i * 4 + j].x;
			buff->vertex[i * 4 + j].position.y +=
			buff->speed[i * 4 + j].y;
		}
		if (buff->vertex[i * 4].position.x > buff->coord.x) {
			buff->vertex[i * 4].position.x -= buff->coord.x;
			buff->vertex[i * 4 + 1].position.x -= buff->coord.x;
			buff->vertex[i * 4 + 2].position.x -= buff->coord.x;
			buff->vertex[i * 4 + 3].position.x -= buff->coord.x;
		}
		if (buff->vertex[i * 4].position.y > buff->coord.y) {
			buff->vertex[i * 4].position.y -= buff->coord.y;
			buff->vertex[i * 4 + 1].position.y -= buff->coord.y;
			buff->vertex[i * 4 + 2].position.y -= buff->coord.y;
			buff->vertex[i * 4 + 3].position.y -= buff->coord.y;
		}
	}
}
