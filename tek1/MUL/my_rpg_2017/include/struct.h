/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct global global_t;
typedef struct my_sprite my_sprite_t;
typedef struct my_font my_font_t;
typedef struct game game_t;

typedef struct scene
{
	void (*event)(global_t *, sfEvent);
	void (*update)(global_t *, int *);
	void (*display)(global_t *, my_sprite_t *, my_font_t *,
	sfRenderWindow *);
} scene_t;

typedef struct my_texture
{
	sfTexture *background[NB_BACKGROUND];
	sfTexture *button[NB_BUTTON];
	sfTexture *image[NB_IMAGE];
	sfTexture *world[NB_WORLD];
	sfTexture *animation[NB_ANIMATION];
} my_texture_t;

typedef struct my_sprite
{
	sfSprite *background[NB_BACKGROUND];
	sfSprite *button[NB_BUTTON];
	sfSprite *image[NB_IMAGE];
	sfSprite *world[NB_WORLD];
	sfSprite *animation[NB_ANIMATION];
} my_sprite_t;

typedef struct my_music
{
	sfMusic *music[NB_MUSIC];
	sfMusic *sound[NB_SOUND];
} my_music_t;

typedef struct my_var
{
	char setting[4];
	float fps;

	char con_var[3];
	char *con_field[3];

	char button[3];
	int animation;
} my_var_t;

typedef struct my_font
{
	sfFont *font1;
	sfFont *font2;
	sfFont *font3;
} my_font_t;

typedef struct my_clock
{
	long long time;
	sfClock *update;
	sfClock *frame_rate;
} my_clock_t;

typedef struct my_network
{
	sfTime time;

	sfHttp *http;
	sfHttpRequest *req;
	sfHttpResponse *rep;
} my_network_t;

struct item_info
{
	char *name;
	image_t image;
	int attack;
	int defense;
	int equipement;
};

typedef struct inventory
{
	status_item_t status;
	item_t item;

	struct inventory *next;
	struct inventory *prev;
} inventory_t;

typedef struct env
{
	int prog_max;
	int image;
	int *pos;
	void (*fonc)(global_t *, game_t *);

	struct env *next;
	struct env *prev;
} env_t;

typedef struct my_text
{
	int chars;
	int elem;
	char **text;
	void (*fonc)(global_t *, game_t *);
} my_text_t;

typedef struct part_s
{
	sfVertex *vertex;
	sfTexture *text;
	sfRenderStates *state;
	sfVector2f *speed;
	int *life;
	int size;
} part_t;

typedef struct snow_s
{
	sfVertex *vertex;
	sfVector2f *speed;
	sfVector2i coord;
	int size;
}snow_t;

struct enemy_info
{
	image_t image;
	char *attack;
};

typedef struct my_fight
{
	enemy_t enemy;
	int stat_enemy[4];

	char fight_status;
	char fight_anim;

	int damage;
	char *string;

	part_t *part;

	void (*win)(global_t *, game_t *);
} my_fight_t;

typedef struct game
{
	char **map;
	int pos[2];
	direction_t dir;
	char move_on;
	char move_status;

	int progression;
	int stat_player[4];

	inventory_t *first_inv;
	inventory_t *last_inv;

	env_t *first_env;
	env_t *last_env;

	my_text_t *text;
	my_fight_t *fight;

	snow_t *snow;
} game_t;

typedef struct global
{
	sfRenderWindow *win;
	sfEvent event;

	scene_name_t scene;
	scene_t scene_tab[NB_SCENE];

	my_texture_t *texture;
	my_sprite_t *sprite;
	my_music_t *music;
	my_font_t *font;

	my_clock_t *clock;
	my_var_t *var;

	my_network_t *net;
	game_t *game;
} global_t;

#endif	/* STRUCT_H_ */
