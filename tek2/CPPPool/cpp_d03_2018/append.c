/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** append.c
*/

#include "string.h"

void append_s(string_t *dest, const string_t *str)
{
    char *tmp;

    if (!dest || !str)
        return;
    tmp = dest->str;
    dest->str = my_append(dest->str, str->str);
    my_free(tmp);
}

void append_c(string_t *dest, const char *str)
{
    char *tmp;

    if (!dest)
        return;
    tmp = dest->str;
    dest->str = my_append(dest->str, str);
    my_free(tmp);
}
