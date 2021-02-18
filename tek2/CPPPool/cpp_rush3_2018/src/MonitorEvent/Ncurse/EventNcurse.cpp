/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** EventNcurse.cpp
*/

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <fstream>
#include "EventNcurse.hpp"
#include "../../MonitorDisplay/Ncurse/Container.hpp"

void EventNcurse::changeModule(IMonitorModule **modules, int i,
    Types::Offset offset)
{
    Types::Modules type = Types::NONE;
    if (modules[i])
        type = modules[i]->getModuleType();

    delete modules[i];
    modules[i] = createMonitorModule(type, offset);
}

void EventNcurse::manageClick(MEVENT event, IMonitorModule **modules)
{
    for (int i = 0; i < 4; i++) {
        int xMax;
        int yMax;
        int x;
        int y;
        getmaxyx(stdscr, yMax, xMax);
        if (i / 2 == 0)
            y = 0;
        else
            y = (yMax / 2);
        if (i % 2 == 0)
            x = 0;
        else
            x = (xMax / 2);
        Ncurses::Container c(y, x, (xMax / 2) - 1, (yMax / 2), 0);
        auto button = c.getPrev();
        if (event.x >= std::get<0>(button) &&
            event.x < std::get<0>(button) + 3 &&
            event.y == std::get<1>(button)) {
            changeModule(modules, i, Types::LEFT);
        }
        button = c.getNext();
        if (event.x >= std::get<0>(button) &&
            event.x < std::get<0>(button) + 3 &&
            event.y == std::get<1>(button)) {
            changeModule(modules, i, Types::RIGHT);
        }
        if (event.y >= (int)c.X + 3 && event.y < (int)c.X + (int)c.H &&
            event.x >= (int)c.Y && event.x < (int)c.Y + (int)c.W &&
            modules[i]) {
            modules[i]->clickOnMy(sf::Vector2f(0, 0), Types::NCURSE);
        }
    }
}

bool EventNcurse::get(IMonitorDisplay *display, IMonitorModule **modules,
    Settings &settings)
{
    (void)display;
    MEVENT event;
    int c = getch();
    if (c != ERR) {
        if (c == 'q') {
            settings.closeProg();
            return (false);
        }
        if (c == 's') {
            settings.setDisplayMode(Types::SFML);
            return (true);
        }
        if (c == KEY_MOUSE && getmouse(&event) == OK)
            manageClick(event, modules);
    }
    return (false);
}
