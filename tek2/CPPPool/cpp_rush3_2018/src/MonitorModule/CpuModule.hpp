/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class header
*/

#ifndef CPP_RUSH3_2018_CPUMODULE_HPP
#define CPP_RUSH3_2018_CPUMODULE_HPP


#include <unordered_map>
#include <vector>
#include "IMonitorModule.hpp"

class CpuModule : public IMonitorModule
{
public:
    CpuModule();
    ~CpuModule() = default;

    void refresh() override;
    Types::Modules getModuleType() const ;
    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec) override ;
    void displayNcurse(sf::Vector2f vec) override ;
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);

    int getNumber() const;
    int getSpeed(int index) const;
    int getMaxSpeed(int index) const;
    int getUsage(int index) const;
    int getTotalUsage(void) const;
    int getColor(int x, int y) const;
    std::string getName(void) const;
    void trim(std::string &s);

private:
    void addMaxSpeedInfo(void);
    std::vector<std::unordered_map<std::string, std::string>> Processors;
};


#endif //CPP_RUSH3_2018_CPUMODULE_HPP
