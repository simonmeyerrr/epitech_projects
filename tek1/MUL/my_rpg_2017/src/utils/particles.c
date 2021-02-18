/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** particles.c
*/

#include "../include/all.h"

static int malloc_buff(part_t **buff, int size, int color)
{
	(*buff) = malloc(sizeof(part_t));
	(*buff)->vertex = malloc(sizeof(sfVertex) * size * 4);
	(*buff)->speed = malloc(sizeof(sfVector2f) * size * 4);
	(*buff)->life = malloc(sizeof(int) * size);
	(*buff)->state = malloc(sizeof(sfRenderStates));
	(*buff)->text = sfTexture_createFromFile((color == 1) ?
	("asset/texture/part.png") : ("asset/texture/part2.png"), NULL);
	(*buff)->state->shader = NULL;
	(*buff)->state->blendMode = sfBlendAlpha;
	(*buff)->state->transform = sfTransform_Identity;
	(*buff)->state->texture = (*buff)->text;
	(*buff)->size = size;
	if (!(*buff) || !(*buff)->vertex || !(*buff)->speed ||
	!(*buff)->life || !(*buff)->state)
		return (1);
	return (0);
}

part_t *new_part_buffer(int size, int color)
{
	float rand_nb;
	part_t *buff;

	if (malloc_buff(&buff, size, color))
		return (NULL);
	for (int i = 0; i < size; i++) {
		buff->life[i] = 25;
		rand_nb = (rand() % (629)) / 100.0 - 1;
		for (int j = 0; j < 4; j++) {
			buff->speed[i * 4 + j].x = cos(rand_nb) *
			((rand() % 1000) / 100.0 + 1);
			buff->speed[i * 4 + j].y = sin(rand_nb) *
			((rand() % 1000) / 100.0 + 1);
		}
	}
	return (buff);
}

void set_part(part_t *buff, sfVector2f pos)
{
	for (int i = 0; i < buff->size; i++) {
		buff->vertex[i * 4 + 0].position =
		VEC(pos.x, pos.y);
		buff->vertex[i * 4 + 1].position =
		VEC(pos.x + 100, pos.y);
		buff->vertex[i * 4 + 2].position =
		VEC(pos.x + 100, pos.y + 100);
		buff->vertex[i * 4 + 3].position =
		VEC(pos.x, pos.y + 100);
		buff->vertex[i * 4 + 0].texCoords = VEC(0 , 0);
		buff->vertex[i * 4 + 1].texCoords = VEC(100, 0);
		buff->vertex[i * 4 + 2].texCoords = VEC(100, 100);
		buff->vertex[i * 4 + 3].texCoords = VEC(0 , 100);
		for (int j = 0; j < 4; j++) {
			buff->vertex[i * 4 + j].color = sfWhite;
			buff->vertex[i * 4 + j].color.a = 100;
		}
	}
}

void draw_part(sfRenderWindow *window, part_t *buff)
{
	if (buff && buff->text)
		sfRenderWindow_drawPrimitives(window, buff->vertex, buff->size
		* 4, sfQuads, buff->state);
}

void update_part(part_t *buff)
{
	for (int i = 0; i < buff->size && buff->life[i]; i++) {
		buff->life[i] -= 1;
		for (int j = 0; j < 4; j++) {
			buff->vertex[i * 4 + j].position.x +=
			buff->speed[i * 4 + j].x;
			buff->vertex[i * 4 + j].position.y +=
			buff->speed[i * 4 + j].y;
		}
		for (int j = 0; buff->life[i] < 10 && j < 4; j++)
			buff->vertex[i * 4 + j].color.a -= 10;
	}
}
