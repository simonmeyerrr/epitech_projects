/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** proto.h
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

hangman_t *init_hangman(int ac, char **av);
void display_game(hangman_t *hangman, csfml_t *csfml);
csfml_t *init_csfml(void);
void display_hangman(int tries, sfRenderWindow *win);
sfVertex create_vertex(sfVector2f a , sfColor c , sfVector2f b);
sfVector2f create_vector(int a, int b);

void display_hang2(int tries, sfVertexArray *array);
void display_hang3(int tries, sfVertexArray *array);
void display_hang4(int tries, sfVertexArray *array);
void display_hang5(int tries, sfVertexArray *array);
void display_hang6(int tries, sfVertexArray *array);

/* utils_string.c */
int my_strlen(char *str);
int is_line_valid(char *line);
char *get_hidden_word(hangman_t *hangman, char *word);

/* utils_int.c */
int my_get_nbr(char *str);
int is_nb_valid(char *str);

/* utils_memory.c */
void my_free(void *ptr);
void my_free_tab(char **tab);
int my_tab_len(char **tab);

/* utils_display.c */
void my_putstr(char *str);
void my_put_err(char *str);
void my_put_nb(int nb);

/* other_utils */
char *get_next_line(int fd);
char **str_to_tab(char *str, char *sep);

#endif	/* PROTO_H_ */
