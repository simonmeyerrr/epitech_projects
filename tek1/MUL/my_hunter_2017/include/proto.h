/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** prototypes
*/

int my_strcmp(char *s1, char *s2);
void my_putstr(char *str);
char *five_to_str(int nb);
char *two_to_str(int nb);
char *my_strdup(char *src);
char *pc_to_str(float nb);
char *three_to_str(int nb);
void my_hunter(int*);
void my_init(myObjects_t* obj, int*);
void start_menu(myObjects_t* obj);
void my_init_text(myText_t* text, sfFont* font, int* error);
void prepare_game(myObjects_t* obj);
void prepare_end(myObjects_t* obj, myText_t* text, myStat_t* stat);
void my_init_clock(myObjects_t* obj);
void end_menu(myObjects_t* obj);
void my_init_music(myMusic_t* music, int* error);
void bird_rect(myObjects_t* obj);
sfVector2f pos_mouse(sfRenderWindow* window);
sfVector2f create_vector(float x, float y);
void disp_birds(myObjects_t* obj);
void game_screen(myObjects_t* obj, sfRenderWindow* window, mySprite_t* sprite);
void manage_hit_box(myObjects_t* obj, sfMouseButtonEvent event);
void my_destroy(myObjects_t* obj);
