/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Main.cpp
*/

#ifdef WIN32
    #include "../utils/my_sockets.hpp"
#endif

#include <iostream>
#include "../IndieStudio.hpp"

int main()
{
    #ifdef WIN32
    WSACleanup();
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    #endif
    int ret = 84;


    try {
        std::srand(std::time(nullptr));
        IndieStudio studio;
        studio.loop();
        ret = 0;
    } catch (...) {
        std::cerr << "Something went wrong..." << std::endl;
    }
    #ifdef WIN32
    WSACleanup();
    #endif
    return ret;
}