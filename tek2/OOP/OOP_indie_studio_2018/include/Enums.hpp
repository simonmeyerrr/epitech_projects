/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Enums.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_ENUMS_HPP
#define OOP_INDIE_STUDIO_2018_ENUMS_HPP

/// PlayerType enumerate different type of players for the game creation
enum PlayerType {
    PLAYER_NONE = 0,
    PLAYER_LOCAL = 1,
    PLAYER_EXTERN = 2,
    PLAYER_AI = 3
};

/// PlayerSkin enumerate different skins for players
enum PlayerSkin {
    LAMA_BRAUN = 0,
    LAMA_BLACK = 1,
    LAMA_WHITE = 2,
    LAMA_RED = 3,
    LAMA_BLUE = 4,
    LAMA_GREEN = 5,
    LAMA_YELLOW = 6,
    LAMA_PURPLE = 7
};

/// Direction enumerate different direction (360°)
enum Direction {
    DIR_UP = 0,
    DIR_RIGHT = 90,
    DIR_DOWN = 180,
    DIR_LEFT = 270
};

/// BonusType enumerate different bonuses for players
enum BonusType {
    BONUS_NONE = 0,
    BONUS_SPEED_UP = 1,
    BONUS_BOMB_POWER = 2,
    BONUS_BOMB_MAX = 3,
    BONUS_LASER = 4,
};

/// BlockType enumerate different block for a map
enum BlockType {
    BLOCK_NONE = 0,
    BLOCK_UNBREAKABLE = 1,
    BLOCK_BREAKABLE = 2,
};

/// MapType enumerate different type of map generation
enum MapType {
    MAP_CLASSIC = 0,
    MAP_COMPLEX = 1,
};

/// Sounds enumerate different soundss which can be played
enum Sounds {
    SOUND_SPLASH,
    SOUND_INTRO,
	SOUND_CLICK,
	SOUND_BONUS,
	SOUND_EXPLOSION,
	SOUND_DEATH,
	SOUND_VICTORY,
	SOUND_LASER
};

/// Musics enumerate different musics which can be played
enum Musics {
    MUSIC_MENU,
    MUSIC_GAME,
};

#endif /* OOP_INDIE_STUDIO_2018_ENUMS_HPP */
