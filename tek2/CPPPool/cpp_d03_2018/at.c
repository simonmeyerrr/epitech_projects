/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** at.c
*/

#include <stddef.h>
#include "string.h"

char at(const string_t *string, size_t pos)
{
    if (!string)
        return (-1);
    if (pos >= (size_t)my_strlen(string->str))
        return (-1);
    return (string->str[pos]);
}