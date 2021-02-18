/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorCore.cpp
*/

#include <zconf.h>
#include "MonitorCore.hpp"

MonitorCore::~MonitorCore()
{
    delete _display;
    delete _event;
    for (int i = 0; i < 4; i++)
        delete _modules[i];
}

MonitorCore::MonitorCore(Types::DisplayMode mode, Types::Modules *modules)
    : _settings(mode)
{
    _display = createMonitorDisplay(mode);
    _event = createMonitorEvent(mode);
    for (int i = 0; i < 4; i++)
        _modules[i] = createMonitorModule(modules[i]);

    while (_settings.isLaunched()) {
        getEvent();
        updateModule();
        refreshDisplay();
    }
}

void MonitorCore::getEvent()
{
    if (_event->get(_display, _modules, _settings)) {
        delete _display;
        delete _event;
        _display = createMonitorDisplay(_settings.getDisplayMode());
        _event = createMonitorEvent(_settings.getDisplayMode());
    }
}

void MonitorCore::updateModule()
{
    sf::Time elapsed = _updateTime.getElapsedTime();
    if (elapsed.asMicroseconds() / 1000000.0 > 1.0 / 2.0 ) {
        for (int i = 0; i < 4; i++) {
            if (_modules[i])
                _modules[i]->refresh();
        }
        _updateTime.restart();
    }
}

void MonitorCore::refreshDisplay()
{
    sf::Time elapsed = _refreshTime.getElapsedTime();
    if (elapsed.asMicroseconds() / 1000000.0 > 1.0 / 30.0) {
        _display->refreshWindow(_modules, _settings);
        _refreshTime.restart();
    }
}
