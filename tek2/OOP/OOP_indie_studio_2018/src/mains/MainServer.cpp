/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** MainServer.cpp
*/

#include <iostream>
#include "../utils/my_sockets.hpp"
#include "../game/GameBack.hpp"
#include "../Settings.hpp"

int main(int ac, const char **av)
{
    #ifdef WIN32
    WSACleanup();
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    #endif
    int ret = 84;

    try {
        Settings set;
        GameBack game(set);
        ret = (game.hasError() ? 84 : 0);
    } catch (...) {
        std::cerr << "Something went wrong..." << std::endl;
    }
    #ifdef WIN32
    WSACleanup();
    #endif
    return ret;
}