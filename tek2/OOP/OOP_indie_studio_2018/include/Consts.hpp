/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Consts.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_CONSTS_HPP
#define OOP_INDIE_STUDIO_2018_CONSTS_HPP

#include <tuple>
#include <vector>
#include <functional>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include "Structures.hpp"

/// PlayerTypeString contains of the string name for each PlayerType
const std::map<PlayerType, std::string> PlayerTypeString = {
    {PLAYER_NONE, "None"},
    {PLAYER_LOCAL, "Local"},
    {PLAYER_EXTERN, "Extern"},
    {PLAYER_AI, "Bot"}
};

/// BombModel contains the path of the bomb's 3D model
const std::string BombModel = ASSETS_PATH_STR "models/bomb.obj";
/// BombSkin contains the path of the bomb's texture
const std::string BombSkin = ASSETS_PATH_STR "textures/bomb.png";

/// MapModel contains the path of the map's 3D model
const std::string MapModel = ASSETS_PATH_STR "models/map.obj";
/// MapSkin contains the path of the map's texture
const std::string MapSkin = ASSETS_PATH_STR "textures/map.png";

/// MapModel contains the path of the podium's 3D model
const std::string PodiumModel = ASSETS_PATH_STR "models/podium.obj";
/// PodiumSkin contains the path of the podium's texture
const std::string PodiumSkin = ASSETS_PATH_STR "textures/podium.png";

/// LamasticotModel contains the path of the lamasticot's 3D model
const std::string LamasticotModel = ASSETS_PATH_STR "models/lamasticot.ms3d";

/// PlayerSkinPath contains the path of the lamasticot's texture depending on the PlayerSkin
const std::map<PlayerSkin, std::string> PlayerSkinPath = {
    {LAMA_BRAUN, ASSETS_PATH_STR "textures/lamasticot_braun.png"},
    {LAMA_BLACK, ASSETS_PATH_STR "textures/lamasticot_black.png"},
    {LAMA_WHITE, ASSETS_PATH_STR "textures/lamasticot_white.png"},
    {LAMA_RED, ASSETS_PATH_STR "textures/lamasticot_red.png"},
    {LAMA_BLUE, ASSETS_PATH_STR "textures/lamasticot_blue.png"},
    {LAMA_GREEN, ASSETS_PATH_STR "textures/lamasticot_green.png"},
    {LAMA_YELLOW, ASSETS_PATH_STR "textures/lamasticot_yellow.png"},
    {LAMA_PURPLE, ASSETS_PATH_STR "textures/lamasticot_purple.png"}
};

/// BlockModels contains the path the lamasticot's 3D model and texture for each BlockType
const std::map<BlockType, std::pair<std::string, std::string>> BlockModels = {
    {BLOCK_NONE, {ASSETS_PATH_STR "models/sand.obj", ASSETS_PATH_STR "textures/sand.png"}},
    {BLOCK_UNBREAKABLE, {ASSETS_PATH_STR "models/rock.obj", ASSETS_PATH_STR "textures/rock.png"}},
    {BLOCK_BREAKABLE, {ASSETS_PATH_STR "models/bamboo.obj", ASSETS_PATH_STR "textures/bamboo.png"}}
};

/// BonusModel contains the path of the bonuses's 3D model
const std::string BonusModel = ASSETS_PATH_STR "models/bonus.obj";

/// BonusSkins contains the path of the bonuses's texture depending on the BonusType
const std::map<BonusType , std::string> BonusSkins = {
    {BONUS_SPEED_UP, ASSETS_PATH_STR "textures/bonus_speed.png"},
    {BONUS_BOMB_MAX, ASSETS_PATH_STR "textures/bonus_bomb_max.png"},
    {BONUS_BOMB_POWER, ASSETS_PATH_STR "textures/bonus_bomb_power.png"},
    {BONUS_LASER, ASSETS_PATH_STR "textures/bonus_laser.png"}
};

/// SoundsPath contains the path for different sounds depending on Sounds
const std::map<Sounds, std::vector<std::string>> SoundsPath = {
    {SOUND_SPLASH, {
        ASSETS_PATH_STR "sounds/splash.ogg"}},
    {SOUND_INTRO, {
        ASSETS_PATH_STR "sounds/intro.ogg"}},
    {SOUND_CLICK, {
        ASSETS_PATH_STR "sounds/click1.ogg",
        ASSETS_PATH_STR "sounds/click2.ogg"}},
    {SOUND_BONUS, {
        ASSETS_PATH_STR "sounds/bonus1.ogg",
        ASSETS_PATH_STR "sounds/bonus2.ogg"}},
    {SOUND_EXPLOSION, {
        ASSETS_PATH_STR "sounds/explosion1.ogg",
        ASSETS_PATH_STR "sounds/explosion2.ogg"}},
    {SOUND_DEATH, {
        ASSETS_PATH_STR "sounds/death1.ogg",
        ASSETS_PATH_STR "sounds/death2.ogg",
        ASSETS_PATH_STR "sounds/death3.ogg"}},
    {SOUND_VICTORY, {
        ASSETS_PATH_STR "sounds/victory1.ogg",
        ASSETS_PATH_STR "sounds/victory2.ogg"}},
    {SOUND_LASER, {
        ASSETS_PATH_STR "sounds/laser1.ogg",
        ASSETS_PATH_STR "sounds/laser2.ogg"}}
};

