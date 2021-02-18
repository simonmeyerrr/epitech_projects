/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** drawing.c
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size,
uint32_t color)
{
    if (!img || !origin)
        return;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            img[i + origin->y][j + origin->x] = color;
        }
    }
}