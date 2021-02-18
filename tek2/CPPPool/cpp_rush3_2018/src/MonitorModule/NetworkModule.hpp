/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** hpp
*/

#ifndef NETWORKMODULE_H
#define NETWORKMODULE_H

#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
private:
    std::string _interface;
    long long int _rxBytes;
    long long int _rxPackets;
    long long int _txBytes;
    long long int _txPackets;
public:
    NetworkModule();
    ~NetworkModule();
    void refresh();
    Types::Modules getModuleType() const;

    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);
    int getColor(int x, int y) const;

    const std::string &getInterface() const { return (_interface); }
    long long int getRxBytes(void) const { return (_rxBytes); }
    long long int getRxPackets(void) const { return (_rxPackets); }
    long long int getTxBytes(void) const { return (_txBytes); }
    long long int getTxPackets(void) const { return (_txPackets); }
};


#endif
