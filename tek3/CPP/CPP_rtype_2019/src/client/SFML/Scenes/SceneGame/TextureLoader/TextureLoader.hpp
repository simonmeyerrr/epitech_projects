//
// Created by hugo on 11/26/19.
//

#ifndef CPP_RTYPE_2019_TEXTURELOADER_HPP
#define CPP_RTYPE_2019_TEXTURELOADER_HPP

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObjects/IGameObject.hpp"
#include "GameObjects/Players/Players.hpp"
#include "GameObjects/Rocket/Rocket.hpp"
#include "GameObjects/Monsters/LowMonsters.hpp"
#include "GameObjects/Monsters/FastMonster.hpp"

class TextureLoader
{
public:
    TextureLoader();

    void render(sf::Vector2f, sf::RenderWindow &, ProtocolUDP::EntityType);
    void update();
private:
    std::map<ProtocolUDP::EntityType , IGameObjectPtr> _textures;
};

#endif //CPP_RTYPE_2019_TEXTURELOADER_HPP
