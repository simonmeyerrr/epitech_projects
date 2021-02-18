/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Config.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_CONFIG_HPP
    #define OOP_INDIE_STUDIO_2018_CONFIG_HPP

    #ifdef _IRR_WINDOWS_
        #pragma comment(lib, "Irrlicht.lib")
        #pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
    #endif /* _IRR_WINDOWS_ */

    #define STRINGIFY(x) XSTRINGIFY(x)
    #define XSTRINGIFY(x) #x

    #ifndef ASSETS_PATH
        #define ASSETS_PATH ./assets/
    #endif /* ASSETS_PATH */

    #define ASSETS_PATH_STR STRINGIFY(ASSETS_PATH)
    #define SETTINGS_FILE ASSETS_PATH_STR "settings.conf"
    #define SAVE_FILE ASSETS_PATH_STR "last.save"

    #define WINDOW_WIDTH 1600
    #define WINDOW_HEIGHT 900
    #define WINDOW_FORMAT irr::core::dimension2d<irr::u32>(WINDOW_WIDTH, WINDOW_HEIGHT)
    #define DEFAULT_SCENE SCENE_SPLASH_SCREEN

    #define PLAYER_NUMBER 4
    #define MAP_WIDTH 15
    #define MAP_HEIGHT 15
    #define BLOCK_SIZE 2.89614f

    #define MAGIC_NUMBER 0x42697465

#endif /* OOP_INDIE_STUDIO_2018_CONFIG_HPP */
