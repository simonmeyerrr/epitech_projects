/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** main.c
*/

#include <stdio.h>
#include "../include/my_chap.h"

static bool_t is_valid(const char *str)
{
    int i = 0;

    while (str && str[i] >= '0' && str[i] <= '9')
        i++;
    if (i == 0 || !str || str[i] != '\0')
        return (FALSE);
    return (TRUE);
}

int main(int ac, const char **av)
{
    args_t *args = get_args(ac, av);
    if (!args)
        return (84);
    if (!is_valid(args->port)) {
        dprintf(2, "Invalid port\n");
        delete_args(args);
        return (84);
    }
    create_client(args);
    delete_args(args);
    return (0);
}