/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** IMonitorEvent.cpp
*/

#include "Ncurse/EventNcurse.hpp"
#include "Sfml/EventSfml.hpp"
#include "IMonitorEvent.hpp"

IMonitorEvent *createMonitorEvent(Types::DisplayMode mode)
{
    switch (mode) {
    case Types::SFML:
        return (new EventSfml);
    case Types::NCURSE:
        return (new EventNcurse);
    default:
        throw std::exception();
    }
}