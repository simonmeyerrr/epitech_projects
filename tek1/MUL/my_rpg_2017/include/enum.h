/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** enum.h
*/

#ifndef ENUM_H_
#define ENUM_H_

// scene
typedef enum
{
	SCENE_MAIN_MENU,
	SCENE_LOG_IN,
	SCENE_SIGN_UP,
	SCENE_CONNECTED,
	SCENE_SETTINGS,
	SCENE_ANIMATION,
	SCENE_GAME,
	SCENE_INVENTORY,
	SCENE_FIGHT,
	SCENE_GAME_MENU,
	SCENE_HELP,
} scene_name_t;

// texture / sprite
typedef enum
{
	BG_MAIN_MENU,
	BG_INVENTORY,
	BG_FIGHT,
	BG_FIGHT2,
	BG_FIGHT3,
	BG_HELP,
	BG_SETTING,
} background_t;

typedef enum
{
	BT_BIG_OFF,
	BT_BIG_ON,
	BT_LITTLE_OFF,
	BT_LITTLE_ON,
	BT_INPUT_FIELD,
	BT_INPUT_SEL,
	BT_MOUSE_OFF,
	BT_MOUSE_ON,
	BT_CURSOR_BUT,
	BT_SWITCH_L,
	BT_SWITCH_R,
	BT_FIGHT_1,
	BT_FIGHT_2,
} button_t;

typedef enum
{
	IM_LAMA_RIGHT,
	IM_LAMA_LEFT,
	IM_COURNNE,
	IM_SACADO,
	IM_BATON,
	IM_CROCS,
	IM_CORO_FIGHT,
	IM_LOGAN_FIGHT,
	IM_KNUCKLE_FIGHT,
	IM_LAMA_FIGHT,
	IM_JAHAR_FIGHT,
	IM_CHAT,
	IM_TONGUE,
	IM_BIERE,
	IM_DILDO,
} image_t;

typedef enum
{
	WD_MAP,
	WD_CORO1,
	WD_CORO2,
	WD_KNUCKLES,
	WD_STICK,
	WD_COFFRE,
	WD_LOGAN,
	WD_PNJ1,
	WD_PNJ2,
	WD_PNJ3,
	WD_PANNEAU,
	WD_ROI_KNUCKLE,
	WD_LAMA,
	WD_JAHAR,
	WD_LORION,
	WD_NURSE,
} world_t;

// music / sound
typedef enum
{
	MUSIC_ANIMATION,
	MUSIC_FLAMINGO,
	MUSIC_THEME,
	MUSIC_FIGHT,
} music_name_t;

typedef enum
{
	SOUND_CLICK,
	SOUND_LAMA,
	SOUND_COFFRE,
	SOUND_STEPS,
	SOUND_ARETE,
	SOUND_EUUUH,
	SOUND_ATTACK1,
	SOUND_ABANON,
	SOUND_LOSE,
	SOUND_VICTOIRE,
	SOUND_ATTACK2,
} sound_name_t;

// var
typedef enum
{
	SET_VOL_GENERAL = 0,
	SET_VOL_MUSIC = 1,
	SET_VOL_SOUND = 2,
	SET_VSYNC = 3
} setting_t;

typedef enum
{
	CON_FIELD = 0,
	CON_ERROR = 1,
	CON_ERROR_STAT = 2
} con_var_t;

typedef enum
{
	CON_USERNAME = 0,
	CON_PASSWORD1 = 1,
	CON_PASSWORD2 = 2
} con_field_t;

typedef enum
{
	BUT_PRESSED = 0,
	BUT_STATUS = 1,
	BUT_RELEASED = 2
} button_var_t;

// game
typedef enum
{
	SI_IN_INV,
	SI_EQUIP_HEAD,
	SI_EQUIP_WAEPON,
	SI_EQUIP_WEAR,
	SI_EQUIP_SHOES
} status_item_t;

typedef enum
{
	ITEM_BATON,
	ITEM_COURONNE,
	ITEM_SACADO,
	ITEM_CROCS,
	ITEM_TONGUE,
	ITEM_BIERE,
	ITEM_DILDO,
} item_t;

typedef enum
{
	EN_LOGAN,
	EN_KNUCKLE,
	EN_LAMA,
	EN_JAHAR,
} enemy_t;

typedef enum
{
	DIR_DOWN,
	DIR_RIGHT,
	DIR_LEFT,
	DIR_UP,
} direction_t;

typedef enum
{
	STAT_PV,
	STAT_PV_MAX,
	STAT_ATTACK,
	STAT_DEF,
} stat_player_t;

#endif	/* ENUM_H_ */
