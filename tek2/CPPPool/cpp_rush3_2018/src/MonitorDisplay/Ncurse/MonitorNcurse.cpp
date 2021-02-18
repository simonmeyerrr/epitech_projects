/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorNcurse.cpp
*/

#include <unistd.h>
#include <ncurses.h>
#include "MonitorNcurse.hpp"
#include "./Container.hpp"
#include "./Text.hpp"

MonitorNcurse::~MonitorNcurse()
{
    endwin();
}

MonitorNcurse::MonitorNcurse()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    mousemask(ALL_MOUSE_EVENTS, nullptr);

    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_CYAN, COLOR_CYAN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLUE, COLOR_BLACK);
    init_pair(9, COLOR_BLUE, COLOR_BLUE);
    init_pair(10, COLOR_BLACK, COLOR_CYAN);
    init_pair(11, COLOR_BLACK, COLOR_BLUE);
    init_pair(51, COLOR_GREEN, COLOR_BLACK);
    init_pair(52, COLOR_RED, COLOR_BLACK);
    init_pair(53, COLOR_CYAN, COLOR_BLACK);
    init_pair(54, COLOR_YELLOW, COLOR_BLACK);
    init_pair(55, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(59, COLOR_BLUE, COLOR_BLACK);
}

int MonitorNcurse::getColor(int x, int y) const
{
    if (x == 0 && y == 0)
        return 3;
    if (x == 0 && y == 1)
        return 4;
    if (x == 1 && y == 0)
        return 5;
    if (x == 1 && y == 1)
        return 9;
    return 0;
}

void MonitorNcurse::noneModule(sf::Vector2f vec) const
{
    int xMax;
    int yMax;
    int x;
    int y;
    getmaxyx(stdscr, yMax, xMax);
    if (vec.x == 0)
        y = 0;
    else
        y = (yMax / 2);
    if (vec.y == 0)
        x = 0;
    else
        x = (xMax / 2);
    Ncurses::Container c(y, x, (xMax / 2) - 1, (yMax / 2),
        getColor(vec.x, vec.y));
    Ncurses::Text title("NONE", "", y + 2, x + 3, getColor(vec.x, vec.y) + 50,
        8);
    title.display();
    c.display();
}

bool MonitorNcurse::resMin() const
{
    int x;
    int y;
    getmaxyx(stdscr, x, y);
    if (x < 40 || y < 80)
        return true;
    return false;
}

void MonitorNcurse::displayFooter() const
{
    attron(A_BOLD);
    attron(COLOR_PAIR(6));
    mvprintw(0, 2, " Quit : Q ");
    mvprintw(0, 15, " Switch to SFML : S ");
    attroff(COLOR_PAIR(6));
    attroff(A_BOLD);
}

void MonitorNcurse::refreshWindow(IMonitorModule **modules, Settings settings)
{
    bool resolutionMin = false;
    clear();
    resolutionMin = resMin();
    for (int i = 0; i < 4 && !resolutionMin; i++) {
        if (modules[i])
            modules[i]->displayNcurse(sf::Vector2f(i / 2, i % 2));
        else
            noneModule(sf::Vector2f(i / 2, i % 2));
    }
    if (!resolutionMin)
        displayFooter();
    if (resolutionMin) {
        int x;
        int y;
        getmaxyx(stdscr, x, y);
        clear();
        mvprintw(x / 2, y / 2 - 21,
            "Please increase the terminal resolution !");
    }
    refresh();
    move(-1, -1);
    (void)settings;
}

sf::RenderWindow *MonitorNcurse::getWindow()
{
    return (nullptr);
}
