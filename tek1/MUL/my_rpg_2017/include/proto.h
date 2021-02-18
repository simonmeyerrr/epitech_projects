/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** proto.h
*/

#ifndef PROTO_H_
#define PROTO_H_

// Csfml
// global_event.c
int event_click(global_t *global);
int event_key(global_t *global, sfKeyCode key);
int mouse_on_button(sfVector2f mouse_pos, int *tab);
void event_close(global_t *global);
void input_to_str(sfKeyCode key, char *str);
// global_update.c
void update_user(global_t *global);
void apply_settings(global_t *global);
int update_button(global_t *global);
void update_con_error(global_t *global);
// global_draw.c
void my_draw_sprite(sfRenderWindow *win, sfSprite *sprite, sfVector2f pos);
sfText *create_text(sfVector2f pos, int size, sfColor color, sfFont *font);
void my_draw_text(sfRenderWindow *win, sfText *text, char *str, int free_str);
void my_draw_mouse(global_t *global, int on);
// network.c
char *create_body(my_var_t *var);
int are_logs_ok(char const *body);
sfHttpRequest *create_request(int method, char *uri, char *body);
void send_http_request(global_t *global, int method, char *uri, char *body);
// sign_up.c / log_in.c
void user_creation(global_t *global, int *error, my_var_t *var);
void user_connection(global_t *global, int *error, my_var_t *var);
int  get_user_info(global_t *global, game_t *game);

// Init
void prepare_global(global_t *global, int *error, int online);
my_font_t *prepare_font(int *error);
my_music_t *prepare_music(int *error);
my_var_t *prepare_var(int *error);
my_texture_t *prepare_texture(int *error);
my_sprite_t *prepare_sprite(my_texture_t *text, int *error);
game_t *init_game(global_t *global, int *error);

// Free struct
void free_global(global_t *global);
void free_font(my_font_t *font);
void free_music(my_music_t *music);
void free_sprite(my_sprite_t *sprite);
void free_texture(my_texture_t *text);
void free_fight(game_t *game);
void free_text(game_t *game);
void free_game(global_t *global);

// Interactions
void nothing(global_t *global, game_t *game);
void add_new_item(game_t *game, item_t item, status_item_t status);
my_text_t *create_text_box(char **tab, void (*fonc)(global_t *, game_t *));
my_fight_t *create_fight(global_t *global, enemy_t enemy, int *tab,
void (*win)(global_t *, game_t *));
void inter_stick(global_t *global, game_t *game);
void inter_knuckles(global_t *global, game_t *game);
void inter_coffre2(global_t *global, game_t *game);
void inter_coffre1(global_t *global, game_t *game);
void inter_logan(global_t *global, game_t *game);
void inter_king_knuckle(global_t *global, game_t *game);
void inter_knuckle_block(global_t *global, game_t *game);
void inter_panneau(global_t *global, game_t *game);
void inter_coffre3(global_t *global, game_t *game);
void inter_nurse(global_t *global, game_t *game);
void inter_npc1(global_t *global, game_t *game);
void inter_npc2(global_t *global, game_t *game);
void inter_npc3(global_t *global, game_t *game);
void inter_lama(global_t *global, game_t *game);
void inter_jahar(global_t *global, game_t *game);

// Utils
// vector_tab.c
sfVector2f create_vec(int x, int y);
sfVector2f get_mouse_pos(global_t *global);
int *create_tab4(int nb1, int nb2, int nb3, int nb4);
int *create_tab2(int nb1, int nb2);
// get_string_nb.c
int my_get_second_number(char *str);
int my_get_nbr(char *str);
char *my_append(char *origin, char *add, int free);
char *int_to_str(int nb);
char *hiden_pass(char *str);
// utils_string.c
int my_strlen(char *str);
void my_putstr_fd(char *str, int fd);
char *my_strdup(char *s1);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *s1, char *s2);
// memory.c
void free_req_rep(my_network_t *net);
void my_free(void *ptr);
int my_tab_len(char **tab);
void my_free_tab(char **tab);
int verif_malloc(void *ptr, int *error);
// utils_setting.c
sfVector2f *get_vol_pos(global_t *global);
float *get_diff(global_t *global, sfVector2f mouse_pos);
int *get_vol(sfVector2f mouse_pos, float *pos_diff);
void set_defaut(global_t *global);
// fight_attack.c
void attack_coro1(global_t *global, game_t *game);
void attack_coro2(global_t *global, game_t *game);
void attack_enemy(global_t *global, game_t *game);
struct enemy_info ene_tab[4];
struct item_info item_tab[7];
// particules.c
part_t *new_part_buffer(int size, int color);
void set_part(part_t *buff, sfVector2f pos);
void draw_part(sfRenderWindow *window, part_t *buff);
void update_part(part_t *buff);
void free_part(part_t *buff);
// snow.c
void update_snow(snow_t *buff);
void set_snow(snow_t *buff);
snow_t *new_snow_buffer(int size, int width, int height);
void free_snow(snow_t *buff);
// other utils
int manage_arg(int ac, char **av, char **env);
char **json_parser(char *str);
char *json_creator(char **tab);
int is_nb_valid(char *str);
char *get_next_line(int fd);
char **my_str_to_wordtab(char *str, char sep);
void check_position(game_t *game, char **map);

// Scenes
// 0: main_menu
void event_main_menu(global_t *, sfEvent);
void update_main_menu(global_t *, int *);
void display_main_menu(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 1: log_in
void event_log_in(global_t *, sfEvent);
void update_log_in(global_t *, int *);
void display_log_in(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 2: sign_up
void event_sign_up(global_t *, sfEvent);
void update_sign_up(global_t *, int *);
void display_sign_up(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 3: connected
void event_connected(global_t *, sfEvent);
void update_connected(global_t *, int *);
void display_connected(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 4: settings
void event_settings(global_t *, sfEvent);
void update_settings(global_t *, int *);
void display_settings(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 5: animation
void event_animation(global_t *, sfEvent);
void update_animation(global_t *, int *);
void display_animation(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 6: game
void event_game(global_t *, sfEvent);
void update_game(global_t *, int *);
void display_game(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 7: inventory
void event_inventory(global_t *, sfEvent);
void update_inventory(global_t *, int *);
void display_inventory(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 8: fight
void event_fight(global_t *, sfEvent);
void update_fight(global_t *, int *);
void display_fight(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 9: game_menu
void event_game_menu(global_t *, sfEvent);
void update_game_menu(global_t *, int *);
void display_game_menu(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);
// 10: help
void event_help(global_t *, sfEvent);
void update_help(global_t *, int *);
void display_help(global_t *, my_sprite_t *, my_font_t *,
sfRenderWindow *);

#endif	/* PROTO_H_ */
