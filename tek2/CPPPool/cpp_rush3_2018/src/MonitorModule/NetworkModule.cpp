/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** Network Module
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <ncurses.h>
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "NetworkModule.hpp"
#include "CpuModule.hpp"
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

NetworkModule::NetworkModule()
: _interface("Interface Not found"), _rxBytes(0), _rxPackets(0), _txBytes(0), _txPackets(0)
{
    this->refresh();
}

NetworkModule::~NetworkModule()
{
}

void NetworkModule::refresh()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    int empty;

    if (file.fail())
        std::cerr << "File not found : /proc/net/dev" << std::endl;
    else {
        for (int i = 0; i < 5; i++) {
            std::getline(file, line);
        }
        std::getline(file, line);
        std::stringstream s(line);
        s >> _interface >> _rxBytes >> _rxPackets >> empty >> empty >> empty >>
        empty >> empty >> empty >> _txBytes >> _txPackets;
    }
}

Types::Modules NetworkModule::getModuleType() const
{
    return (Types::NETWORK);
}

void NetworkModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    SFML::Text text1("Network", "", 20 + (505 * vec.x), 5 + (505 * vec.y),
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    text1.display(win);
    SFML::Text text2("Interface:", getInterface(), 10 + (505 * vec.x), 100 +
    (505 * vec.y));
    text2.display((win));
    SFML::Text text3("Received bytes:       ", std::to_string(getRxBytes()),
        10 + (505 * vec.x), 150 + (505 * vec.y));
    text3.display((win));
    SFML::Text text4("Received packets:    ", std::to_string(getRxPackets()),
        10 + (505 * vec.x), 200 + (505 * vec.y));
    text4.display((win));
    SFML::Text text5("Transmitted bytes:   ", std::to_string(getTxBytes()),
        10 + (505 * vec.x), 250 + (505 * vec.y));
    text5.display((win));
    SFML::Text text6("Transmitted packets:", std::to_string(getTxPackets()),
        10 + (505 * vec.x), 300 + (505 * vec.y));
    text6.display((win));
}

int NetworkModule::getColor(int x, int y) const
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

void NetworkModule::displayNcurse(sf::Vector2f vec)
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

    Ncurses::Text title("NETWORK", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 8);
    Ncurses::Text text2("Interface",
        getInterface(), y + 5, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text2.display();
    Ncurses::Text text3("Received bytes",
        std::to_string(getRxBytes()), y + 7, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text3.display();
    Ncurses::Text text4("Received packets",
        std::to_string(getRxPackets()), y + 9, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text4.display();
    Ncurses::Text text5("Transmitted bytes",
        std::to_string(getTxBytes()), y + 11, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text5.display();
    Ncurses::Text text6("Transmitted packets",
        std::to_string(getTxPackets()), y + 13, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text6.display();
    title.display();
    c.display();
}

void NetworkModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
}
