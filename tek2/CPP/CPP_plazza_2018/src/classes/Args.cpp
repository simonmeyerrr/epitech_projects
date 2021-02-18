/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Args.cpp
*/

#include "Args.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

Args::Args(int ac, const char **av)
    : _ac(ac), _av(av)
{
}

int Args::usage(int ret) const
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t./plazza <multiplier> <cook> <time>" << std::endl
    << std::endl;
    std::cout << "\t<multiplier>: multiplier for the cooking time."
    << std::endl;
    std::cout << "\t<cook>: number of cooks per kitchen." << std::endl;
    std::cout << "\t<time>: time in milliseconds to replace ingredients."
    << std::endl;
    return (ret);
}

bool Args::isNum(const char *str) const
{
    for (size_t i = 0; str[i] != '\0'; ++i)
        if (str[i] != '.' && str[i] != ',' && (str[i] < '0' || str[i] > '9'))
            return (false);
    return (true);
}

int Args::checkArgs()
{
    std::string help(_av[0]);
    if (_ac == 1 && (help == "-h" || help == "--help"))
        return (usage(0));
    if (_ac != 3) {
        std::cerr << "Not enough arguments." << std::endl;
        return (usage(84));
    }
    if (!isNum(_av[0]) || !isNum(_av[1]) || !isNum(_av[2])) {
        std::cerr << "Invalid argument." << std::endl;
        return (usage(84));
    }
    _multiplier = atof(_av[0]);
    _cooks = atoi(_av[1]);
    _respawn = atoi(_av[2]);
    return (1);
}

double Args::getMultiplier() const
{
    return _multiplier;
}

int Args::getCooks() const
{
    return _cooks;
}

int Args::getRespawn() const
{
    return _respawn;
}