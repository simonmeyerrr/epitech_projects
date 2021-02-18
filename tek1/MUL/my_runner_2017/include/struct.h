/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** struct.h
*/

typedef struct my_var
{
	int menu;
	int restart;
	int win;
	int pause;

	int pourcent;
	int end_distance;
	int position;

	int reserve_jump;
	int jump;
	int move_vec;

	int cheat;
} my_var_t;

typedef struct my_text
{
	sfFont *font;

	sfText *score;
	sfText *end_score;
	sfText *win;
	sfText *lose;
} my_text_t;

typedef struct my_block
{
	int type;
	sfVector2f pos;

	struct my_block *next;
	struct my_block *prev;
} my_block_t;

typedef struct my_player
{
	sfIntRect rect;
	sfVector2f pos;
	int move_rect;
} my_player_t;

typedef struct my_object
{
	my_player_t *player;

	my_block_t *line0;
	my_block_t *line1;
	my_block_t *line2;
	my_block_t *line3;
	my_block_t *line4;
	my_block_t *line5;
	my_block_t *line6;
	my_block_t *line7;
	my_block_t *line8;
	my_block_t *line9;
} my_object_t;

typedef struct my_sprite
{
	sfSprite *player;

	sfSprite *full_block;
	sfSprite *semi_block;
	sfSprite *jump_block;
	sfSprite *jump_infinite;
	sfSprite *end_block;
	sfSprite *pick;

	sfSprite *background1;
	sfSprite *background2;
	sfSprite *background3;

	sfSprite *pause_menu;
	sfSprite *end_menu;
	sfSprite *mouse;
} my_sprite_t;

typedef struct my_texture
{
	sfTexture *player;

	sfTexture *full_block;
	sfTexture *semi_block;
	sfTexture *jump_block;
	sfTexture *jump_infinite;
	sfTexture *end_block;
	sfTexture *pick;

	sfTexture *background1;
	sfTexture *background2;
	sfTexture *background3;

	sfTexture *pause_menu;
	sfTexture *end_menu;
	sfTexture *mouse;
} my_texture_t;

typedef struct my_music
{
	sfMusic *game;
	sfMusic *jump;
	sfMusic *death;
	sfMusic *win;
} my_music_t;

typedef struct my_clock
{
	sfClock *frame_rate;
	sfClock *update;
} my_clock_t;

typedef struct game
{
	sfEvent event;

	my_texture_t *texture;
	my_sprite_t *sprite;
	my_object_t *obj;
	my_text_t *text;
	my_clock_t *clock;
	my_music_t *music;
	my_var_t *var;
} game_t;

typedef struct menu_texture
{
	sfTexture *mouse;
	sfTexture *main_menu;
	sfTexture *set_menu;
	sfTexture *border;
	sfTexture *little_border;
	sfTexture *play_menu;
	sfTexture *lock;
} menu_texture_t;

typedef struct menu_sprite
{
	sfSprite *mouse;
	sfSprite *main_menu;
	sfSprite *set_menu;
	sfSprite *border;
	sfSprite *little_border;
	sfSprite *play_menu;
	sfSprite *lock;
} menu_sprite_t;

typedef struct menu_text
{
	sfFont *font1;
	sfFont *font2;

	sfText *main_menu;
	sfText *my_runner;
	sfText *int_volume;
	sfText *ten;
	sfText *volume;
	sfText *a_font1;
	sfText *a_font2;
	sfText *level1;
	sfText *level2;
	sfText *level3;
	sfText *level4;
} menu_text_t;

typedef struct menu_music
{
	sfMusic *click;
} menu_music_t;

typedef struct menu_var
{
	int menu;

	int sound;
	int theme;
	int font;

	int level_choice;
	int level_max;
} menu_var_t;

typedef struct menu
{
	sfEvent event;
	sfClock *frame_rate;

	menu_texture_t *texture;
	menu_sprite_t *sprite;
	menu_text_t *text;
	menu_music_t *music;
	menu_var_t *var;
} menu_t;
