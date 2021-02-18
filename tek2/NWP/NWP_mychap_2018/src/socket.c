/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** socket.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../include/my_chap.h"

static int create_socket(void)
{
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    int option = 1;

    if (socket_fd == -1) {
        dprintf(2, "Failed to open socket: %s\n", strerror(errno));
        return (-1);
    }
    if (setsockopt(socket_fd, IPPROTO_IP, IP_HDRINCL, &option,
        sizeof(option)) == -1) {
        close(socket_fd);
        dprintf(2, "Failed to set socket options: %s\n", strerror(errno));
        return (-1);
    }
    return (socket_fd);
}

static int connect_socket(int socket_fd, args_t *args)
{
    struct sockaddr_in server_sock_addr;
    struct hostent *host = gethostbyname(args->target);

    if (!host) {
        dprintf(2, "No such hostname: '%s'\n", args->target);
        return (-1);
    }
    memcpy(&server_sock_addr.sin_addr, &host->h_addr_list[0], sizeof(host->h_length));
    server_sock_addr.sin_port = htons(atoi(args->port));
    server_sock_addr.sin_family = AF_INET;
    if (connect(socket_fd, (struct sockaddr *)&server_sock_addr,
        sizeof(server_sock_addr)) == -1) {
        dprintf(2, "Failed to connect: %s\n", strerror(errno));
        return (-1);
    }
    return (0);
}

void create_client(args_t *args)
{
    int socket_fd = create_socket();

    if (socket_fd == -1)
        return;
    if (connect_socket(socket_fd, args) == -1) {
        close(socket_fd);
        return;
    }
    close(socket_fd);
}