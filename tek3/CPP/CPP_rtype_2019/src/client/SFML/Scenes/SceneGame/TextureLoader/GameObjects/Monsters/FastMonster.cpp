//
// Created by hugo on 11/30/19.
//

#include "FastMonster.hpp"

FastMonsters::FastMonsters()
{
    _textures.loadFromFile(ASSETS_PATH_STR"Monster2.png");
    _sprites.setTexture(_textures);
    _rect = sf::IntRect({0, 0}, {33, 36});
}

void FastMonsters::render(sf::RenderWindow &win, sf::Vector2f pos)
{
    _sprites.setPosition(pos);
    _sprites.setTextureRect(_rect);
    _sprites.setScale(2, 2);
    win.draw(_sprites);
}

void FastMonsters::update()
{
    static int times = 0;
    times++;
    if (times == 3) {
        times = 0;
        _rect.left += 33;
        if (_rect.left == 264)
            _rect.left = 0;
    }
}
