/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorCore.hpp
*/

#ifndef CPP_RUSH3_2018_MONITORCORE_HPP_
# define CPP_RUSH3_2018_MONITORCORE_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include "SFML/System/Time.hpp"
# include <iostream>
# include <string>
# include <time.h>
# include "../MonitorDisplay/IMonitorDisplay.hpp"
# include "../MonitorModule/IMonitorModule.hpp"
# include "../MonitorEvent/IMonitorEvent.hpp"
# include "Settings.hpp"

class MonitorCore {
public:
    ~MonitorCore();
    MonitorCore(Types::DisplayMode, Types::Modules *);

    void getEvent();
    void updateModule();
    void refreshDisplay();

private:
    Settings _settings;

    IMonitorDisplay *_display;
    IMonitorEvent *_event;
    IMonitorModule *_modules[4];

    sf::Clock _refreshTime;
    sf::Clock _updateTime;
};

#endif /* CPP_RUSH3_2018_MONITORCORE_HPP_ */
