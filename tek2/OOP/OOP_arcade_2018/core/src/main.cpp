/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <string.h>
#include <exception>
#include "Core.hpp"

void printHelp(int fd, const char *cmd)
{
    (void)fd;
    (void)cmd;
    std::cout << "help" << std::endl;
}

int main(int ac, const char **av)
{
    if (ac != 2) {
        printHelp(2, av[0]);
        return (84);
    } else if (!strcmp(av[1], "-h")) {
        printHelp(1, av[0]);
        return (0);
    } else {
        try {
            arcade::Core core = {std::string(av[1])};
            core.loop();
            return (0);
        } catch (const std::exception &e) {
            return (84);
        } catch (...) {
            return (84);
        }
    }
}