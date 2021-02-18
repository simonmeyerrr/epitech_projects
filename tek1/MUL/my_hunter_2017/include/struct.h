/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** structures
*/

typedef struct myVar
{
	int menu;
	int birdgoright;
	int birdgoleft;
	int image_move_rect;
	int randomRX;
	int randomRY;
	int randomLX;
	int randomLY;
	float difficulty;
	int pause;
	double pause_time;
	int new_highscore;

	sfVector2f pos1;
	sfVector2f pos2;
	sfVector2f scale1;
	sfVector2f scale2;
	sfIntRect rect;

	sfVideoMode mode;
} myVar_t;

typedef struct myStat
{
	int score;
	int life;
	int stage;
	float shot;
	int shot_failed;
	float shot_succes;
	float precision;
	int shot_blue;
	int shot_yellow;
	int double_shot;
	int fail_blue;
	int fail_yellow;
} myStat_t;

typedef struct myClock
{
	sfClock* game;
	sfClock* pause;
	sfClock* shot;
	sfClock* frame_rate;

	sfTime time;
	float seconds;
} myClock_t;

typedef struct myMusic
{
	sfMusic* menu;
	sfMusic* game;
	sfMusic* shot_blue;
	sfMusic* shot_yellow;
	sfMusic* double_shot;
	sfMusic* shotgun;
	sfMusic* lose_life;
	sfMusic* game_over;
} myMusic_t;

/* R = go to right, L = go to left, B = blue, Y = yellow */

typedef struct myText
{
	sfText* title;
	sfText* start;
	sfText* exit;

	sfText* pause;
	sfText* score;
	sfText* int_score;
	sfText* life;
	sfText* int_life;
	sfText* stage;
	sfText* int_stage;

	sfText* game_over;
	sfText* restart;
	sfText* end_exit;
	sfText* new_high_score;
	sfText* int_new_high_score;
	sfText* end_score;
	sfText* end_int_score;
	sfText* int_high_score;
	sfText* end_stage;
	sfText* end_int_stage;
	sfText* shot_success;
	sfText* int_shot_success;
	sfText* shot_double;
	sfText* int_shot_double;
	sfText* shot_failed;
	sfText* int_shot_failed;
	sfText* precision;
	sfText* int_precision;
	sfText* bird_B_shot;
	sfText* bird_Y_shot;
	sfText* int_bird_B_shot;
	sfText* int_bird_Y_shot;
	sfText* bird_B_fail;
	sfText* bird_Y_fail;
	sfText* int_bird_B_fail;
	sfText* int_bird_Y_fail;

	sfFont* font;
} myText_t;

typedef struct myTexture
{
	sfTexture* background;
	sfTexture* bird_RB;
	sfTexture* bird_RY;
	sfTexture* bird_LB;
	sfTexture* bird_LY;
	sfTexture* crosshair;
	sfTexture* mouse;
	sfTexture* begin_menu;
	sfTexture* end_menu;
} myTexture_t;

typedef struct mySprite
{
	sfSprite* background;
	sfSprite* bird_RB;
	sfSprite* bird_RY;
	sfSprite* bird_LB;
	sfSprite* bird_LY;
	sfSprite* crosshair;
	sfSprite* mouse;
	sfSprite* begin_menu;
	sfSprite* end_menu;
} mySprite_t;

typedef struct myObjects
{
	sfRenderWindow* window;
	sfEvent event;
	myTexture_t* texture;
	mySprite_t* sprite;
	myText_t* text;
	myMusic_t* music;
	myClock_t* clock;
	myVar_t* var;
	myStat_t* stat;
} myObjects_t;
