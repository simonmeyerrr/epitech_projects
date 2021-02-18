/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** compare.c
*/

#include "string.h"

int compare_s(const string_t *s1, const string_t *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (-1);
    if (!s1->str || s2->str)
        return (-1);
    while (s1->str[i] && s2->str[i] && s1->str[i] == s2->str[i])
        i++;
    return (s1->str[i] - s2->str[i]);
}

int compare_c(const string_t *string, const char *str)
{
    int i = 0;

    if (!string || !string->str || !str)
        return (-1);
    while (string->str[i] && str[i] && string->str[i] == str[i])
        i++;
    return (string->str[i] - str[i]);
}