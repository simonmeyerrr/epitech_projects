/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** mem_ptr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "mem_ptr.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str && str[i]; i++)
        len++;
    return (len);
}

void add_str(const char *str1, const char *str2, char **res)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));

    if (!str)
        return;
    for (int j = 0; str1 && str1[j]; j++) {
        str[i] = str1[j];
        i++;
    }
    for (int j = 0; str2 && str2[j]; j++) {
        str[i] = str2[j];
        i++;
    }
    str[i] = '\0';
    *res = str;
}

void add_str_struct(str_op_t *str_op)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(str_op->str1) +
        my_strlen(str_op->str2) + 1));

    if (!str)
        return;
    for (int j = 0; str_op->str1 && str_op->str1[j]; j++) {
        str[i] = str_op->str1[j];
        i++;
    }
    for (int j = 0; str_op->str2 && str_op->str2[j]; j++) {
       str[i] = str_op->str2[j];
        i++;
    }
    str[i] = '\0';
    str_op->res = str;
}