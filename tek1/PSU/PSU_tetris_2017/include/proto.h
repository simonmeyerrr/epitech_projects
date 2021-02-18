/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

int my_strlen(char *str);
void my_put_nbr(int nb);
void my_putstr_fd(char *str, int fd);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);

void verif_malloc(void *ptr);
void my_free(void *ptr);
void my_free_tab(char **tab);

void parse_argument(int ac, char **av, my_game_t *game);
void get_tetrimino(my_game_t *game);
void play_game(my_game_t *game);
void free_game(my_game_t *game);
void disp_debug(my_game_t *game);

void sort_tab(my_game_t *game);
int tab_sorted(my_game_t *game);

#endif	/* PROTO_H_ */
