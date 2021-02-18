/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** Module REPORTS
*/

#ifndef ReportsModule_HPP_
#define ReportsModule_HPP_

#include "IMonitorModule.hpp"

class ReportsModule : public IMonitorModule
{
public:
    ~ReportsModule();
    ReportsModule();

    void refresh() override;
    void sendLogTxt();
    void sendLogHtml();
    Types::Modules getModuleType() const;

    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);
    int getColor(int x, int y) const;
private:
};

#endif
