/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

/* string.c */
int my_strlen(char *str);
void my_putstr_fd(char *str, int fd);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *s1);
void my_free(void *ptr);
int verif_malloc(void *ptr, int *error);
char *int_to_str(int nb);
char *time_to_str(double time);

/* vector.c */
sfVector2f create_vector(float x, float y);
sfVector2f get_mouse_pos(sfRenderWindow *win);
void set_pos_draw(sfSprite *sprite, sfRenderWindow *win, sfVector2f pos);

/* initialisation of the game */
game_t *init_game(int *error);
my_texture_t *init_texture(int *error);
my_sprite_t *init_sprite(my_texture_t *text, int *error);
my_text_t *init_text(int *error);

/* free elements of the game */
void free_game(game_t *game);

/* window displayed */
void start_animation(game_t *game);
void main_menu(game_t *game);
void play_game(game_t *game, my_obj_t *obj, sfClock *update);
void update_game(game_t *game, my_obj_t *obj);
void settings(game_t *game);
void end_game(game_t *game, my_obj_t *obj);
void pause_game(game_t *game);

#endif	/* PROTO_H_ */
