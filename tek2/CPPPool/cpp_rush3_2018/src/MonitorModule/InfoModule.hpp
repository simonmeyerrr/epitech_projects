/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class header
*/

#ifndef CPP_RUSH3_2018_INFOMODULE_HPP
#define CPP_RUSH3_2018_INFOMODULE_HPP


#include <unordered_map>
#include "IMonitorModule.hpp"

class InfoModule : public IMonitorModule
{
public:
    InfoModule();
    void refresh(void) override;
    Types::Modules getModuleType() const;
    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);

    std::string getKernel(void) const;
    std::string getOs(void) const;
    std::string getOsVersion(void) const;
    std::string getDateTime(void) const;
    std::string getHostname(void) const;
    std::string getUsername(void) const;
    std::string getUpTime(void) const;
    int getColor(int x, int y) const;

private:
    void refreshVersion(void);
    void refreshTime(void);
    void refreshUser(void);

    std::unordered_map<std::string, std::string> Values;
};


#endif //CPP_RUSH3_2018_INFOMODULE_HPP
