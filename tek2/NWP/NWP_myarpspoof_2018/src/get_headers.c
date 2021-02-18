/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** broadcast_header.c
*/

#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "myarpspoof.h"

struct ether_header *get_ether_header(args_t *args)
{
    struct ether_header *header = malloc(sizeof(struct ether_arp));

    if (!header)
        return (NULL);
    if (!put_mac_to_nb((void *)&(header->ether_shost), args->my_mac) ||
        !put_mac_to_nb((void *)&(header->ether_dhost), args->spoof_mac)) {
        free(header);
        return (NULL);
    }
    header->ether_type = 0x0608;
    return (header);
}

struct ether_arp *get_ether_arp(args_t *args, bool_t broadcast)
{
    struct ether_arp *header = malloc(sizeof(struct ether_arp));

    if (!header)
        return (NULL);
    if (!put_mac_to_nb((void *)&(header->arp_sha), args->my_mac) ||
        !put_mac_to_nb((void *)&(header->arp_tha), args->spoof_mac) ||
        !put_ip_to_nb((void *)&(header->arp_spa), args->sender_ip) ||
        !put_ip_to_nb((void *)&(header->arp_tpa), args->target_ip)) {
        free(header);
        return (NULL);
    }
    header->ea_hdr.ar_hrd = htons(ARPHRD_ETHER);
    header->ea_hdr.ar_pro = htons(ETH_P_IP);
    header->ea_hdr.ar_hln = ETHER_ADDR_LEN;
    header->ea_hdr.ar_pln = sizeof(in_addr_t);
    header->ea_hdr.ar_op = htons(broadcast ? ARPOP_REQUEST : ARPOP_REPLY);
    return (header);
}

int print_broadcast(args_t *args)
{
    struct ether_header *header = get_ether_header(args);
    struct ether_arp *header_arp = header ? get_ether_arp(args, TRUE) : NULL;

    if (!header)
        return (84);
    if (!header_arp) {
        free(header);
        return (84);
    }
    for (unsigned int i = 0; i < sizeof(*header); i++) {
        print_hexa(((unsigned char *)header)[i]);
        write(1, " ", 1);
    }
    for (unsigned int i = 0; i < sizeof(*header_arp); i++) {
        print_hexa(((unsigned char *)header_arp)[i]);
        write(1, (i != sizeof(*header_arp) - 1) ? " " : "\n", 1);
    }
    free(header);
    free(header_arp);
    return (0);
}

int print_spoof(args_t *args)
{
    struct ether_header *header = get_ether_header(args);
    struct ether_arp *header_arp = header ? get_ether_arp(args, FALSE) : NULL;

    if (!header)
        return (84);
    if (!header_arp) {
        free(header);
        return (84);
    }
    for (unsigned int i = 0; i < sizeof(*header); i++) {
        print_hexa(((unsigned char *)header)[i]);
        write(1, " ", 1);
    }
    for (unsigned int i = 0; i < sizeof(*header_arp); i++) {
        print_hexa(((unsigned char *)header_arp)[i]);
        write(1, (i != sizeof(*header_arp) - 1) ? " " : "\n", 1);
    }
    free(header);
    free(header_arp);
    return (0);
}