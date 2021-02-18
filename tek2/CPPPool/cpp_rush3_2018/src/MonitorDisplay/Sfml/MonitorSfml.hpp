/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorSfml.hpp
*/

#ifndef CPP_RUSH3_2018_MONITORSFML_HPP_
# define CPP_RUSH3_2018_MONITORSFML_HPP_

#include "../IMonitorDisplay.hpp"

class MonitorSfml : public IMonitorDisplay {
public:
    ~MonitorSfml();
    MonitorSfml();

    void refreshWindow(IMonitorModule **modules, Settings settings);
    sf::RenderWindow *getWindow();

private:
    void displayModule(int x, int y, IMonitorModule *module);
    void displayButton(int x, int y, int offset, bool left, sf::Vector2i mouse);

    sf::RenderWindow *_win;
};

#endif /* CPP_RUSH3_2018_MONITORSFML_HPP_ */
