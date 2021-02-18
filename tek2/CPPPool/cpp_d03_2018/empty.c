/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** empty.c
*/

#include "string.h"

int empty(const string_t *string)
{
    if (!string || !string->str || my_strlen(string->str) == 0)
        return (1);
    return (0);
}