/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** assign.c
*/

#include <unistd.h>
#include "string.h"

void assign_s(string_t *dest, const string_t *str)
{
    if (!str || !dest)
        return;
    my_free(dest->str);
    dest->str = my_strdup(str->str);
}

void assign_c(string_t *dest, const char *str)
{
    if (!dest)
        return;
    my_free(dest->str);
    dest->str = my_strdup(str);
}