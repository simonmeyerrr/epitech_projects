/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class file
*/

#include <fstream>
#include <iostream>
#include <zconf.h>
#include <unordered_map>
#include <ncurses.h>
#include "InfoModule.hpp"
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

InfoModule::InfoModule()
{
    this->refresh();
}

void InfoModule::refresh(void)
{
    this->Values = std::unordered_map<std::string, std::string>();
    refreshVersion();
    refreshTime();
    refreshUser();
}

Types::Modules InfoModule::getModuleType() const
{
    return (Types::INFO);
}

void InfoModule::refreshVersion(void)
{
    std::ifstream fkernel("/proc/sys/kernel/osrelease");
    std::ifstream fos("/etc/os-release");

    std::string s;
    std::string os;
    std::string ve;

    while (getline(fos, s, '\n')) {
        if (s.find("NAME=") != std::string::npos && os.empty()) {
            os = s.substr(s.find('=') + 1);
        }
        if (s.find("VERSION=") != std::string::npos && ve.empty()) {
            s.pop_back();
            ve = s.substr(s.find('"') + 1);
        }
    }
    Values["os"] = os;
    Values["osversion"] = ve;
    fkernel >> s;
    Values["kernel"] = s;
}

void InfoModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    SFML::Text text1("Informations", "", 20 + (505 * vec.x), 5 + (505 * vec.y),
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    SFML::Text text2("Username: ", getUsername(), 20 + (505 * vec.x),
        80 + (505 * vec.y));
    SFML::Text text3("Hostname: ", getHostname(), 20 + (505 * vec.x),
        120 + (505 * vec.y));
    SFML::Text text4("Date: ", getDateTime(), 20 + (505 * vec.x),
        160 + (505 * vec.y));
    SFML::Text text5("Os: ", getOs(), 20 + (505 * vec.x), 200 + (505 * vec.y));
    SFML::Text text6("OsVersion: ", getOsVersion(), 20 + (505 * vec.x),
        240 + (505 * vec.y));
    SFML::Text text7("Kernel: ", getKernel(), 20 + (505 * vec.x),
        280 + (505 * vec.y));
    SFML::Text text8("Uptime: ", getUpTime(), 20 + (505 * vec.x),
        320 + (505 * vec.y));
    text1.display(win);
    text2.display(win);
    text3.display(win);
    text4.display(win);
    text5.display(win);
    text6.display(win);
    text7.display(win);
    text8.display(win);
}

int InfoModule::getColor(int x, int y) const
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

void InfoModule::displayNcurse(sf::Vector2f vec)
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
    Ncurses::Text text1("INFORMATIONS", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text2("Username", getUsername(), y + 5, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text3("Hostname", getHostname(), y + 7, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text4("Date", getDateTime(), y + 9, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text5("Os", getOs(), y + 11, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text6("OsVersion", getOsVersion(), y + 13, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text7("Kernel", getKernel(), y + 15, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    Ncurses::Text text8("Uptime", getUpTime(), y + 17, x + 6,
        getColor(vec.x, vec.y) + 50, 7);
    text1.display();
    text2.display();
    text3.display();
    text4.display();
    text5.display();
    text6.display();
    text7.display();
    text8.display();
    c.display();
}

std::string InfoModule::getKernel(void) const
{
    try {
        return this->Values.at("kernel");
    } catch (...) {
        return std::string("");
    }
}

std::string InfoModule::getOs(void) const
{
    try {
        return this->Values.at("os");
    } catch (...) {
        return std::string("");
    }
}

std::string InfoModule::getOsVersion(void) const
{
    try {
        return this->Values.at("osversion");
    } catch (...) {
        return std::string("");
    }
}

void InfoModule::refreshTime(void)
{
    std::ifstream fup("/proc/uptime");
    std::string uptime;

    fup >> uptime;
    this->Values["uptime"] = uptime;
    time_t now = time(nullptr);
    this->Values["datetime"] = std::string(ctime(&now));
}

std::string InfoModule::getUpTime(void) const
{
    int rawtime = (int)stol(this->Values.at("uptime"));
    std::string str = "";
    int days = 0;
    int hours = 0;
    int minuts = 0;

    days = rawtime / (3600 * 24);
    rawtime %= (3600 * 24);
    hours = rawtime / 3600;
    rawtime %= 3600;
    minuts = rawtime / 60;
    rawtime %= 60;

    if (days)
        str += ("Since " + std::to_string(days) + "days,\n");
    if (hours)
        str += (std::to_string(hours) + " h ");
    if (minuts)
        str += (std::to_string(minuts) + " m ");
    str += (std::to_string(rawtime) + " s");

    return str;
}

std::string InfoModule::getDateTime(void) const
{
    try {
        return this->Values.at("datetime");
    } catch (...) {
        return std::string("");
    }
}

std::string InfoModule::getHostname(void) const
{
    try {
        return this->Values.at("hostname");
    } catch (...) {
        return std::string("");
    }
}

std::string InfoModule::getUsername(void) const
{
    try {
        return this->Values.at("username");
    } catch (...) {
        return std::string("");
    }
}

void InfoModule::refreshUser(void)
{
    char buff[255] = {0};
    std::ifstream fhost("/proc/sys/kernel/hostname");
    std::string hostname;

    fhost >> hostname;
    this->Values["hostname"] = hostname;

    getlogin_r(buff, 254);
    this->Values["username"] = std::string(buff);
}

void InfoModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
}
