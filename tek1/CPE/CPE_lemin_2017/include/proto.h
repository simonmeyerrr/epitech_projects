/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

/* string.c */
int my_strlen(char *str);
int my_get_nbr(char *str);
void my_putstr_fd(char *str, int fd);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);
char *get_next_line(int fd);
char **str_to_tab(char *str);
int is_nb_valid(char *str);
void init_tunnel(global_t *global);
void my_put_nbr(int nb);

/* memory.c */
int verif_malloc(void *ptr);
void my_free(void *ptr);
void my_free_tab(char **tab);
int my_tab_len(char **tab);

/* call in main.c */
global_t *init_global(void);
void search_path(global_t *global);
void display_result(global_t *global);
void loop_display(int *tab_length, int *tab_ants, int *tab_way, room_t **room);
void my_free_global(global_t *global);

void get_info_input(global_t *global, input_t *input, int *error);
void init_room(global_t *global);
void init_tunnel(global_t *global);
void add_tunnel_to_room(global_t *global);

#endif	/* PROTO_H_ */
