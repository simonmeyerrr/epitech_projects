/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Settings.cpp
*/

#include <iostream>
#include <fstream>
#include "utils/my_sockets.hpp"
#include "Settings.hpp"

Settings::Settings(bool get_from_file)
    : my_ip(getMyIp()), create_game(true), settings()
{
    setDefaultValues(settings);
    if (!get_from_file)
        return;
    std::ifstream file(SETTINGS_FILE);
    if (file.is_open()) {
        file.read((char*)&settings, sizeof(struct settings_s));
        file.close();
    }
}

Settings::Settings(const Settings &other)
    : my_ip(other.my_ip), create_game(other.create_game), settings()
{
    memcpy(&settings, &(other.settings), sizeof(struct settings_s));
}

Settings &Settings::operator=(const Settings &other)
{
    memcpy(&settings, &(other.settings), sizeof(struct settings_s));
    saveSettings(settings);
    return *this;
}

std::string Settings::getMyIp()
{
    std::string ip("127.0.0.1");

    #ifdef WIN32
    std::string line;
    std::ifstream file;
    int offset;
    std::string search("IPv4 Address. . . . . . . . . . . :");
    system("ipconfig > .tmp_ip.txt");
    file.open(".tmp_ip.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            std::getline(file, line);
            offset = line.find(search);
            if (offset != std::string::npos) {
                line.erase(0, 39);
                ip = line;
                break;
            }
        }
        file.close();
    }
    #else
    struct ifaddrs *iflist;

    if (getifaddrs(&iflist) < 0)
        return ip;
    for (struct ifaddrs *iface = iflist; iface; iface = iface->ifa_next) {
        char addrp[INET6_ADDRSTRLEN];
        const void *addr = NULL;
        if (iface->ifa_addr->sa_family == AF_INET)
            addr = &((struct sockaddr_in *)iface->ifa_addr)->sin_addr;
        if (addr &&
            inet_ntop(iface->ifa_addr->sa_family, addr, addrp, sizeof(addrp))) {
            std::string new_ip(addrp);
            std::string interface(iface->ifa_name);
            if (new_ip.find("127.") != 0 &&
                interface.find("docker") == std::string::npos &&
                interface.find("virbr") == std::string::npos &&
                interface != "lo") {
                ip = new_ip;
                break;
            }
        }
    }
    freeifaddrs(iflist);
    #endif
    #ifdef DEBUG
    std::cout << "My ip is " << ip << std::endl;
    #endif
    return ip;
}

void Settings::setDefaultValues(struct settings_s &set)
{
    memset(&set, '\0', sizeof(struct settings_s));
    set.keys[0] = {irr::EKEY_CODE::KEY_KEY_Z, irr::EKEY_CODE::KEY_KEY_Q,
        irr::EKEY_CODE::KEY_KEY_S, irr::EKEY_CODE::KEY_KEY_D,
        irr::EKEY_CODE::KEY_KEY_A};
    set.keys[1] = {irr::EKEY_CODE::KEY_UP, irr::EKEY_CODE::KEY_LEFT,
        irr::EKEY_CODE::KEY_DOWN, irr::EKEY_CODE::KEY_RIGHT,
        irr::EKEY_CODE::KEY_KEY_M};
    set.keys[2] = {irr::EKEY_CODE::KEY_KEY_U, irr::EKEY_CODE::KEY_KEY_H,
        irr::EKEY_CODE::KEY_KEY_J, irr::EKEY_CODE::KEY_KEY_K,
        irr::EKEY_CODE::KEY_KEY_Y};
    set.keys[3] = {irr::EKEY_CODE::KEY_KEY_5, irr::EKEY_CODE::KEY_KEY_1,
        irr::EKEY_CODE::KEY_KEY_2, irr::EKEY_CODE::KEY_KEY_3,
        irr::EKEY_CODE::KEY_KEY_4};
    set.players[0] = {PLAYER_LOCAL, LAMA_BRAUN};
    set.players[1] = {PLAYER_LOCAL, LAMA_BLACK};
    set.players[2] = {PLAYER_LOCAL, LAMA_WHITE};
    set.players[3] = {PLAYER_LOCAL, LAMA_YELLOW};
    memset(set.join_ip, '\0', 20);
    set.general_volume = 100;
    set.music_volume = 100;
    set.sfx_volume = 100;
    set.join_nb = 3;
    set.map_complex = true;
    set.from_file = false;
    set.game.bomb_time = 1.6;
    set.game.explosion_time = 0.8;
    set.game.bomb_start_nb = 1;
    set.game.bomb_max_nb = 5;
    set.game.bomb_start_power = 2;
    set.game.bomb_max_power = 5;
    set.game.speed_start = 0;
    set.game.speed_max = 10;
    set.game.bonus_chance = 15;
    set.game.collision_player = true;
    set.game.collision_bomb = false;
    set.game.bomb_cascade = true;
    set.game.explosion_multi_break = false;
}

void Settings::saveSettings(const struct settings_s &set)
{
    std::ofstream file(SETTINGS_FILE);
    if (file.is_open()) {
        file.write((char*)&set, sizeof(struct settings_s));
        file.close();
    }
}