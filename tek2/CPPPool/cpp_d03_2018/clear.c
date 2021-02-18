/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** clear.c
*/

#include "string.h"

void clear(string_t *string)
{
    if (!string)
        return;
    my_free(string->str);
    string->str = my_strdup("");
}