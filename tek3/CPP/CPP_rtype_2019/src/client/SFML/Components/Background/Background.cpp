//
// Created by hugo on 11/25/19.
//

#include <iostream>
#include "Background.hpp"

Background::Background()
: AComponent(0)
{
    _texture.loadFromFile(ASSETS_PATH_STR"Star.png");
    _sprite.setTexture(_texture);

    for (int i = 0; i < MAX_STARS; i++) {
        int rand = std::rand() % 5 + 1;

        _stars[i].pos = sf::Vector2f(std::rand() % WINDOW_WIDTH + WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT);
        _stars[i].rotation = 0;
        switch (rand) {
            case 1:
                _stars[i].size = {1,1};
                _stars[i].speed = 2.5;
                break;
            case 2:
                _stars[i].size = {0.8,0.8};
                _stars[i].speed = 2;
                break;
            case 3:
                _stars[i].size = {0.6,0.6};
                _stars[i].speed = 1.5;
                break;
            case 4:
                _stars[i].size = {0.4,0.4};
                _stars[i].speed = 1;
                break;
            case 5:
                _stars[i].size = {0.2,0.2};
                _stars[i].speed = 0.5;
                break;
        }
    }
}

void Background::render(sf::RenderWindow &win)
{
    for (int i = 0; i < MAX_STARS; i++) {
        //std::cout << "render" << std::endl;
        _sprite.setPosition(_stars[i].pos);
        _sprite.setOrigin((24 * _stars[i].size.x) / 2, (24 * _stars[i].size.y) / 2);
        _sprite.setScale(_stars[i].size);
        _sprite.setRotation(_stars[i].rotation);
        win.draw(_sprite);
    }

}

void Background::update()
{
    //std::cout << "before : " << _stars[0].pos.x << std::endl;
    for (int i = 0; i < MAX_STARS; i++) {
        if (_stars[i].pos.x <= -40) {
            _stars[i].pos = sf::Vector2f(std::rand() % WINDOW_WIDTH + WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT);
        }
        _stars[i].pos.x -= _stars[i].speed;
        _stars[i].rotation += 1;
    }
    //std::cout << "after : " << _stars[0].pos.x << std::endl;

}

void Background::manageEvent(const sf::Event &event, sf::RenderWindow &win) {
    return;
}
