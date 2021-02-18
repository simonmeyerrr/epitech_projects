/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** get_args.c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my_chap.h"

static args_t *init_args(void)
{
    args_t *args = malloc(sizeof(args_t));

    if (!args)
        return (NULL);
    args->target = NULL;
    args->port = NULL;
    args->password = NULL;
    return (args);
}

void delete_args(args_t *args)
{
    if (!args)
        return;
    if (args->password)
        free(args->password);
    if (args->target)
        free(args->target);
    if (args->port)
        free(args->port);
    free(args);
}

static int manage_arg(const char **av, int i, args_t *args)
{
    if (!strcmp("-t", av[i]) || !strcmp("--target", av[i])) {
        if (args->target)
            free(args->target);
        args->target = strdup(av[i + 1]);
        return (1);
    }
    if (!strcmp("-p", av[i]) || !strcmp("--port", av[i])) {
        if (args->port)
            free(args->port);
        args->port = strdup(av[i + 1]);
        return (1);
    }
    if (!strcmp("-P", av[i]) || !strcmp("--password", av[i])) {
        if (args->password)
            free(args->password);
        args->password = strdup(av[i + 1]);
        return (1);
    }
    return (0);
}

args_t *get_args(int ac, const char **av)
{
    args_t *args = (ac - 1) % 2 != 0 ? NULL : init_args();
    int valid;

    if (!args)
        return (NULL);
    for (int i = 1; i < ac; i += 2) {
        valid = manage_arg(av, i, args);
        if (!valid) {
            delete_args(args);
            return (NULL);
        }
    }
    if (!args->password || !args->target || !args->port) {
        delete_args(args);
        return (NULL);
    }
    return (args);
}