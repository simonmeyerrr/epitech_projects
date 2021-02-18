/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** drawing.c
*/

#include "drawing.h"

static uint32_t get_color_to_draw(int level)
{
    uint32_t color;
    void *ptr = &color;
    unsigned char *tab = ptr;

    tab[0] = 255 / (level + 1);
    tab[1] = 255 / (level + 1);
    tab[2] = 255 / (level + 1);
    tab[3] = 0;
    return (color);
}

void draw_square(uint32_t **img, const point_t *origin, size_t size,
int level)
{
    uint32_t color = get_color_to_draw(level);

    if (!img || !origin)
        return;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            img[i + origin->y][j + origin->x] = color;
        }
    }
}