/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Class header
*/

#ifndef TESTRUSH3_MEMORYMODULE_HPP
#define TESTRUSH3_MEMORYMODULE_HPP


#include <unordered_map>
#include <string>
#include "IMonitorModule.hpp"

class MemoryModule : public IMonitorModule
{
public:
    MemoryModule();
    ~MemoryModule() = default;

    void refresh() override;
    Types::Modules getModuleType() const;
    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);
    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);

    int getRamTotal(void) const;
    int getRamUsed(void) const;
    int getRamPercent(void) const;
    int getRamFree(void) const;

    int getSwapTotal(void) const;
    int getSwapUsed(void) const;
    int getSwapPercent(void) const;
    int getSwapFree(void) const;
    int getColor(int x, int y) const;

private:
    std::unordered_map<std::string, int> Values;
};


#endif //TESTRUSH3_MEMORYMODULE_HPP
