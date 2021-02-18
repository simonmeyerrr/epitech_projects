/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** DanModule.cpp
*/

#include <iostream>
#include <ncurses.h>
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "DanModule.hpp"
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

DanModule::~DanModule()
{}

DanModule::DanModule()
{
    if (_texture.loadFromFile("./assets/dan.png"))
        _sprite.setTexture(_texture);
}

void DanModule::refresh()
{}

Types::Modules DanModule::getModuleType() const
{
    return (Types::DAN);
}

void DanModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    SFML::Text text("Dan's favorite animal", "", 10 + (505 * vec.x), 5 + (505 *
    vec.y), sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    text.display(win);
    for (auto it = _pos.begin(); it != _pos.end(); it++) {
        (*it).x += random() % 11 - 5;
        (*it).y += random() % 11 - 5;
        if ((*it).x < 0)
            (*it).x = 0;
        if ((*it).x > 450)
            (*it).x = 450;
        if ((*it).y < 0)
            (*it).y = 0;
        if ((*it).y > 410)
            (*it).y = 410;
        _sprite.setPosition(505 * vec.x + (*it).x, 505 * vec.y + (*it).y + 50);
        win->draw(_sprite);
    }
}

int DanModule::getColor(int x, int y) const
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

void DanModule::displayNcurse(sf::Vector2f vec)
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
    Ncurses::Text title("DAN'S FAVORITE ANIMAL", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 8);
    c.display();
    title.display();
    for (auto it = _pos.begin(); it != _pos.end(); it++) {
        (*it).x += random() % 11 - 5;
        (*it).y += random() % 11 - 5;
        if ((*it).x < 0)
            (*it).x = 0;
        if ((*it).x > 450)
            (*it).x = 450;
        if ((*it).y < 0)
            (*it).y = 0;
        if ((*it).y > 410)
            (*it).y = 410;
        attron(COLOR_PAIR(7));
        float pos_x, pos_y;
        pos_x = (((*it).y * 100.0) / 410.0) * (((float)c.H - 6.0) / 100.0);
        pos_y = (((*it).x * 100.0) / 450.0) * (((float)c.W - 6.0) / 100.0);
        mvprintw(pos_x + 3 + y, pos_y + 2 + x, "> <");
        attron(COLOR_PAIR(6));
        mvprintw(pos_x + 3 + y, pos_y + 3 + x, "|");
    }
}

void DanModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
    _pos.push_back(sf::Vector2f(random() % 450, random() % 410));
}
