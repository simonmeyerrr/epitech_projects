/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

Parser::Parser(int ac, const char **av)
{
    _ac = ac;
    for (int i = 0; i < 4; i++)
        _mods[i] = Types::NONE;
    for (int i = 0; i < _ac; i++)
        _av.push_back(std::string(av[i]));
}

Parser::Parser(const Parser &other) : _ac(other._ac), _av(other._av)
{
    for (int i = 0; i < 4; i++)
        _mods[i] = other._mods[i];
}

Parser &Parser::operator=(const Parser &other)
{
    _ac = other._ac;
    _av = other._av;
    for (int i = 0; i < 4; i++)
        _mods[i] = other._mods[i];
    return (*this);
}

Types::DisplayMode Parser::getMode() const
{
    if (_ac < 2)
        return (Types::UNKNOWN);

    if (_av[1] == "sfml") {
        return (Types::SFML);
    } else if (_av[1] == "ncurse") {
        return (Types::NCURSE);
    } else {
        return (Types::UNKNOWN);
    }
}

Types::Modules *Parser::getModules()
{
    for (int i = 0; i + 2 < _ac; i++) {
        if (_av[i + 2] == "info")
            _mods[i] = Types::INFO;
        else if (_av[i + 2] == "cpu")
            _mods[i] = Types::CPU;
        else if (_av[i + 2] == "memory")
            _mods[i] = Types::MEMORY;
        else if (_av[i + 2] == "network")
            _mods[i] = Types::NETWORK;
        else if (_av[i + 2] == "reports")
            _mods[i] = Types::REPORTS;
        else if (_av[i + 2] == "dan")
            _mods[i] = Types::DAN;
        else if (_av[i + 2] == "battery")
            _mods[i] = Types::BATTERY;
        else if (_av[i + 2] == "none")
            _mods[i] = Types::NONE;
    }
    return (_mods);
}

void Parser::printUsage() const
{
    if (_ac < 1)
        return;
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t" << _av[0] << " mode [module] [module] [module] [module]"
        << std::endl << std::endl;
    std::cout << "\tmode:   display mode (sfml or ncurse)" << std::endl;
    std::cout << "\tmodule: setup modules on dashboard" << std::endl;
    std::cout << "\t\t(info, cpu, memory, network, reports, dan, battery or none)"
        << std::endl;
    std::cout << std::endl;
}
