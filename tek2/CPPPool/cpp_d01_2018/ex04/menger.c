/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** menger.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "drawing.h"

int is_nb_valid(char const *str)
{
    if (!str || str[0] == '\0')
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int my_get_nbr(char const *str)
{
    int nb = 0;

    for (int i = 0; str && str[i]; i++)
        nb = nb * 10 + str[i] - '0';
    return (nb);
}

int my_pow(int nb, int power)
{
    int res = 1;

    for (int i = 0; i < power; i++)
        res *= nb;
    return (res);
}

static void do_menger(int size, int level, point_t pos, unsigned int **img)
{
    int next = size / 3;
    point_t next_pos = {pos.x - next * 2, pos.y - next * 2};

    draw_square(img, &pos, size, level);
    if (level > 0) {
        do_menger(next, level - 1, next_pos, img);
        next_pos.y = pos.y + next;
        do_menger(next, level - 1, next_pos, img);
        next_pos.y = pos.y + next * 4;
        do_menger(next, level - 1, next_pos, img);
        next_pos.x = pos.x + next;
        do_menger(next, level - 1, next_pos, img);
        next_pos.y = pos.y - next * 2;
        do_menger(next, level - 1, next_pos, img);
        next_pos.x = pos.x + next * 4;
        do_menger(next, level - 1, next_pos, img);
        next_pos.y = pos.y + next;
        do_menger(next, level - 1, next_pos, img);
        next_pos.y = pos.y + next * 4;
        do_menger(next, level - 1, next_pos, img);
    }
}

void menger(int size, int level, unsigned int **img)
{
    point_t pos = {size / 3, size / 3};

    if (level > 0)
        do_menger(size / 3, level -1, pos, img);
}