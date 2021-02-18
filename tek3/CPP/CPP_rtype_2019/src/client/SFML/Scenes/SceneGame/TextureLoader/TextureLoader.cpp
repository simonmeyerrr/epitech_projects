//
// Created by hugo on 11/26/19.
//

#include <iostream>
#include "TextureLoader.hpp"

TextureLoader::TextureLoader()
    : _textures()
{

    _textures.insert(std::make_pair(ProtocolUDP::PLAYER1, new Players(IGameObject::PLAYER1)));
    _textures.insert(std::make_pair(ProtocolUDP::PLAYER2, new Players(IGameObject::PLAYER2)));
    _textures.insert(std::make_pair(ProtocolUDP::PLAYER3, new Players(IGameObject::PLAYER3)));
    _textures.insert(std::make_pair(ProtocolUDP::PLAYER4, new Players(IGameObject::PLAYER4)));
    _textures.insert(std::make_pair(ProtocolUDP::ROCKET, new Rocket()));
    _textures.insert(std::make_pair(ProtocolUDP::MONSTER, new LowMonsters()));
    _textures.insert(std::make_pair(ProtocolUDP::MONSTER2, new FastMonsters()));
}

void TextureLoader::render(sf::Vector2f pos, sf::RenderWindow &win, ProtocolUDP::EntityType type)
{
    try {
        _textures.at(type)->render(win, pos);
    } catch (...) {
        //std::cout << "error" << std::endl;
    }

}

void TextureLoader::update()
{
    for (auto &object: _textures)
        object.second->update();
}
