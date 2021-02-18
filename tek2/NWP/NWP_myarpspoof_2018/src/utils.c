/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** utils.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_hexa(unsigned char nb)
{
    const char *chars = "0123456789abcdef";
    unsigned char cpy = nb;

    nb = nb / 16;
    write(1, &chars[nb], 1);
    write(1, &chars[cpy - (nb * 16)], 1);
}

char *str_append(const char *str1, const char *str2)
{
    char *str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    int i = 0;

    if (!str)
        return (NULL);
    for (; str1 && str1[i]; i++)
        str[i] = str1[i];
    for (int j = 0; str2 && str2[j]; j++) {
        str[i] = str2[j];
        i++;
    }
    str[i] = '\0';
    return (str);
}