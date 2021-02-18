/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** main.cpp
*/

#include "Parser/Parser.hpp"
#include "MonitorCore/MonitorCore.hpp"

int main(int ac, const char **av)
{
    srandom(time(nullptr));
    Parser parser(ac, av);

    if (parser.getMode() == Types::UNKNOWN) {
        parser.printUsage();
        return (1);
    }
    MonitorCore(parser.getMode(), parser.getModules());
    return (0);
}
