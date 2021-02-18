/*
** EPITECH PROJECT, 2017
** dante_solver
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

char **my_str_to_wordtab(char *str, char sep);
void create_maze(char *path);
int *get_possibility(maze_t *maze, int *tab);
void solve_maze(maze_t *maze);
void check_maze_valid(char **maze);
void display_curse(maze_t *maze);

/* memory.c */
void my_free(void *ptr);
void my_free_tab(char **tab);
int my_tab_len(char **tab);
void verif_malloc(void *ptr);
void my_free_maze(maze_t *maze);

#endif	/* PROTO_H_ */
