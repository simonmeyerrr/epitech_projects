/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** proto.h
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

void parse_argument(my_mixword_t *mixword, int ac, char **av);
void algo_to_mixword(my_mixword_t *mixword);
void display_mixword(my_mixword_t *mixword);
my_mixword_t *init_mixword(int ac, char **av);
void display_help(void);

/* utils_string.c */
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *str);
char *my_strcat(char *s1, char *s2);

/* utils_int.c */
int my_get_nbr(char *str);
int is_nb_valid(char *str);
char *int_to_str(int nb);

/* utils_memory.c */
void my_free(void *ptr);
void my_free_tab(char **tab);
int my_tab_len(char **tab);
void verif_malloc(void *ptr);

/* utils_display.c */
void my_putstr(char *str);
void my_put_err(char *str);
void my_put_nb(int nb);
void my_put_tab(char **tab);
void my_exit(char *str);

/* other_utils */
char *get_next_line(int fd);
char **str_to_tab(char *str, char *sep);
char my_getopt(my_flag_t *flags, char **str, int ac, char **av);
char get_long_flag(my_getopt_t getopt, int len);

#endif	/* PROTO_H_ */
