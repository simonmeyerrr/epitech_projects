/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** myarpspoof.h
*/

#ifndef NWP_MYARPSPOOF_2018_MYARPSPOOF_H
# define NWP_MYARPSPOOF_2018_MYARPSPOOF_H

#include <netinet/if_ether.h>
#include <linux/if_packet.h>

#define SPOOF_LOOP 100

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

typedef enum {
    NORMAL = 0,
    PRINT_BROADCAST = 1,
    PRINT_SPOOF = 2
} arp_mode_t;

typedef struct args_s {
    char *sender_ip;
    char *target_ip;
    char *interface;
    arp_mode_t mode;
    char *spoof_mac;
    char *my_mac;
    int index;
    struct sockaddr_ll sock;
    unsigned char target_mac[6];
} args_t;

args_t *delete_args(args_t *args);
args_t *create_args(void);
args_t *get_args(int ac, const char **av);

bool_t is_mac_valid(const char *str);
bool_t put_mac_to_nb(unsigned char *ptr, const char *str);
char *get_mac_address(args_t *args);
bool_t get_if_index(args_t *args);

bool_t put_ip_to_nb(unsigned char *ptr, const char *str);

int print_broadcast(args_t *args);
int print_spoof(args_t *args);

void print_hexa(unsigned char nb);
char *str_append(const char *str1, const char *str2);

struct ether_arp *get_ether_arp(args_t *args, bool_t broadcast);
struct ether_header *get_ether_header(args_t *args);

int do_arp(args_t *args);

#endif /* NWP_MYARPSPOOF_2018_MYARPSPOOF_H */
