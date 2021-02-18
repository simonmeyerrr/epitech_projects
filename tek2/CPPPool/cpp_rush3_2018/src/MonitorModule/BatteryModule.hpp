/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** BatteryModule
*/

#ifndef BATTERYMODULE_HPP_
#define BATTERYMODULE_HPP_

#include "IMonitorModule.hpp"

class BatteryModule : public IMonitorModule {
public:
    ~BatteryModule();
    BatteryModule();

    void refresh() override;
    Types::Modules getModuleType() const;

    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);
    int getColor(int x, int y) const;

    void getBatteryInfo(int i);
private:
    std::vector<std::string> V;
};

#endif
