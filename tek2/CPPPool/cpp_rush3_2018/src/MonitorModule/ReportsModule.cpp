/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** REPORTS
*/

#include "../MonitorDisplay/Sfml/Text.hpp"
#include "ReportsModule.hpp"
#include "NetworkModule.hpp"
#include "MemoryModule.hpp"
#include "InfoModule.hpp"
#include "IMonitorModule.hpp"
#include "CpuModule.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ncurses.h>
#include "../MonitorDisplay/Ncurse/Bar.hpp"
#include "../MonitorDisplay/Ncurse/Text.hpp"
#include "../MonitorDisplay/Ncurse/Container.hpp"

ReportsModule::~ReportsModule()
{}

ReportsModule::ReportsModule()
{}

void ReportsModule::refresh()
{}

//flag curl  : -n --ssl-reqd (optionnel)
void ReportsModule::sendLogTxt()
{
    InfoModule info;
    NetworkModule net;
    MemoryModule mem;
    CpuModule cpu;

    std::ofstream file("file.txt");
    if(file.is_open()) {
        file << "Gkrellm EPITECH" << std::endl;
        file << "" <<std::endl;

        file << "*** Informations about System ***" << std::endl;
        file << "Kernel : " << info.getKernel() << std::endl;
        file << "Os : " << info.getOs() << std::endl;
        file << "Os Version : " << info.getOsVersion() << std::endl;
        file << "Hostname : " << info.getHostname() << std::endl;
        file << "Username : " << info.getUsername() << std::endl;
        file << "Date & Time : " << info.getDateTime() << std::endl;

        file << "*** Informations about CPU ***" << std::endl;
        file << "Model : " << cpu.getName() << std::endl;
        file << "Number : " << cpu.getNumber() << std::endl;
        file << "Usage : " << cpu.getTotalUsage() << "\n" << std::endl;

        file << "*** Informations about Memory ***" << std::endl;;
        file << "Total Ram : " << mem.getRamTotal() << std::endl;
        file << "Ram Used : " << mem.getRamUsed() << std::endl;
        file << "% Ram : " << mem.getRamPercent() << std::endl;
        file << "Ram Free : " << mem.getRamFree() << std::endl;
        file << "Total Swap : " << mem.getSwapTotal() << std::endl;
        file << "Swap Used : " << mem.getSwapUsed() << std::endl;
        file << "% Swap : " << mem.getSwapPercent() << std::endl;
        file << "Swap Free : " << mem.getSwapFree() << "\n" << std::endl;

        file << "*** Informations about Network ***" << std::endl;
        file << "Interface : " << net.getInterface() << std::endl;
        file << "Received Bytes : " << net.getRxBytes() << std::endl;
        file << "Received Packets : " << net.getRxPackets() << std::endl;
        file << "Transmitted Bytes : " << net.getTxBytes() << std::endl;
        file << "Trasmitted Packets : " << net.getTxPackets() << std::endl;
    }
    system("curl -u gkrellmepitech@gmail.com:gkrellm123 --mail-from gkrellmepitech@gmail.com --mail-rcpt jules.bozouklian@epitech.eu --url smtps://smtp.gmail.com:465 -T file.txt --silent");
    system("rm file.txt");
}

