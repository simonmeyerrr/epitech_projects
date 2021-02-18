/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneType.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENETYPE_HPP
    #define OOP_INDIE_STUDIO_2018_SCENETYPE_HPP

enum SceneType {
    SCENE_NONE = -1,
    SCENE_SPLASH_SCREEN = 0,
    SCENE_INTRODUCTION = 1,
    SCENE_MAIN_MENU,
    SCENE_CREATE_GAME,
    SCENE_JOIN_GAME,
    SCENE_IN_GAME,
    SCENE_SETTINGS,
    SCENE_KEY_SETTINGS,
    SCENE_CREDIT,
    SCENE_ANIM,
};

using ChangeScene = std::pair<bool, SceneType>;

#endif /* OOP_INDIE_STUDIO_2018_SCENETYPE_HPP */
