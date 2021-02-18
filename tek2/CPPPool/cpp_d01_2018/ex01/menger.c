/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** menger.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

void do_menger(int size, int level, int x, int y)
{
    int next = size / 3;

    printf("%03d %03d %03d\n", size, x, y);
    if (level > 0) {
        do_menger(next, level - 1, x - next * 2, y - next * 2);
        do_menger(next, level - 1, x - next * 2, y + next);
        do_menger(next, level - 1, x - next * 2, y + next * 4);
        do_menger(next, level - 1, x + next, y - next * 2);
        do_menger(next, level - 1, x + next, y + next * 4);
        do_menger(next, level - 1, x + next * 4, y - next * 2);
        do_menger(next, level - 1, x + next * 4, y + next);
        do_menger(next, level - 1, x + next * 4, y + next * 4);
    }
}

void menger(int size, int level)
{
    if (level > 0)
        do_menger(size / 3, level - 1, size / 3, size / 3);
}