/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** my_main.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

static void print_help(int fd, const char *cmd)
{
    dprintf(fd, "USAGE:  %s port path\n", cmd);
    dprintf(fd, "        %s\n",
        "port is the port number on which the server socket listens");
    dprintf(fd, "        %s\n",
        "path is the path to the home directory for the Anonymous user");
}

static bool_t is_nb_valid(const char *str)
{
    int i = 0;

    while (str && str[i] >= '0' && str[i] <= '9')
        i++;
    return (i == 0 || str[i] != '\0' ? FALSE : TRUE);
}

int main(int ac, const char **av)
{
    if (ac == 0)
        return (84);
    if (ac == 2 && !strcmp(av[1], "-help")) {
        print_help(1, av[0]);
        return (0);
    }
    if (ac != 3 || !is_nb_valid(av[1])) {
        print_help(2, av[0]);
        return (84);
    }
    return (my_ftp(atoi(av[1]), av[2]));
}