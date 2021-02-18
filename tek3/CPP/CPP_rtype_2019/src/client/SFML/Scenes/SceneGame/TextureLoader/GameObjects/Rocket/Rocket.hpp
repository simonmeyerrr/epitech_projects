//
// Created by hugo on 11/27/19.
//

#ifndef CPP_RTYPE_2019_ROCKET_HPP
#define CPP_RTYPE_2019_ROCKET_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../IGameObject.hpp"
#include "../../../../../../Config.hpp"

class Rocket : public IGameObject
{
public:
    ~Rocket();
    Rocket() {
        _textures.loadFromFile(ASSETS_PATH_STR"Rocket.png");
        _sprites.setTexture(_textures);
    }

    void render(sf::RenderWindow &, sf::Vector2f) override ;
    void update() override ;
private:
    sf::Texture _textures;
    sf::Sprite _sprites;
};

#endif //CPP_RTYPE_2019_ROCKET_HPP
