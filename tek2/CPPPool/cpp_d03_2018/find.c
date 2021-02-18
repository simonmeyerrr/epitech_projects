/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** find.c
*/

#include "string.h"

static int str_has_prefix(char const *str1, char const *str2)
{
    if (my_strlen(str2) > my_strlen(str1))
        return (0);
    for (int i = 0; str2[i]; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}

int find_s(const string_t *s1, const string_t *s2, size_t pos)
{
    int res = 1;
    int i;

    if (!s1 || !s2 || !s1->str || !s2->str)
        return (-1);
    for (i = 0; i + (int)pos < my_strlen(s1->str) && res != 0; i++)
        res = str_has_prefix(s1->str + i + pos, s2->str);
    if (res == 0)
        return (i);
    return (-1);
}

int find_c(const string_t *string, const char *str, size_t pos)
{
    int res = 1;
    int i;

    if (!string || !string->str || !str)
        return (-1);
    for (i = 0; i + (int)pos < my_strlen(string->str) && res != 0; i++)
        res = str_has_prefix(string->str + i + pos, str);
    if (res == 0)
        return (i);
    return (-1);
}