/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/myarpspoof.h"

static int my_arp(args_t *args)
{
    if (!get_if_index(args)) {
        dprintf(2, "can't get if index\n");
        return (84);
    }
    args->my_mac = get_mac_address(args);
    if (!args->my_mac) {
        dprintf(2, "can't get mac address\n");
        return (84);
    }
    if (args->mode == PRINT_BROADCAST)
        return (print_broadcast(args));
    else if (args->mode == PRINT_SPOOF)
        return (print_spoof(args));
    else
        return (do_arp(args));
}

int main(int ac, const char **av)
{
    args_t *args = get_args(ac, av);
    int ret = 0;

    if (!args) {
        dprintf(2, "Invalid arguments.\n");
        return (84);
    }
    ret = my_arp(args);
    delete_args(args);
    return (ret);
}