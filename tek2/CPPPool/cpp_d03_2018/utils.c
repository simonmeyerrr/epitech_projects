/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** my_utils.c
*/

#include <stdlib.h>

void my_free(void *ptr)
{
    if (ptr)
        free(ptr);
}

int my_strlen(char const *str)
{
    int len = 0;

    while (str && str[len])
        len++;
    return (len);
}

char *my_strdup(char const *str)
{
    char *new_str;
    int len = my_strlen(str);

    if (!str)
        return (NULL);
    new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (NULL);
    for (int i = 0; str[i]; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return (new_str);
}

char *my_append(char const *str1, char const *str2)
{
    int i = 0;
    int len = my_strlen(str1) + my_strlen(str2) + 1;
    char *new_str = malloc(sizeof(char) * len);

    if (!new_str)
        return (NULL);
    for (int j = 0; str1 && str1[j]; j++) {
        new_str[i] = str1[j];
        i++;
    }
    for (int j = 0; str2 && str2[j]; j++) {
        new_str[i] = str2[j];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}