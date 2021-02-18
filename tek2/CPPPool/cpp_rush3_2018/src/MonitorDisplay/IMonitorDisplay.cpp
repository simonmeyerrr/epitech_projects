/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** IMonitorDisplay.cpp
*/

#include <exception>
#include "Ncurse/MonitorNcurse.hpp"
#include "Sfml/MonitorSfml.hpp"
#include "IMonitorDisplay.hpp"

IMonitorDisplay *createMonitorDisplay(Types::DisplayMode mode)
{
    switch (mode) {
    case Types::SFML:
        return (new MonitorSfml);
    case Types::NCURSE:
        return (new MonitorNcurse);
    default:
        throw std::exception();
    }
}