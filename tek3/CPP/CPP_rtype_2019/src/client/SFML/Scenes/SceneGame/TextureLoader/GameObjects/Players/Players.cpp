//
// Created by hugo on 11/26/19.
//

#include <iostream>
#include "Players.hpp"

void Players::render(sf::RenderWindow &win, sf::Vector2f pos)
{
    _sprites.setPosition(pos);
    if (pos.y > _lastPos.y) {
        _rect.left = 33;
    } else if (pos.y < _lastPos.y) {
        _rect.left = 99;
    } else {
        _rect.left = 66;
    }
    _sprites.setTextureRect(_rect);
    _sprites.setScale(3, 3);
    win.draw(_sprites);
    _lastPos = pos;
}

void Players::update() {

}
