/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Structures.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_STRUCTURES_HPP
#define OOP_INDIE_STUDIO_2018_STRUCTURES_HPP

#include "Config.hpp"
#include "Enums.hpp"

/// PACK set attribute packed to structures so they take less space in memory
#ifdef WIN32
    #define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )
#else /* not WIN32 */
    #define PACK(__Declaration__) __Declaration__ __attribute__((__packed__))
#endif /* WIN32 */

/// PlayerSettings contains the type and the skin for a player for game creation
using PlayerSettings = struct player_settings_s {
    PlayerType type;
    PlayerSkin skin;
};

/// KeySet contains control keys for a player
using KeySet = struct key_set_s {
    int up; ///< key which will make the player go up
    int left; ///< key which will make the player go left
    int down; ///< key which will make the player go down
    int right; ///< key which will make the player go right
    int action; ///< key which will make the player use his power (put a bomb or use laser)
};

/// GameSettings contains every settings for a game
using GameSettings = struct game_settings_s {
    float bomb_time; ///< Time in seconds took by a bomb to explode (0.0 to 3.0)
    float explosion_time; ///< Time in seconds of an explosion (0.0 to 3.0)
    unsigned char bomb_start_nb; ///< Initial number of bombs per player(1 to bomb_max_nb)
    unsigned char bomb_max_nb;  ///< Maximum number of bombs per player (1 to 9)
    unsigned char bomb_start_power; ///< Initial range of bombs (1 to bomb_max_power)
    unsigned char bomb_max_power; ///< Maximum range of bombs (1 to 10)
    unsigned char speed_start; ///< Initial speed bonus (0 to speed_max)
    unsigned char speed_max; ///< Maximum speed bonus (0 to 10)
    unsigned char bonus_chance; ///< Chance of bonus drop in percent (0 to 100)
    bool collision_player; ///< Activation of collision between players
    bool collision_bomb; ///< Activation of collision between bombs and players
    bool bomb_cascade; ///< Activation of cascade explosions
    bool explosion_multi_break; ///< Activation of multi break explosions (one explosion can break multiple blocks on a line)
};

/// struct settings_s contains project's settings which can be saved
struct settings_s {
    key_set_s keys[PLAYER_NUMBER]; ///< Key settings for each players
    player_settings_s players[PLAYER_NUMBER]; ///< Type and skin settings for each players
    char join_ip[20]; ///< Ip to join a game
    int join_nb; ///< Player number to join a game
    bool from_file; ///< Start game by charging a saved game
    bool map_complex; ///< Generate complex generation for maps
    int general_volume; ///< Volume of all sounds (0 to 100)
    int music_volume; ///< Volume of musics (0 to 100)
    int sfx_volume; ///< Volume of sfx (0 to 100)
    game_settings_s game; ///< Game settings
};

/// Position contains X and Y based position
using Position = PACK(struct position_s {
    char x; ///< x
    char y; ///< y
});

/// Block contains information about a block in the map
using Block = PACK(struct block_s {
    BlockType type; ///< Type of the block
    bool bomb; ///< Presence of a bomb on this block
    unsigned char bomb_player; ///< Player who put the bomb
    unsigned char bomb_power; ///< Power of the bomb
    double bomb_percent; ///< Advancement of the bomb before explosion (0 to 100)
    bool explosion; ///< Presence of an explosion on this block
    double explosion_percent; ///< Advancement of the explosion (0 to 100)
    BonusType bonus; ///< Bonus present on the block
});

/// PlayerStats contains information about a player in the game
using PlayerStats = PACK(struct player_stats_s {
    bool exist; ///< Does the player exist
    bool connected; ///< Is the player connected
    bool alive; ///< Is the player alive
    PlayerSkin skin; ///< Skin of the player
    unsigned char number; ///< Number which represent the player
    char rank; ///< Rank of the player in the game
    unsigned char speed; ///< Speed bonus of the player
    unsigned char max_bomb; ///< Maximum bombs of the player
    unsigned char ready_bomb; ///< Number of bombs that the player can put
    unsigned char bomb_power; ///< Power of explosion of bombs
    Direction dir; ///< Direction of the player
    Position pos; ///< Position in the map of the player
    Position next_pos; ///< Next position of the player if he is moving
    bool moving; ///< Is the player moving from a block to another one
    double move_percent; ///< Movement advancement of the player (0 to 100)
    bool bonus_laser; ///< Have a laser bonus available
    bool using_laser; ///< Is using his laser bonus
    double laser_percent; ///< Laser utilization advancement (0 to 100)
});

/// GameStats contains every informations of a game
using GameStats = PACK(struct global_game_s {
    unsigned int magic; ///< Magic number to check packet validity
    bool started; ///< Has the game started
    bool end; ///< Is the game over
    PlayerStats players[PLAYER_NUMBER]; ///< Player statistics for each players
    Block map[MAP_HEIGHT * MAP_WIDTH]; ///< Every block which compose the map
});

/// Action contains information of action send from player to game back-end
using Action = PACK(struct action_s {
    unsigned int magic; ///< Magic number to check packet validity
    bool move; ///< Do the player want to move
    Direction dir; ///< Direction the player want to move in
    bool use_power; ///< Do the player want to use his power
});

#endif /* OOP_INDIE_STUDIO_2018_STRUCTURES_HPP */
