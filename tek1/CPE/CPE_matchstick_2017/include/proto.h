/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** proto.h
*/

char *get_next_line(int fd);
int my_strlen(char *str);
void my_disp(char *str, int fd);
int my_getnbr(char *str);
int turn_player(int *param, int *stick, int *error);
void disp_matchstick(int *param, int *stick);
void my_putnbr(int nb);
int turn_robot(int *param, int *stick, int *error);
