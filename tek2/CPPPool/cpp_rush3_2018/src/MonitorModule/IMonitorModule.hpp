/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Header file
*/

#ifndef TESTRUSH3_IMONITORMODULE_HPP
#define TESTRUSH3_IMONITORMODULE_HPP

# include "../MonitorCore/Settings.hpp"
# include <SFML/Graphics.hpp>

class IMonitorModule {
public:
    virtual ~IMonitorModule() = default;

    virtual Types::Modules getModuleType() const = 0;
    virtual void refresh() = 0;

    virtual void displaySfml(sf::RenderWindow *, sf::Vector2f) = 0;
    virtual void displayNcurse(sf::Vector2f) = 0;

    virtual void clickOnMy(sf::Vector2f, Types::DisplayMode) = 0;
};

IMonitorModule *createMonitorModule(Types::Modules mode,
    Types::Offset offset = Types::NORMAL);

#endif //TESTRUSH3_IMONITORMODULE_HPP
