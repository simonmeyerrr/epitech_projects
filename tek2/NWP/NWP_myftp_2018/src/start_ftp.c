/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** start_ftp.c
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

static int manage_message(my_ftp_t *ftp, int fd, char *message)
{
    connection_t *connection = search_connection(ftp, fd);

    if (!connection || compare_message(message, "QUIT")) {
        send_message(fd, 221, "Service closing control connection");
        return (-1);
    } else if (compare_message(message, "HELP")) {
        send_message(fd, 214, "I can help you");
        return (0);
    } else {
        parse_messages(connection, message);
        return (0);
    }
}

static int communicate(my_ftp_t *ftp, int fd)
{
    char buffer[1024];
    int nbytes;

    memset(buffer, '\0', 1024);
    nbytes = read(fd, buffer, 1023);
    if (nbytes < 0) {
        dprintf(2, "Failed to read: %s\n", strerror(errno));
        return (-1);
    } else if (nbytes == 0) {
        return (-1);
    } else {
        printf("-> %s", buffer);
        return (manage_message(ftp, fd, buffer));
    }
}

static int loop_accept(my_ftp_t *ftp)
{
    struct sockaddr_in client;
    socklen_t size = sizeof(client);
    int new_fd;

    for (int fd = 0; fd < FD_SETSIZE; ++fd) {
        if (!FD_ISSET(fd, &(ftp->read_fd_set)))
            continue;
        if (fd == ftp->socket_fd) {
            new_fd = accept(ftp->socket_fd, (struct sockaddr *)&client, &size);
            if (new_fd == -1)
                return (-1);
            add_connection(ftp, client, new_fd);
        } else if (communicate(ftp, fd) == -1)
            close_connection(ftp, fd);
    }
    return (0);
}

int start_ftp(int socket_fd, const char *path)
{
    my_ftp_t *ftp = create_ftp(socket_fd, path);

    if (!ftp)
        return (-1);
    FD_ZERO(&(ftp->active_fd_set));
    FD_SET(ftp->socket_fd, &(ftp->active_fd_set));
    while (1) {
        ftp->read_fd_set = ftp->active_fd_set;
        if (select(FD_SETSIZE, &(ftp->read_fd_set), NULL, NULL, NULL) < 0) {
            dprintf(2, "Failed to select: %s\n", strerror(errno));
            destroy_ftp(ftp);
            return (-1);
        } else if (loop_accept(ftp) == -1) {
            dprintf(2, "Failed to accept: %s\n", strerror(errno));
            destroy_ftp(ftp);
            return (-1);
        }
    }
}
