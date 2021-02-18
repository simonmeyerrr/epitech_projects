/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** tab_to_2dtab.c
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **new_tab = malloc(sizeof(int*) * length);

    if (!new_tab)
        return;
    for (int j = 0; j < length; j++) {
        new_tab[j] = malloc(sizeof(int) * width);
        if (!new_tab[j])
            return;
        for (int i = 0; i < width; i++)
            new_tab[j][i] = tab[(j * width) + i];
    }
    *res = new_tab;
}