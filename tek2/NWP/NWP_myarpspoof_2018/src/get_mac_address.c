/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** get_mac_address.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../include/myarpspoof.h"

bool_t is_mac_valid(const char *str)
{
    if (!str || strlen(str) != 17)
        return (FALSE);
    for (int i = 0; str[i]; i++) {
        if (i % 3 == 2 && str[i] != ':')
            return (FALSE);
        else if (i % 3 != 2 &&
            (str[i] < '0' || (str[i] > '9' && str[i] < 'a') || str[i] > 'f'))
            return (FALSE);
    }

    return (TRUE);
}

unsigned char get_hex_value(char c, int place)
{
    const char *chars = "0123456789abcdef";

    for (unsigned int i = 0; i < strlen(chars); i++) {
        if (c == chars[i] && place == 0)
            return (i);
        else if (c == chars[i])
            return ((unsigned char)i * 16);
    }
    return (0);
}

bool_t put_mac_to_nb(unsigned char *ptr, const char *str)
{
    if (str && is_mac_valid(str) == FALSE)
        return (FALSE);
    if (!ptr)
        return (FALSE);
    for (unsigned int i = 0; str && i < strlen(str); i += 3)
        ptr[i / 3] = get_hex_value(str[i], 1) + get_hex_value(str[i + 1], 0);
    for (unsigned int i = 0; i < 6 && !str; ++i)
        ptr[i] = 255;
    return (TRUE);
}

char *get_mac_address(args_t *args)
{
    char buffer[18];
    char *s1 = str_append("/sys/class/net/", args->interface);
    char *s2 = str_append(s1, "/address");
    int fd = open(s2, O_RDONLY);

    free(s1);
    free(s2);
    buffer[17] = '\0';
    if (fd == -1)
        return (NULL);
    if (read(fd, buffer, 17) != 17) {
        close(fd);
        return (NULL);
    }
    close(fd);
    return (strdup(buffer));
}

bool_t get_if_index(args_t *args)
{
    char buffer[4];
    int size;
    char *s1 = str_append("/sys/class/net/", args->interface);
    char *s2 = str_append(s1, "/ifindex");
    int fd = open(s2, O_RDONLY);

    free(s1);
    free(s2);
    if (fd == -1)
        return (FALSE);
    size = read(fd, buffer, 3);
    if (size <= 0) {
        close(fd);
        return (FALSE);
    }
    buffer[size] = '\0';
    args->index = atoi(buffer);
    close(fd);
    return (TRUE);
}