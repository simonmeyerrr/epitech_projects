/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** drawing.h
*/

#ifndef CPP_D01_2018_DRAWING_H
#define CPP_D01_2018_DRAWING_H

#include <stdint.h>
#include <stddef.h>

typedef struct point {
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size,
uint32_t color);

#endif //CPP_D01_2018_DRAWING_H
