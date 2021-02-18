/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorNcurse.hpp
*/

#ifndef CPP_RUSH3_2018_MONITORNCURSE_HPP_
# define CPP_RUSH3_2018_MONITORNCURSE_HPP_

#include <SFML/Graphics.hpp>
#include "../IMonitorDisplay.hpp"

class MonitorNcurse : public IMonitorDisplay {
public:
    ~MonitorNcurse();
    MonitorNcurse();

    void refreshWindow(IMonitorModule **modules, Settings settings);
    sf::RenderWindow *getWindow();

    void noneModule(sf::Vector2f vec) const;
    void displayFooter() const;
    int getColor(int x, int y) const;
    bool resMin() const;
};

#endif /* CPP_RUSH3_2018_MONITORNCURSE_HPP_ */
