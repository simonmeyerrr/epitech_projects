/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** c_star.c
*/

#include "string.h"

const char *c_str(const string_t *string)
{
    if (!string || !string->str)
        return (NULL);
    return (string->str);
}