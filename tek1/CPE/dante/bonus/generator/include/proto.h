/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

void create_maze(int width, int height, int perfect);
void generate_maze(maze_t *maze);
int *get_possibility(maze_t *maze, int *tab);
void display_curse_maze(maze_t *maze, int *tab);
void make_maze_imperfect(maze_t *maze, int perfect);

/* string.c */
int my_strlen(char *str);
void my_putstr_fd(char *str, int fd);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);

/* memory.c */
void my_free(void *ptr);
void my_free_tab(char **tab);
void verif_malloc(void *ptr);
void my_free_maze(maze_t *maze);

#endif	/* PROTO_H_ */
