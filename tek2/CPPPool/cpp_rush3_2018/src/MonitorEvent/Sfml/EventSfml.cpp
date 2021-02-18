/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorSfml.cpp
*/

#include <iostream>
#include "EventSfml.hpp"
#include "../../MonitorDisplay/Sfml/MonitorSfml.hpp"

bool EventSfml::manageKey(sf::Event &event, sf::RenderWindow *win,
    Settings &settings, IMonitorModule **modules)
{
    (void)modules;
    if (event.key.code == sf::Keyboard::Escape ||
        event.key.code == sf::Keyboard::Q) {
        win->close();
        settings.closeProg();
        return (false);
    }
    if (event.key.code == sf::Keyboard::S) {
        win->close();
        settings.setDisplayMode(Types::NCURSE);
        return (true);
    }
    return (false);
}

void EventSfml::changeModule(IMonitorModule **modules, int i,
    Types::Offset offset)
{
    Types::Modules type = Types::NONE;
    if (modules[i])
        type = modules[i]->getModuleType();

    delete modules[i];
    modules[i] = createMonitorModule(type, offset);
}

bool EventSfml::manageMouse(sf::Event &event, Settings &settings,
    IMonitorModule **modules)
{
    int mouse_x = event.mouseButton.x;
    int mouse_y = event.mouseButton.y;

    for (int i = 0; i < 4; i++) {
        int elem_x = i % 2;
        int elem_y = i / 2;
        if (mouse_x >= elem_x * 505 + 400 && mouse_x < elem_x * 505 + 450 &&
            mouse_y >= elem_y * 505 && mouse_y < elem_y * 505 + 50)
            changeModule(modules, i, Types::LEFT);
        if (mouse_x >= elem_x * 505 + 450 && mouse_x < elem_x * 505 + 500 &&
            mouse_y >= elem_y * 505 && mouse_y < elem_y * 505 + 50)
            changeModule(modules, i, Types::RIGHT);
        if (mouse_x >= elem_x * 505 && mouse_x < elem_x * 505 + 500 &&
            mouse_y >= elem_y * 505 + 50 && mouse_y < elem_y * 505 + 500 &&
            modules[i]) {
            modules[i]->clickOnMy(
                sf::Vector2f(mouse_x - 505 * elem_x, mouse_y - 505 * elem_y),
                settings.getDisplayMode());
        }
    }
    return (false);
}

bool EventSfml::get(IMonitorDisplay *display, IMonitorModule **modules,
    Settings &settings)
{
    (void)modules;
    sf::Event event;
    sf::RenderWindow *win = display->getWindow();
    if (!win)
        return (false);
    while (win->pollEvent(event)) {
        if (event.type == sf::Event::EventType::Closed) {
            win->close();
            settings.closeProg();
            return (false);
        }
        if (event.type == sf::Event::EventType::KeyPressed)
            return (manageKey(event, win, settings, modules));
        if (event.type == sf::Event::EventType::MouseButtonPressed)
            return (manageMouse(event, settings, modules));
    }
    return (false);
}
