/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** myftp.c
*/

#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "myftp.h"

static int create_socket(void)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 6);

    if (socket_fd == -1) {
        dprintf(2, "Failed to open socket: %s\n", strerror(errno));
        return (-1);
    }
    return (socket_fd);
}

static int bind_socket(int port, int socket_fd)
{
    struct sockaddr_in server_address;
    size_t size;

    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    size = sizeof(server_address);
    if (bind(socket_fd, (struct sockaddr *)&server_address, size) == -1) {
        dprintf(2, "Failed to bind socket: %s\n", strerror(errno));
        return (-1);
    } else if (listen(socket_fd, MAX_QUEUE) == -1) {
        dprintf(2, "Failed to start listening: %s\n", strerror(errno));
        return (-1);
    }
    return (0);
}

int my_ftp(int port, const char *path)
{
    int socket_fd = create_socket();

    if (socket_fd == -1) {
        return (84);
    }
    if (bind_socket(port, socket_fd) == -1) {
        close(socket_fd);
        return (84);
    } else if (start_ftp(socket_fd, path) == -1) {
        close(socket_fd);
        return (84);
    } else {
        close(socket_fd);
        return (0);
    }
}