/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** get_args.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "../include/myarpspoof.h"

args_t *delete_args(args_t *args)
{
    if (!args)
        return (NULL);
    if (args->sender_ip)
        free(args->sender_ip);
    if (args->target_ip)
        free(args->target_ip);
    if (args->interface)
        free(args->interface);
    if (args->spoof_mac)
        free(args->spoof_mac);
    if (args->my_mac)
        free(args->my_mac);
    free(args);
    return (NULL);
}

args_t *create_args(void)
{
    args_t *args = malloc(sizeof(args_t));

    if (!args)
        return (NULL);
    args->sender_ip = NULL;
    args->target_ip = NULL;
    args->interface = NULL;
    args->mode = NORMAL;
    args->spoof_mac = NULL;
    args->my_mac = NULL;
    args->index = 0;
    args->sock.sll_family = AF_PACKET;
    args->sock.sll_family = AF_PACKET;
    args->sock.sll_protocol = htons(ETH_P_ARP);
    args->sock.sll_hatype = htons(ARPHRD_ETHER);
    args->sock.sll_pkttype = (PACKET_BROADCAST);
    args->sock.sll_halen = 6;
    args->sock.sll_addr[6] = 0x00;
    args->sock.sll_addr[7] = 0x00;
    return (args);
}

args_t *get_args(int ac, const char **av)
{
    args_t *args = create_args();

    if (!args)
        return (NULL);
    if (ac != 4 && ac != 5 && ac != 6)
        return (delete_args(args));
    args->sender_ip = strdup(av[1]);
    args->target_ip = strdup(av[2]);
    args->interface = strdup(av[3]);
    if (ac == 5 && strcmp(av[4], "--printBroadcast") == 0)
        args->mode = PRINT_BROADCAST;
    if (ac == 6 && strcmp(av[4], "--printSpoof") == 0) {
        args->mode = PRINT_SPOOF;
        args->spoof_mac = strdup(av[5]);
    }
    if (ac != 4 && args->mode == NORMAL)
        return (delete_args(args));
    return (args);
}