/// MusicsPath contains the path for musics depending on Musics
const std::map<Musics, std::string> MusicsPath = {
    {MUSIC_MENU, ASSETS_PATH_STR "musics/menu.ogg"},
    {MUSIC_GAME, ASSETS_PATH_STR "musics/game.ogg"}
};

/// ToString represent a lambda which get a string depending on GameSettings
using ToString = std::function<std::string(const GameSettings &)>;
/// ChangeSettingValue represent a lambda which will update values of GameSettings
using ChangeSettingValue = std::function<void(GameSettings &, bool up)>;

/// toString transform any kind of value into a string
template<typename T>
std::string toString(const T &t)
{
    std::ostringstream os;
    os << std::boolalpha << std::fixed << std::setprecision(1) << t;
    return os.str();
}

/// changeValue change any kind of value of an offset with a minimum and maximum value
template<typename T>
void changeValue(T &value, const T &min, const T &max, const T &offset, bool up)
{
    if (up && value < max)
        value = (T)(value + offset);
    else if (!up && value > min)
        value = (T)(value - offset);
    if (value <= min)
        value = min;
    else if (value >= max)
        value = max;
}

/// ChangeGameSettings contains a description (string), a string converter and a value updater for each element present in GameSettings
const std::vector<std::tuple<std::string, ToString, ChangeSettingValue>> ChangeGameSettings = {
    {"Bomb timer (in seconds)",
        [](const GameSettings &set) {return toString(set.bomb_time);},
        [](GameSettings &set, bool up) {changeValue(set.bomb_time, 0.0f, 5.0f, 0.1f, up);}},
    {"Explosion timer (in seconds)",
        [](const GameSettings &set) {return toString(set.explosion_time);},
        [](GameSettings &set, bool up) {changeValue(set.explosion_time, 0.0f, 5.0f, 0.1f, up);}},
    {"Bomb per player at start",
        [](const GameSettings &set) {return toString((int)set.bomb_start_nb);},
        [](GameSettings &set, bool up) {changeValue(set.bomb_start_nb, (unsigned char)1, set.bomb_max_nb, (unsigned char)1, up);}},
    {"Maximum bomb per player",
        [](const GameSettings &set) {return toString((int)set.bomb_max_nb);},
        [](GameSettings &set, bool up) {
            changeValue(set.bomb_max_nb, (unsigned char)1, (unsigned char)9, (unsigned char)1, up);
            changeValue(set.bomb_start_nb, (unsigned char)1, set.bomb_max_nb, (unsigned char)0, up);
        }},
    {"Bomb power at start",
        [](const GameSettings &set) {return toString((int)set.bomb_start_power);},
        [](GameSettings &set, bool up) {changeValue(set.bomb_start_power, (unsigned char)1, set.bomb_max_power, (unsigned char)1, up);}},
    {"Maximum bomb power",
        [](const GameSettings &set) {return toString((int)set.bomb_max_power);},
        [](GameSettings &set, bool up) {
            changeValue(set.bomb_max_power, (unsigned char)1, (unsigned char)10, (unsigned char)1, up);
            changeValue(set.bomb_start_power, (unsigned char)1, set.bomb_max_power, (unsigned char)0, up);
        }},
    {"Speed bonus at start",
        [](const GameSettings &set) {return toString((int)set.speed_start);},
        [](GameSettings &set, bool up) {changeValue(set.speed_start, (unsigned char)0, set.speed_max,(unsigned char)1, up);}},
    {"Maximum speed bonus",
        [](const GameSettings &set) {return toString((int)set.speed_max);},
        [](GameSettings &set, bool up) {
            changeValue(set.speed_max, (unsigned char)0, (unsigned char)10, (unsigned char)1, up);
            changeValue(set.speed_start, (unsigned char)0, set.speed_max, (unsigned char)0, up);
        }},
    {"Bonus drop chance (%)",
        [](const GameSettings &set) {return toString((int)set.bonus_chance);},
        [](GameSettings &set, bool up) {changeValue(set.bonus_chance, (unsigned char)0, (unsigned char)100, (unsigned char)5, up);}},
    {"Collision between player",
        [](const GameSettings &set) {return toString(set.collision_player);},
        [](GameSettings &set, bool up) {set.collision_player = !set.collision_player;}},
    {"Collision between player and bombs",
        [](const GameSettings &set) {return toString(set.collision_bomb);},
        [](GameSettings &set, bool up) {set.collision_bomb = !set.collision_bomb;}},
    {"Bombs explode on cascade",
        [](const GameSettings &set) {return toString(set.bomb_cascade);},
        [](GameSettings &set, bool up) {set.bomb_cascade = !set.bomb_cascade;}},
    {"Explosion break multiple blocks",
        [](const GameSettings &set) {return toString(set.explosion_multi_break);},
        [](GameSettings &set, bool up) {set.explosion_multi_break = !set.explosion_multi_break;}}
    };

#endif /* OOP_INDIE_STUDIO_2018_CONSTS_HPP */
