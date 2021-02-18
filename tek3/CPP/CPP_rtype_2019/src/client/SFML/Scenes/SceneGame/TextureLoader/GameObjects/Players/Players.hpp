//
// Created by hugo on 11/26/19.
//

#ifndef CPP_RTYPE_2019_PLAYERS_HPP
#define CPP_RTYPE_2019_PLAYERS_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../IGameObject.hpp"
#include "../../../../../../Config.hpp"

class Players : public IGameObject
{
public:
    ~Players();
    Players(ObjectType type) : _type(type) {
        switch (type) {
            case PLAYER1:
                _textures.loadFromFile(ASSETS_PATH_STR"Player1.png");
                break;
            case PLAYER2:
                _textures.loadFromFile(ASSETS_PATH_STR"Player2.png");
                break;
            case PLAYER3:
                _textures.loadFromFile(ASSETS_PATH_STR"Player3.png");
                break;
            case PLAYER4:
                _textures.loadFromFile(ASSETS_PATH_STR"Player4.png");
                break;
        }
        _sprites.setTexture(_textures);
        _rect = sf::IntRect({66,0}, {32,17});
    }

    void render(sf::RenderWindow &, sf::Vector2f) override ;
    void update() override ;
private:
    ObjectType _type;
    sf::Texture _textures;
    sf::Sprite _sprites;
    sf::IntRect _rect;
    sf::Vector2f _lastPos;
};

#endif //CPP_RTYPE_2019_PLAYERS_HPP
