/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** proto.h
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

minicut_t *parse_argument(int ac, char **av);
int get_arg_flag(minicut_t *minicut, char *arg);
int manage_flag(minicut_t *minicut, char *arg);
void display_minicut(minicut_t *minicut);
void display(minicut_t *minicut, char *str);
int manage_numbers_list(minicut_t *minicut, char *arg);

/* action_flag.c */
int flag_del_arg(minicut_t *minicut, char *arg);
int flag_field(minicut_t *minicut);
int flag_field_arg(minicut_t *minicut, char *arg);
int flag_char(minicut_t *minicut);
int flag_char_arg(minicut_t *minicut, char *arg);

/* utils_string.c */
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *str);
char *my_strcat(char *s1, char *s2);

/* utils_int.c */
int my_get_nbr(char *str);
int my_get_second_nbr(char *str);
int is_nb_valid(char *str);
int is_duo_nb_valid(char *str);
char *int_to_str(int nb);

/* utils_memory.c */
void my_free(void *ptr);
void my_free_tab(char **tab);
int my_tab_len(char **tab);

/* utils_display.c */
void my_putstr(char *str);
void my_put_err(char *str);
void my_put_nb(int nb);
void my_put_tab(char **tab);

/* other_utils */
char *get_next_line(int fd);
char **str_to_tab(char *str, char *sep);

#endif	/* PROTO_H_ */
