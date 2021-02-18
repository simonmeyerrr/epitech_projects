/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class file
*/

#include <fstream>
#include <iostream>
#include <limits>
#include "MemoryModule.hpp"
#include <ncurses.h>
#include "../MonitorDisplay/Sfml/Bar.hpp"
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

MemoryModule::MemoryModule()
{
    this->refresh();
}

void MemoryModule::refresh()
{
    std::ifstream f("/proc/meminfo");

    this->Values = std::unordered_map<std::string, int>();
    int nbr;
    std::string key;

    while (f >> key && f >> nbr) {
        Values[key.substr(0, key.size() - 1)] = nbr;
        f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Types::Modules MemoryModule::getModuleType() const
{
    return (Types::MEMORY);
}

void MemoryModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    auto xOrigin = (unsigned)(505 * vec.x);
    auto yOrogin = (unsigned)(505 * vec.y);
    SFML::Text title("Memory Informations", "", 20 + xOrigin, 5 + yOrogin,
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    SFML::Text total("Total RAM:",
        std::to_string(this->getRamTotal() / 1000.0) + " Gb", 20 + xOrigin,
        100 + yOrogin, sf::Color::White, sf::Color::Green);

    auto ramPercent = SFML::Bar("RAM", getRamTotal(), xOrigin + 10,
        yOrogin + 150, "Mb");
    auto swapPercent = SFML::Bar("SWAP", getSwapTotal(), xOrigin + 10,
        yOrogin + 200, "Mb");
    ramPercent.setValue(getRamUsed());
    swapPercent.setValue(getSwapUsed());
    total.display(win);
    title.display(win);
    ramPercent.display(win);
    swapPercent.display(win);
}

int MemoryModule::getColor(int x, int y) const
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

void MemoryModule::displayNcurse(sf::Vector2f vec)
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
    Ncurses::Text title("MEMORY INFORMATIONS", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 8);
    Ncurses::Text text1("Total RAM", std::to_string(this->getRamTotal() / 1000.0) + " Gb", y + 5, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Bar ramPercent("RAM ", getRamTotal(), (xMax / 2) - 4, y + 7, x + 3, "%%");
    Ncurses::Bar swapPercent("SWAP", getSwapTotal(), (xMax / 2) - 4, y + 9, x + 3, "%%");
    ramPercent.setValue(getRamUsed());
    swapPercent.setValue(getSwapUsed());
    ramPercent.display();
    swapPercent.display();
    text1.display();
    title.display();
    c.display();
}

int MemoryModule::getRamTotal(void) const
{
    try {
        return Values.at("MemTotal") / 1000;
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getRamFree(void) const
{
    try {
        return Values.at("MemAvailable") / 1000;
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getRamUsed(void) const
{
    try {
        return (Values.at("MemTotal") - Values.at("MemAvailable")) / 1000;
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getRamPercent(void) const
{
    try {
        float total = getRamTotal();

        if (!total)
            return 0;
        return (int)((getRamUsed() / total) * 100);
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getSwapTotal(void) const
{
    try {
        return Values.at("SwapTotal") / 1000;
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getSwapFree(void) const
{
    try {
        return Values.at("SwapFree") / 1000;
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getSwapUsed(void) const
{
    try {
        return getSwapTotal() - getSwapFree();
    } catch (...) {
        return 0;
    }
}

int MemoryModule::getSwapPercent(void) const
{
    try {
        float total = getSwapTotal();

        if (!total)
            return 0;
        return (int)((getSwapUsed() / total) * 100);
    } catch (...) {
        return 0;
    }
}

void MemoryModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
}
