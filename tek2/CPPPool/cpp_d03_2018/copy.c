/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** copy.c
*/

#include <stddef.h>
#include "string.h"

size_t copy(const string_t *string, char *str, size_t n, size_t pos)
{
    size_t size = 0;

    if (!string || !string->str || !str)
        return (0);
    while (string->str[pos] && size < n) {
        str[size] = string->str[pos];
        pos++;
        size++;
    }
    if (string->str[pos] == '\0') {
        str[size] = '\0';
        size++;
    }
    return (size);
}