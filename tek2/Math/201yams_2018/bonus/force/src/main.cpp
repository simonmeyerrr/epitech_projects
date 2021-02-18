/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** main.cpp
*/

#include "Yams.hpp"

int main(int ac, const char **av)
{
    Yams yams(ac, av);

    if (yams.hasError())
        return (84);
    if (yams.needHelp())
        return (yams.printUsage());
    yams.compute();
    yams.dump();
    return (0);
}