/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** BatteryModule Module
*/

#include "BatteryModule.hpp"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <string>
#include "../MonitorDisplay/Sfml/Bar.hpp"
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

BatteryModule::~BatteryModule()
{}

BatteryModule::BatteryModule()
{
    this->refresh();
}

void BatteryModule::getBatteryInfo(int i)
{
    std::string percent;
    std::ifstream file("/sys/class/power_supply/BAT" + std::to_string(i) + "/capacity");
    if (!file.is_open())
        return;
    std::getline(file, percent);
    V.push_back(percent);
    getBatteryInfo(i + 1);
}

void BatteryModule::refresh()
{
    V.clear();
    getBatteryInfo(0);
}

Types::Modules BatteryModule::getModuleType() const
{
    return (Types::BATTERY);
}

void BatteryModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    auto xOrigin = (unsigned)(505 * vec.x);
    auto yOrogin = (unsigned)(505 * vec.y);
    SFML::Text title("Battery", "", 20 + xOrigin, 5 + yOrogin,
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    title.display(win);
    int i = 0;
    for (auto it = V.begin(); it != V.end(); it++, i++) {
        int percent = std::stoi(*it);
        auto bat = SFML::Bar("Battery " + std::to_string(i), 100, xOrigin +
        10, yOrogin + 120 + (i * 50) , "");
        bat.setValue(percent);
        bat.display(win);
    }
}

int BatteryModule::getColor(int x, int y) const
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

void BatteryModule::displayNcurse(sf::Vector2f vec)
{
    int xMax;
    int yMax;
    int x;
    int y;
    int i = 0;
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
    Ncurses::Text title("BATTERY STATE", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 8);
    for (auto it = V.begin(); it != V.end(); it++, i++) {
        int percent = std::stoi(*it);
        Ncurses::Bar b("BAT" + std::to_string(i), 100, (xMax / 2) - 4, y + 5 + 2 * i, x + 3, true, "%%");
        b.setValue(percent);
        b.display();
    }
    c.display();
    title.display();
}

void BatteryModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
}
