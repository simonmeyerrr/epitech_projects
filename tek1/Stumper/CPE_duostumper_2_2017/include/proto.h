/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** proto.h
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

ginger_t *init_ginger(int ac, char **av);
void display_ginger(ginger_t *ginger);
void move_ginger(ginger_t *ginger);
char **str_to_tab(char *str, char *sep);
void verif_malloc(void *ptr);
void parse_argument(ginger_t *ginger, int ac, char **av);
int my_strlen(char *str);
void my_free(void *ptr);
void move_on_map(ginger_t *ginger, int x, int y);
int get_total_distance(ginger_t *ginger, position_t *pos);

#endif	/* PROTO_H_ */