void ReportsModule::sendLogHtml()
{
    InfoModule info;
    NetworkModule net;
    MemoryModule mem;
    CpuModule cpu;

    std::ofstream file("index.html");
    if(file.is_open()) {
        file << "<!DOCTYPE html>" << std::endl;
        file << "<html>" << std::endl;
        file << "<body>" << std::endl;

        file << "<head>" << std::endl;
        file << "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css'>" << std::endl;
        file << "<title>Gkrellm</title>" << std::endl;
        file << "<link rel='icon' type='image/png' href='assets/dan.png' />" << std::endl;
        file << "</head>" << std::endl;

        file << "<div class='container'>" << std::endl;
        file << "</br>" << std::endl;
        file << "<div class='card'>" << std::endl;
        file << "<div class='card-body'>" << std::endl;
        file << "<h2>Informations : </h2>" << std::endl;
        file << "<p>" << "Kernel : " << info.getKernel() << "</p>" << std::endl;
        file << "<p>" << "Os : " << info.getOs() << "</p>" << std::endl;
        file << "<p>" << "Os Version : " << info.getOsVersion() << "</p>" << std::endl;
        file << "<p>" << "Hostname : " << info.getHostname() << "</p>" << std::endl;
        file << "<p>" << "Username : " << info.getUsername() << "</p>" << std::endl;
        file << "<p>" << "Date & Time : " << info.getDateTime() << "</p>" << std::endl;
        file << "</div>" << std::endl;
        file << "</div>" << std::endl;
        file << "</br>" << std::endl;

        file << "<div class='card'>" << std::endl;
        file << "<div class='card-body'>" << std::endl;
        file << "<h2>CPU :  </h2>" << std::endl;
        file << "<p>" << "Model : " << cpu.getName() << "</p>" << std::endl;
        file << "<p>" << "Number : " << cpu.getNumber() << "</p>" << std::endl;
        file << "<p>" << "Usage : " << cpu.getTotalUsage() << "</p>" << std::endl;
        file << "</div>" << std::endl;
        file << "</div>" << std::endl;
        file << "</br>" << std::endl;

        file << "<div class='card'>" << std::endl;
        file << "<div class='card-body'>" << std::endl;
        file << "<h2>RAM : </h2>" << std::endl;
        file << "<p>" << "Total Ram : " << mem.getRamTotal() << "</p>" << std::endl;
        file << "<p>" << "Ram Used : " << mem.getRamUsed() << "</p>" << std::endl;
        file << "<p>" << "% Ram : " << mem.getRamPercent() << "</p>" << std::endl;
        file << "<p>" << "Ram Free : " << mem.getRamFree() << "</p>" << std::endl;
        file << "<p>" << "Total Swap : " << mem.getSwapTotal() << "</p>" << std::endl;
        file << "<p>" << "Swap Used : " << mem.getSwapUsed() << "</p>" << std::endl;
        file << "<p>" << "% Swap : " << mem.getSwapPercent() << "</p>" << std::endl;
        file << "<p>" << "Swap Free : " << mem.getSwapFree() << "</p>" << std::endl;
        file << "</div>" << std::endl;
        file << "</div>" << std::endl;
        file << "</br>" << std::endl;

        file << "<div class='card'>" << std::endl;
        file << "<div class='card-body'>" << std::endl;
        file << "<h2>Network : </h2>" << std::endl;
        file << "<p>" << "Interface : " << net.getInterface() << "</p>" << std::endl;
        file << "<p>" << "Received Bytes : " << net.getRxBytes() << "</p>" << std::endl;
        file << "<p>" << "Received Packets : " << net.getRxPackets() << "</p>" << std::endl;
        file << "<p>" << "Transmitted Bytes : " << net.getTxBytes() << "</p>" << std::endl;
        file << "<p>" << "Transmitted Packets : " << net.getTxPackets() << "</p>" << std::endl;
        file << "</div>" << std::endl;
        file << "</div>" << std::endl;
        file << "</br>" << std::endl;
        file << "<a href='https://www.youtube.com/watch?v=gxrjIvJ5ydw' target='_blank'> <img class='img-fluid rounded' src='https://upload.wikimedia.org/wikipedia/commons/2/2d/Epitech.png' /></a>" << std::endl;
        file << "</div>" << std::endl;
        file << "</body>" << std::endl;
        file << "</html>" << std::endl;
    }
}

Types::Modules ReportsModule::getModuleType() const
{
    return (Types::REPORTS);
}

void ReportsModule::displaySfml(sf::RenderWindow *win, sf::Vector2f vec)
{
    SFML::Text text("Reports", "", 10 + (505 * vec.x), 5 + (505 * vec.y),
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    text.display(win);
    SFML::Text text2("Generate Mail and Html", "", 80 + (505 * vec.x),
        230 + (505 * vec.y),
        sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
    text2.display(win);
}

int ReportsModule::getColor(int x, int y) const
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

void ReportsModule::displayNcurse(sf::Vector2f vec)
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
    Ncurses::Text title("REPORTS", "Click to generate Mail and Html.",
        y + 2, x + 3, getColor(vec.x, vec.y) + 50, 7);
    c.display();
    title.display();
}

void ReportsModule::clickOnMy(sf::Vector2f pos, Types::DisplayMode mode)
{
    (void)pos;
    (void)mode;
    sendLogTxt();
    sendLogHtml();
}
