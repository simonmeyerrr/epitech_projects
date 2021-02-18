/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** get_ip.c
*/

#include <stdio.h>
#include "../include/myarpspoof.h"

static unsigned char get_ip_value(const char *str, int *i)
{
    unsigned char nb = 0;

    while (str && str[*i] >= '0' && str[*i] <= '9') {
        nb = nb * 10 + str[*i] - '0';
        *i = *i + 1;
    }
    if (str && str[*i] != '\0')
        *i = *i + 1;
    return (nb);
}

bool_t put_ip_to_nb(unsigned char *ptr, const char *str)
{
    int i = 0;

    if (!ptr)
        return (FALSE);
    for (unsigned int j = 0; j < 4; ++j) {
        ptr[j] = get_ip_value(str, &i);
    }
    return (TRUE);
}