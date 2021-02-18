/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** size.c
*/

#include "string.h"

int size(const string_t *string)
{
    if (!string || !string->str)
        return (-1);
    return (my_strlen(string->str));
}