/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** myftp.h
*/


#ifndef NWP_MYFTP_2018_MYFTP_H
# define NWP_MYFTP_2018_MYFTP_H

# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>

# define MAX_QUEUE  5

typedef struct connection_s {
    int fd;
    struct sockaddr_in client;
    int auth;
    struct connection_s *next;
    struct connection_s *prev;
} connection_t;

typedef struct my_ftp_s {
    int socket_fd;
    char *path;
    fd_set active_fd_set;
    fd_set read_fd_set;
    connection_t *first;
    connection_t *last;
} my_ftp_t;

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

int my_main(int ac, const char **av);
int my_ftp(int port, const char *path);
int start_ftp(int socket_fd, const char *path);
my_ftp_t *create_ftp(int socket_fd, const char *path);
void destroy_ftp(my_ftp_t *ftp);
void add_connection(my_ftp_t *ftp, struct sockaddr_in client, int fd);
void close_connection(my_ftp_t *ftp, int fd);
connection_t *search_connection(my_ftp_t *ftp, int fd);
void send_message(int fd, int code, const char *message);
bool_t compare_message(const char *message, const char *cmd);
void parse_messages(connection_t *connection, const char *message);

#endif /* NWP_MYFTP_2018_MYFTP_H */
