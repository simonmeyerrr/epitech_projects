/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

// Exit value
#define MY_SUCCESS	0
#define MY_ERROR	84

// Window settings
#define WIDTH	1600
#define HEIGHT	900
#define WINDOW_NAME	"Lamasticot Adventure"
#define WINDOW_OPTION	sfClose
#define CURSOR_VISIBLE	sfFalse

// Macro for function
#define TEXT(a, b, c, d)	create_text(a, b, c, d)
#define VEC(a, b)		create_vec(a, b)
#define TAB4(a, b, c, d)	create_tab4(a, b, c, d)
#define TAB2(a, b)		create_tab2(a, b)

// scene
#define NB_SCENE	11
#define TAB_EVENT	{event_main_menu, event_log_in, event_sign_up,\
			event_connected, event_settings, event_animation,\
			event_game, event_inventory, event_fight,\
			event_game_menu, event_help}
#define TAB_UPDATE	{update_main_menu, update_log_in, update_sign_up,\
			update_connected, update_settings, update_animation,\
			update_game, update_inventory, update_fight,\
			update_game_menu, update_help}
#define TAB_DISPLAY	{display_main_menu, display_log_in, display_sign_up,\
			display_connected, display_settings, display_animation,\
			display_game, display_inventory, display_fight,\
			display_game_menu, display_help}

// path for font
#define FONT1	"asset/font/font.otf"
#define FONT2	"asset/font/manga.ttf"
#define FONT3	"asset/font/Pixeled.ttf"

// path for texture
// background
#define NB_BACKGROUND	7
#define MAIN_BACKGROUND	"asset/texture/main_background.png"
#define INVENTORY	"asset/texture/inventory.png"
#define COMBAT		"asset/texture/combat.png"
#define COMBAT2		"asset/texture/combat2.png"
#define COMBAT3		"asset/texture/combat3.png"
#define AIDE		"asset/texture/aide.png"
#define SETTING		"asset/texture/setting.png"

#define PATH_BACKGROUND	{MAIN_BACKGROUND, INVENTORY, COMBAT, COMBAT2, COMBAT3,\
			AIDE, SETTING}

// button
#define NB_BUTTON	13
#define BIG_BUTTON_OFF	"asset/texture/big_button_off.png"
#define BIG_BUTTON_ON	"asset/texture/big_button_on.png"
#define LIT_BUTTON_OFF	"asset/texture/lit_button_off.png"
#define LIT_BUTTON_ON	"asset/texture/lit_button_on.png"
#define INPUT_ZONE	"asset/texture/input_zone.png"
#define INPUT_SELECT	"asset/texture/input_select.png"
#define MOUSE_OFF	"asset/texture/mouse_off.png"
#define MOUSE_ON	"asset/texture/mouse_on.png"
#define SET_CURSOR_BUT	"asset/texture/cursor_button.png"
#define SWITCH_LEFT	"asset/texture/switch_left.png"
#define SWITCH_RIGHT	"asset/texture/switch_right.png"
#define FIGHT_1		"asset/texture/but_fight_1.png"
#define FIGHT_2		"asset/texture/but_fight_2.png"

#define PATH_BUTTON	{BIG_BUTTON_OFF, BIG_BUTTON_ON, LIT_BUTTON_OFF,\
			LIT_BUTTON_ON, INPUT_ZONE, INPUT_SELECT, MOUSE_OFF,\
			MOUSE_ON, SET_CURSOR_BUT, SWITCH_LEFT, SWITCH_RIGHT,\
			FIGHT_1, FIGHT_2}

// image
#define NB_IMAGE	15
#define LAMA_RIGHT	"asset/texture/lama_right.png"
#define LAMA_LEFT	"asset/texture/lama_left.png"
#define COURONNE	"asset/texture/courone.png"
#define SACADO		"asset/texture/sacado.png"
#define BATON		"asset/texture/baton.png"
#define CROCS		"asset/texture/crocs.png"
#define CORO_FIGHT	"asset/texture/coro_fight.png"
#define LOGAN_FIGHT	"asset/texture/logan_fight.png"
#define KNUCKLE_FIGHT	"asset/texture/knuckle_fight.png"
#define LAMA_FIGHT	"asset/texture/lama_fight.png"
#define JAHAR_FIGHT	"asset/texture/jahar_fight.png"
#define CHAT		"asset/texture/chat.png"
#define TONGUE		"asset/texture/tongue.png"
#define BIERE		"asset/texture/biere.png"
#define DILDO		"asset/texture/dildo.png"

