/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** ex00.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *cthulhu)
{
    cthulhu->m_power = 42;
    cthulhu->m_name = strdup("Cthulhu");
    printf("----\nBuilding %s\n", cthulhu->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *cthulhu = malloc(sizeof(cthulhu_t));

    if (!cthulhu)
        return (NULL);
    cthulhu_initializer(cthulhu);
    return (cthulhu);
}

void print_power(cthulhu_t *cthulhu)
{
    printf("Power => %d\n", cthulhu->m_power);
}

void attack(cthulhu_t *cthulhu)
{
    if (cthulhu->m_power >= 42) {
        cthulhu->m_power -= 42;
        printf("%s attacks and destroys the city\n", cthulhu->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n",
            cthulhu->m_name);
    }
}

void sleeping(cthulhu_t *cthulhu)
{
    printf("%s sleeps\n", cthulhu->m_name);
    cthulhu->m_power += 42000;
}

static void koala_initializer(koala_t *koala, char *name, char is_a_legend)
{
    koala->m_is_a_legend = is_a_legend;
    if (is_a_legend)
        koala->m_parent.m_power = 42;
    else
        koala->m_parent.m_power = 0;
    koala->m_parent.m_name = name;
    printf("----\nBuilding %s\nBuilding %s\n", "Cthulhu", name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *koala = malloc(sizeof(koala_t));

    if (!koala)
        return (NULL);
    koala_initializer(koala, name, is_a_legend);
    return (koala);
}

void eat(koala_t *koala)
{
    printf("%s eats\n", koala->m_parent.m_name);
    koala->m_parent.m_power += 42;
}