/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class file
*/

#include <fstream>
#include <limits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <ncurses.h>
#include "CpuModule.hpp"
#include "../MonitorDisplay/Sfml/Bar.hpp"
#include "../MonitorDisplay/Sfml/Text.hpp"
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

CpuModule::CpuModule()
{
    this->refresh();
}

void CpuModule::trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void CpuModule::addMaxSpeedInfo(void)
{
    std::ifstream f;
    std::string freq;

    for (unsigned i = 0; i < this->Processors.size(); i++) {
        f = std::ifstream("/sys/devices/system/cpu/cpu" + std::to_string(i) +
            "/cpufreq/scaling_max_freq");
        f >> freq;
        this->Processors[i]["maxSpeed"] = freq;
    }
}

void CpuModule::refresh()
{
    Processors = std::vector<std::unordered_map<std::string, std::string>>();
    std::ifstream f("/proc/cpuinfo");

    std::string line;
    std::string val;
    std::string key;
    std::unordered_map<std::string, std::string> proc;

    do {
        proc = std::unordered_map<std::string, std::string>();
        while (getline(f, line, '\n') && !line.empty()) {
            key = line.substr(0, line.find(':'));
            val = line.substr(line.find(':') + 1);
            trim(key);
            trim(val);
            proc[key] = val;
        }
        this->Processors.push_back(proc);
    } while (getline(f, line, '\n'));
    addMaxSpeedInfo();
}

Types::Modules CpuModule::getModuleType() const
{
    return (Types::CPU);
}

void CpuModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    auto xOrigin = (unsigned)(505 * vec.x);
    auto yOrogin = (unsigned)(505 * vec.y);
    SFML::Text title("CPU informations", "", 20 + xOrigin, 5 + yOrogin,
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    auto fullcpu = SFML::Bar("CPU average", getMaxSpeed(0), xOrigin + 10,
        yOrogin + 100, "Mhz");

    for (int i = 0; i < this->getNumber(); i++) {
        auto tmpcpu = SFML::Bar("CPU " + std::to_string(i + 1), getMaxSpeed(i),
            xOrigin + 10, yOrogin + 150 + 50 * i, "Mhz");
        tmpcpu.setValue((getUsage(i) * getMaxSpeed(0)) / 100);
        tmpcpu.display(win);
    }
    title.display(win);
    fullcpu.setValue((getTotalUsage() * getMaxSpeed(0)) / 100);
    fullcpu.display(win);
}

int CpuModule::getColor(int x, int y) const
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

void CpuModule::displayNcurse(sf::Vector2f vec)
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
    Ncurses::Text title("CPU INFORMATIONS", "", y + 2, x + 3,
        getColor(vec.x, vec.y) + 50, 8);
    Ncurses::Bar cpuUsage("CPU average", getMaxSpeed(0),
        (xMax / 2) - 4, y + 5, x + 3, "%%");
    cpuUsage.setValue((getTotalUsage() * getMaxSpeed(0)) / 100);
    for (int i = 0; i < this->getNumber(); i++) {
        int yTmp = 7;
        for (int j = 0; j < i; j++)
            yTmp += 2;
        Ncurses::Bar tmpcpu("CPU " + std::to_string(i + 1) + "      ",
            getMaxSpeed(i), (xMax / 2) - 4, y + yTmp, x + 3, "%%");
        tmpcpu.setValue((getUsage(i) * getMaxSpeed(0)) / 100);
        tmpcpu.display();
    }
    c.display();
    title.display();
    cpuUsage.display();
}

int CpuModule::getNumber() const
{
    try {
        return (int)Processors.size();
    } catch (...) {
        return -1;
    }
}

int CpuModule::getSpeed(int index) const
{
    try {
        return (int)std::stol(Processors[index].at("cpu MHz"));
    } catch (...) {
        return -1;
    }
}

int CpuModule::getMaxSpeed(int index) const
{
    try {
        return (int)std::stol(Processors[index].at("maxSpeed")) / 1000;
    } catch (...) {
        return -1;
    }
}

int CpuModule::getUsage(int index) const
{
    try {
        float maxSpeed = getMaxSpeed(index);
        float speed = getSpeed(index);

        if (maxSpeed == 0 || !speed)
            return 0;
        return (int)((speed / maxSpeed) * 100);
    } catch (...) {
        return -1;
    }
}

int CpuModule::getTotalUsage(void) const
{
    try {
        float total = 0;

        for (unsigned i = 0; i < this->Processors.size(); i++)
            total += getUsage(i);
        return (int)(total / this->Processors.size());
    } catch (...) {
        return -1;
    }
}

std::string CpuModule::getName(void) const
{
    try {
        return this->Processors[0].at("model name");
    } catch (std::exception const &e) {
        return "Unknown";
    }
}

void CpuModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
}
