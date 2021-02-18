/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** macro.h
*/

#define EXIT_SUCCESS	0
#define EXIT_ERROR	84

#define USAGE	"This runner game was created by Simon Meyer with CSFML library\
.\nIf you want to create your own map or understand every 'block' of the game, \
look at the .legend file.\n\nUSAGE\n\t./my_runner\t\tOpen a window with differe\
nt menu where you can chose different levels and change settings.\n\t./my_runne\
r [map.txt]\tYou can play on a custom map.\n\t./my_runner -h\t\tDisplay usage.\
\n\nUSER INTERACTIONS\n\tLEFT CLICK\tClick on different button to interract wit\
h the game (ex: change settings, restart the game, ...)\n\tESCAPE\t\tPause and \
resume the game. Escape the menu where you are when you're not in game which is\
 not over.\n\tRETURN\t\tRestart the game when it is over.\n\tSPACE\t\tJump when\
 your in the game.\n"

#define MUSIC_GAME	"resources/music/mozart.ogg"
#define MUSIC_JUMP	"resources/music/jump.ogg"
#define MUSIC_DEATH	"resources/music/death.ogg"
#define MUSIC_WIN	"resources/music/win.ogg"
#define MUSIC_CLICK	"resources/music/jump.ogg"

#define PLAYER1		"resources/image/player1.png"
#define PLAYER2		"resources/image/player2.png"
#define FULL_BLOCK	"resources/image/block.png"
#define SEMI_BLOCK	"resources/image/semi_block.png"
#define JUMP_BLOCK	"resources/image/jump_block.png"
#define JUMP_INFINITE	"resources/image/jump_infinite.png"
#define END_BLOCK	"resources/image/end_block.png"
#define BACKGROUND1	"resources/image/background1.png"
#define BACKGROUND2	"resources/image/background2.png"
#define BACKGROUND3	"resources/image/background3.png"
#define PAUSE_MENU	"resources/image/pause.png"
#define END_MENU	"resources/image/end.png"
#define MOUSE		"resources/image/mouse.png"
#define PICK		"resources/image/pick.png"
#define MAIN_MENU	"resources/image/main_menu.png"
#define SET_MENU	"resources/image/settings.png"
#define BORDER		"resources/image/border.png"
#define LITTLE_BORDER	"resources/image/little_border.png"
#define PLAY_MENU	"resources/image/play_menu.png"
#define LOCK		"resources/image/lock.png"

#define FONT1	"resources/font/font2.ttf"
#define FONT2	"resources/font/font3.ttf"

#define TYPE_VOID_BLOCK	0
#define	TYPE_FULL_BLOCK	1
#define TYPE_SEMI_BLOCK	2
#define	TYPE_JUMP_BLOCK	3
#define	TYPE_END_BLOCK	4
#define TYPE_PICK	5
#define TYPE_JUMP_INFINITE	6

#define TXT1	"  Play\n\nSettings\n\n  Exit"
#define TXT2	"My Runner"
#define TXT3	"0  1  2  3  4  5  6  7  8  9"
#define TXT4	"      Volume\n\n\nRunner       Font"
#define TXT5	"1  2  3  4  5"
#define TXT6	"6  7  8  9"

#define TAB_MAP	{"map/map1", "map/map2", "map/map3", "map/map4", "map/map5", "m\
ap/map6", "map/map7", "map/map8", "map/map9", "map/map10", "map/map11"}

#define INVALID_BLOCK(c)	((c != ' ' && c != 'F' && c != 'S' && c != 'P'\
&& c != 'E' && c != 'J' && c != 'p' && c != 'I') ? (1) : (0))

#define IF_RETURN(event)	((event.type == sfEvtKeyPressed && event.key.co\
de == sfKeyEscape) || (event.type == sfEvtMouseButtonPressed && event.mouseButt\
on.x >= 0 && event.mouseButton.x <= 100 && event.mouseButton.y >= 0 && event.mo\
useButton.y <= 100)) ? (1) : (0)

#define IF_VOLUME(event, i)	(event.mouseButton.x >= 160 + (i * 150) && even\
t.mouseButton.x <= 260 + (i * 150) && event.mouseButton.y >= 150 && event.mouse\
Button.y <= 250) ? (1) : (0)

#define IF_THEME(event, i)	(event.mouseButton.x >= 160 + (i * 400) && even\
t.mouseButton.x <= 460 + (i * 400) && event.mouseButton.y >= 450 && event.mouse\
Button.y <= 850) ? (1) : (0)

#define IF_FONT(event, i)	(event.mouseButton.x >= 1060 + (i * 400) && eve\
nt.mouseButton.x <= 1360 + (i * 400) && event.mouseButton.y >= 450 && event.mou\
seButton.y <= 850) ? (1) : (0)

#define IF_LAST_LEVEL(event)	(event.mouseButton.x >= 860 &&event.mouseButton\
.x <= 1060 && event.mouseButton.y >= 700 && event.mouseButton.y <= 900) ? (1) :\
(0)
