/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** DanModule.hpp
*/

#ifndef CPP_RUSH3_2018_DANMODULE_HPP_
# define CPP_RUSH3_2018_DANMODULE_HPP_

#include <vector>
#include "IMonitorModule.hpp"

class DanModule : public IMonitorModule {
public:
    DanModule();
    ~DanModule();

    void refresh() override;
    Types::Modules getModuleType() const;

    void displaySfml(sf::RenderWindow *win, sf::Vector2f vec);
    void displayNcurse(sf::Vector2f vec);

    void clickOnMy(sf::Vector2f pos, Types::DisplayMode);
    int getColor(int x, int y) const;

private:
    std::vector<sf::Vector2f> _pos;
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif /* CPP_RUSH3_2018_DANMODULE_HPP_ */
