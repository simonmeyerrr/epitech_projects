#include "LowMonsters.hpp"
#include <iostream>

LowMonsters::LowMonsters()
{
    _textures.loadFromFile(ASSETS_PATH_STR"Monster.png");
    _sprites.setTexture(_textures);
    _rect = sf::IntRect({0, 0}, {65, 50});
}

void LowMonsters::render(sf::RenderWindow &win, sf::Vector2f pos)
{
    _sprites.setPosition(pos);
    _sprites.setTextureRect(_rect);
    _sprites.setScale(2, 2);
    win.draw(_sprites);
}

void LowMonsters::update()
{
    static int times = 0;
    times++;
    if (times == 3) {
        times = 0;
        _rect.left += 65;
        if (_rect.left == 390)
            _rect.left = 0;
    }
}

