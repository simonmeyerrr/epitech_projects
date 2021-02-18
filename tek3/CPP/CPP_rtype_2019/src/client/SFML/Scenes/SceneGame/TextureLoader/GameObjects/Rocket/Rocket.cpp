//
// Created by hugo on 11/27/19.
//

#include "Rocket.hpp"

void Rocket::render(sf::RenderWindow &win, sf::Vector2f pos)
{
    _sprites.setPosition(pos);
    _sprites.setScale(3,3);
    win.draw(_sprites);
}

void Rocket::update()
{

}
