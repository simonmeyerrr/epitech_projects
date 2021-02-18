/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Settings.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SETTINGS_HPP
    #define OOP_INDIE_STUDIO_2018_SETTINGS_HPP

#include <irrlicht/irrlicht.h>
#include <string>
#include "Config.hpp"
#include "Structures.hpp"

class Settings {
public:
    ~Settings() = default;
    explicit Settings(bool get_from_file = false);
    Settings(const Settings &);
    Settings &operator=(const Settings &);

    static std::string getMyIp();
    static void setDefaultValues(struct settings_s &set);
    static void saveSettings(const struct settings_s &set);

    std::string my_ip;
    bool create_game;
    struct settings_s settings;
};

#endif /* OOP_INDIE_STUDIO_2018_SETTINGS_HPP */
