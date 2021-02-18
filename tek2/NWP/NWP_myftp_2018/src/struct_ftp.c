/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** struct_ftp.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

my_ftp_t *create_ftp(int socket_fd, const char *path)
{
    my_ftp_t *ftp = malloc(sizeof(my_ftp_t));

    if (!ftp)
        return (NULL);
    ftp->socket_fd = socket_fd;
    ftp->first = NULL;
    ftp->last = NULL;
    ftp->path = strdup(path);
    if (!ftp->path) {
        free(ftp);
        return (NULL);
    }
    return (ftp);
}

void destroy_ftp(my_ftp_t *ftp)
{
    if (!ftp)
        return;
    while (ftp->first)
        close_connection(ftp, ftp->first->fd);
    if (ftp->path)
        free(ftp->path);
    free(ftp);
}

void add_connection(my_ftp_t *ftp, struct sockaddr_in client, int fd)
{
    connection_t *connection = malloc(sizeof(connection_t));

    if (!connection) {
        close(fd);
        return;
    }
    connection->fd = fd;
    connection->client = client;
    connection->auth = 0;
    connection->next = NULL;
    connection->prev = ftp->last;
    if (ftp->last)
        ftp->last->next = connection;
    else
        ftp->first = connection;
    ftp->last = connection;
    FD_SET(fd, &(ftp->active_fd_set));
    printf("Connection Establishment %s:%hd\n", inet_ntoa(client.sin_addr),
        ntohs(client.sin_port));
    dprintf(fd, "220 Service ready for new user.\r\n");
}

void close_connection(my_ftp_t *ftp, int fd)
{
    connection_t *connection = search_connection(ftp, fd);

    if (!connection)
        return;
    close(fd);
    FD_CLR(fd, &(ftp->active_fd_set));
    if (connection->next)
        connection->next->prev = connection->prev;
    else
        ftp->last = connection->prev;
    if (connection->prev)
        connection->prev->next = connection->next;
    else
        ftp->first = connection->next;
}

connection_t *search_connection(my_ftp_t *ftp, int fd)
{
    for (connection_t *tmp = ftp->first; tmp; tmp = tmp->next) {
        if (tmp->fd == fd)
            return (tmp);
    }
    return (NULL);
}