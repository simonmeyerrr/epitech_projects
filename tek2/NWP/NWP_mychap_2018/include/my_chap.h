/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** my_chap.h
*/

#ifndef NWP_MYCHAP_2018_MY_CHAP_H
# define NWP_MYCHAP_2018_MY_CHAP_H

typedef struct args_s {
    char *target;
    char *port;
    char *password;
} args_t;

void delete_args(args_t *args);
args_t *get_args(int ac, const char **av);

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

void create_client(args_t *args);

#endif /* NWP_MYCHAP_2018_MY_CHAP_H */
