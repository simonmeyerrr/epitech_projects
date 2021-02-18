/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** IMonitorDisplay.hpp
*/

#ifndef CPP_RUSH3_2018_IMONITORDISPLAY_HPP_
# define CPP_RUSH3_2018_IMONITORDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include "../MonitorModule/IMonitorModule.hpp"
#include "../MonitorCore/Settings.hpp"

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay() = default;

    virtual void refreshWindow(IMonitorModule **modules, Settings settings) = 0;
    virtual sf::RenderWindow *getWindow() = 0;
};

IMonitorDisplay *createMonitorDisplay(Types::DisplayMode mode);

#endif /* CPP_RUSH3_2018_IMONITORDISPLAY_HPP_ */
