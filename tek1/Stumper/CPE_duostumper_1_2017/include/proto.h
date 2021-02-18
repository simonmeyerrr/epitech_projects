/*
** EPITECH PROJECT, 2017
** head
** File description:
** proto.h
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

/* call in main.c */
argument_t *parse_argument(int ac, char **av);
void display_file(argument_t *arg);

/* detect_special_arg.c */
int get_value_arg(argument_t *arg, char *str);
int get_simple_arg(argument_t *arg, char c);
int get_long_arg(argument_t *arg, char *str);
int get_special_arg(argument_t *arg, char *str);
int get_value_arg_spe(argument_t *arg, char *str);

/* util string.c */
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
int my_get_nbr(char *str);

/* get_next_line.c */
void my_putstr(char *str);
void my_put_error(char *str);
void my_free(void *ptr);
char *get_next_line(int fd);

#endif	/* PROTO_H_ */