#define PATH_IMAGE	{LAMA_RIGHT, LAMA_LEFT, COURONNE, SACADO, BATON, CROCS,\
			CORO_FIGHT, LOGAN_FIGHT, KNUCKLE_FIGHT, LAMA_FIGHT,\
			JAHAR_FIGHT, CHAT, TONGUE, BIERE, DILDO}

// world
#define NB_WORLD	16
#define MAP		"asset/texture/map.png"
#define CORO1		"asset/texture/coro1.png"
#define CORO2		"asset/texture/coro2.png"
#define KNUCKLES	"asset/texture/knuckles.png"
#define STICK		"asset/texture/stick.png"
#define COFFRE		"asset/texture/coffre.png"
#define LOGAN		"asset/texture/logan_paul.png"
#define	PNJ1		"asset/texture/pnj1.png"
#define	PNJ2		"asset/texture/pnj2.png"
#define	PNJ3		"asset/texture/pnj3.png"
#define	PANNEAU		"asset/texture/panneau.png"
#define	ROI_KNUCKLE	"asset/texture/roi_knuckle.png"
#define LAMA		"asset/texture/petit_lama.png"
#define JAHAR		"asset/texture/jahar.png"
#define LORION		"asset/texture/lorion.png"
#define NURSE		"asset/texture/infirmiere.png"

#define PATH_WORLD	{MAP, CORO1, CORO2, KNUCKLES, STICK, COFFRE, LOGAN,\
			PNJ1, PNJ2, PNJ3, PANNEAU, ROI_KNUCKLE, LAMA, JAHAR,\
			LORION, NURSE}

// animation
#define NB_ANIMATION	16
#define ANIMATION1	"asset/texture/animation1.png"
#define ANIMATION2	"asset/texture/animation2.png"
#define ANIMATION3	"asset/texture/animation3.png"
#define ANIMATION4	"asset/texture/animation4.png"
#define ANIMATION5	"asset/texture/animation5.png"
#define ANIMATION6	"asset/texture/animation6.png"
#define ANIMATION7	"asset/texture/animation7.png"
#define ANIMATION8	"asset/texture/animation8.png"
#define ANIMATION9	"asset/texture/animation9.png"
#define ANIMATION10	"asset/texture/animation10.png"
#define ANIMATION11	"asset/texture/animation11.png"
#define ANIMATION12	"asset/texture/animation12.png"
#define ANIMATION13	"asset/texture/animation13.png"
#define ANIMATION14	"asset/texture/animation14.png"
#define ANIMATION15	"asset/texture/animation15.png"
#define ANIMATION16	"asset/texture/animation16.png"

#define PATH_ANIMATION	{ANIMATION1, ANIMATION2, ANIMATION3, ANIMATION4,\
			ANIMATION5, ANIMATION6, ANIMATION7, ANIMATION8,\
			ANIMATION9, ANIMATION10, ANIMATION11, ANIMATION12,\
			ANIMATION13, ANIMATION14, ANIMATION15, ANIMATION16}

// Path for music
// music
#define NB_MUSIC	4
#define MUSIC_PATH_ANIM		"asset/sound/animation.ogg"
#define FLAMINGO		"asset/sound/flamingo.ogg"
#define MAIN_THEME		"asset/sound/quiet_theme.ogg"
#define PATH_MUSIC_FIGHT	"asset/sound/fight1.ogg"
#define PATH_MUSIC	{MUSIC_PATH_ANIM, FLAMINGO, MAIN_THEME,\
			PATH_MUSIC_FIGHT}
// sound
#define NB_SOUND	11
#define CLICK		"asset/sound/click.ogg"
#define LAMAAA		"asset/sound/lama_intro.ogg"
#define LE_COFFRE	"asset/sound/coffre.ogg"
#define MARCHE		"asset/sound/steps.ogg"
#define ARETE		"asset/sound/areut.ogg"
#define EUUUH		"asset/sound/euh.ogg"
#define ATTACK1		"asset/sound/attack1.ogg"
#define ABANON		"asset/sound/ahbahnon.ogg"
#define LOSE		"asset/sound/lose.ogg"
#define VICTOIRE	"asset/sound/victoire.ogg"
#define ATTACK2		"asset/sound/yeeee.ogg"
#define PATH_SOUND	{CLICK, LAMAAA, LE_COFFRE, MARCHE, ARETE, EUUUH,\
			ATTACK1, ABANON, LOSE, VICTOIRE, ATTACK2}

#endif	/* MACRO_H_ */
