/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** proto.h
*/

/* string_vector_rect.c */
void move_rect(sfIntRect *rect, int offset, int max_value);
sfVector2f create_vector(float x, float y);
int my_strlen(char *str);
void my_putstr_fd(char *str, int fd);
int my_strcmp(char *s1, char *s2);
char *pourcent_to_str(int pc);
sfText *init_text(sfFont *font, int size, sfVector2f pos, char *str);
sfSprite *create_sprite(sfTexture *texture, int *error);
sfVector2f get_mouse_pos(sfRenderWindow *win);

/* open_map.c */
char** open_map(char *path_map, int *error);
void free_map(char **map);

/* prepare_game.c / prepare_texture_sprite.c */
game_t *prepare_game(char **map, int *error, int *settings);
void prepare_texture(my_texture_t *texture, int *error, int *settings);
void prepare_sprite(my_sprite_t *sprite, my_texture_t *texture, int *error);
void prepare_obj(my_object_t *obj, char **map, int *error);
int free_struct_game(game_t *game, int *);

/* game */
int my_runner(sfRenderWindow *win, char **map, int *error, int *settings);
void display_map(my_object_t *obj, my_sprite_t *sprite,
sfRenderWindow *win);
void analyze_event_game(game_t *game, sfEvent event, sfRenderWindow *win);
void update_game(game_t *game);
void jump(game_t *game);
void detect_colision(game_t *game);
int on_ground(my_object_t *obj, my_var_t *var);
void analyze_event_end(game_t *game, sfEvent event, sfRenderWindow *win);
void display_game(game_t *game, sfRenderWindow *win);
void jump3(game_t *game, int i);

/* menu */
void main_menu(menu_t *menu, sfRenderWindow *win);
menu_t *prepare_menu(int *error);
void free_struct_menu(menu_t *menu);
void settings_menu(menu_t *menu, sfRenderWindow *win);
void init_text_menu2(menu_text_t *text, int *error, sfFont *font);
void play_menu(menu_t *menu, sfRenderWindow *win);
