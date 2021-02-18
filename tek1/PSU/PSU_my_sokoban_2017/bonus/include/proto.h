/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** proto.h
*/

char** open_map(char* path);
void manage_touch(int touch, char** map, var_t* var);
void touch_up(int touch, char** map, var_t* var);
void touch_down(int touch, char** map, var_t* var);
void touch_right(int touch, char** map, var_t* var);
void touch_left(int touch, char** map, var_t* var);;
int sokoban(char* path);
int check_blocked(char** map, var_t* var, int, int);
