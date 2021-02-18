/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** message.c
*/

#include <stdio.h>
#include "myftp.h"

void send_message(int fd, int code, const char *message)
{
    printf("<- %d %s\n", code, message);
    dprintf(fd, "%d %s\r\n", code, message);
}

int my_strlen(const char *cmd)
{
    int len = 0;

    while (cmd && cmd[len])
        len++;
    return (len);
}

bool_t compare_message(const char *message, const char *cmd)
{
    int i = 0;

    if (!message || !cmd)
        return (FALSE);
    if (my_strlen(message) < my_strlen(cmd))
        return (FALSE);
    while (message && cmd && message[i] && cmd[i] && message[i] == cmd[i])
        i++;
    if (i < my_strlen(cmd))
        return (FALSE);
    if (message[i] <= 32)
        return (TRUE);
    return (FALSE);
}

static void parse_messages_two(connection_t *connection, const char *message)
{
    if (compare_message(message, "PASS")) {
        if (connection->auth == 1) {
            send_message(connection->fd, 230, "logged in");
            connection->auth = 3;
        } else {
            send_message(connection->fd, 332, "oups");
        }
        return;
    }
    if (compare_message(message, "PWD")) {
        if (connection->auth == 3) {
            send_message(connection->fd, 257, "/");
        } else {
            send_message(connection->fd, 530, "/");
        }
        return;
    }
    send_message(connection->fd, 500, "pas bonne cmd");
}

void parse_messages(connection_t *connection, const char *message)
{
    if (compare_message(message, "NOOP")) {
        if (connection->auth == 3) {
            send_message(connection->fd, 200, "Noop");
        } else {
            send_message(connection->fd, 530, "Noop");
        }
        return;
    }
    if (compare_message(message, "USER")) {
        if (compare_message(message, "USER Anonymous")) {
            connection->auth = 1;
            send_message(connection->fd, 230, "good");
        } else {
            connection->auth = 2;
            send_message(connection->fd, 230, "not good");
        }
        return;
    }
    parse_messages_two(connection, message);
}